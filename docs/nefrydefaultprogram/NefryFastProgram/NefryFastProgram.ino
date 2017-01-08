#include <Nefry.h>
#include<NefryWriteMode.h>
void WriteModeSetup() {
  Nefry.println("Write Mode Setup");
  Nefry.reset();
}
void WriteModeloop() {
  Nefry.setLed(0, random(255), 0);
  Nefry.ndelay(500);
}
NefryWriteMode WriteMode(WriteModeSetup, WriteModeloop);
void setup() {
  Nefry.setConfModule("","","");
  Nefry.setConfUser("","");
  for (int i = 0; i < 8; i++) {
    Nefry.setConfValue(0, i);
    Nefry.setConfStr("", i);
    Nefry.deleteWifi(i);//保存されているWiFiリストを削除します。
  }
  Nefry.addWifi("Nefry","");
  Nefry.setProgramName("autoUpdate");
  int i=Nefry.autoUpdate("/nefrydefaultprogram");
  if(i==true){
    Nefry.println("確認しましたが更新はありません。");
  }else{
    Nefry.print("更新に問題が発生しました。ErrCode : ");
    Nefry.println(i);
    Nefry.setLed(255,0,0);
    Nefry.reset();
    //ErrCode
  }
}

void loop() {

}
