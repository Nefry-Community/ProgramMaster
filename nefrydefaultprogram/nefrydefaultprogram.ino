/*
 * デフォルトプログラム　2017/01/27
 * 
 * Nefry購入時ブログラム
 * 
 * IFTTTとMilkcocoaを扱える　RGBLEDの点滅実行
 */

#include <Nefry.h>
#include <Nefry_Milkcocoa.h>

Nefry_Milkcocoa *milkcocoa;

char *datastore;
int milkcocoaSendFlg = 0, count = 0;
String Event, SecretKey;

void onpush(DataElement *elem);
bool IFTTT_send(String, String, String data = "");
void pushSWReader();

void setup() {
  Nefry.setProgramName("DefaultProgram");
  int i = Nefry.autoUpdate("/nefrydefaultprogram");
  if (i == true) {
    Nefry.println("プログラムの更新はありません。");
  } else {
    Nefry.print("更新に問題が発生しました。");
    Nefry.println("ネットに問題ないかチェック！");
    Nefry.print("ErrCode : ");
    Nefry.println(i);
    Nefry.setLed(255, 0, 0);
    //ErrCode
  }
  milkcocoa->print();//Setup ModuleにAPPIDの表示をする
  milkcocoa = Nefry_Milkcocoa::begin();
  datastore = Nefry.getConfStr(3);
  Nefry.println( milkcocoa->on( datastore, "push", onpush) ? "Milkcocoa onPush OK" : "Milkcocoa onPush NG" );
  Nefry.setConfHtmlValue("MilkcocoaSendFg", 0);
  milkcocoaSendFlg = Nefry.getConfValue(0);
  Nefry.setConfHtmlStr("SecretKey", 4);
  Nefry.setConfHtmlStr("Event", 5);
  SecretKey = Nefry.getConfStr(4);
  Event = Nefry.getConfStr(5);
  if (WiFi.localIP().toString().equals("0.0.0.0")) {
    Nefry.println("Not Found Internet");
  }
}

void loop() {
  Nefry.setLed(random(255), random(255), random(255));
  Nefry.ndelay(100);
  if (Nefry.readSW() == true) {
    pushSWReader();
  }
}

void pushSWReader() {
  if (!WiFi.localIP().toString().equals("0.0.0.0")) {
    if (!IFTTT_send(Event, SecretKey)) {
      Nefry.setLed(255, 0, 0);//Errの時、赤色点灯
      Nefry.ndelay(500);
    }
    if (milkcocoaSendFlg != 0) {
      Nefry.println( milkcocoa->loop(10000) ? "Milkcocoa Connect OK" : "Milkcocoa Connect NG" );
      DataElement elem = DataElement();
      elem.setValue("sw", count++ );
      milkcocoa->push(datastore, &elem);//milkcocoaSendFlgが0以外の時送信される
    }
  }
}


void onpush(DataElement *elem) {//MilkcocoaからRGBを取得して表示します。
  Nefry.print("milkcocoa ");
  Nefry.print("set led:");
  Nefry.println(elem->getInt("r") + ":");
  Nefry.println(elem->getInt("g") + ":");
  Nefry.println(elem->getInt("b"));
  Nefry.setLed(elem->getInt("r"), elem->getInt("g"), elem->getInt("b"));//LEDを点灯
}

//IFTTTへデータを送信します。
bool IFTTT_send(String event, String Secretkey, String data) {
  WiFiClient client;
  if (client.connect("maker.ifttt.com", 80)) {
    client.println("POST /trigger/" + event + "/with/key/" + Secretkey + " HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("User-Agent: ESP8266/1.0");
    client.println("Connection: close");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.println(data);
    delay(10);
    Nefry.println("IFTTT connection OK");;
    return true;
  } else {
    Nefry.println("IFTTT connection Err");
    return false;
  }
}
