#include <Nefry.h>
#define PIN D2
void setup() {
  Nefry.setProgramName("Digital OUT");
  Nefry.println("Digital OUT");
  pinMode(PIN,OUTPUT);//出力モード切り替え
}
void loop() {
  //SWを押した時にD2にLEDを差すと点灯する
  if(Nefry.push_SW()){
    //押した時
    digitalWrite(PIN,HIGH);
    Nefry.println("Push SW");
  }else{
    //離した時
    digitalWrite(PIN,LOW);
  }
  Nefry.ndelay(100);
}

