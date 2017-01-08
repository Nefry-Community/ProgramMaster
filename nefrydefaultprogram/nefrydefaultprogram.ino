#include <Nefry.h>
void setup() {
  Nefry.setProgramName("DefaultProgram");
  int i=Nefry.autoUpdate("/nefrydefaultprogram");
  if(i==true){
    Nefry.println("プログラムの更新はありません。");
  }else{
    Nefry.print("更新に問題が発生しました。");
    Nefry.println("ネットに問題ないかチェック！");
    Nefry.print("ErrCode : ");
    Nefry.println(i);
    Nefry.setLed(255,0,0);
    //ErrCode
  }
}
void loop() {
Nefry.setLed(random(255),random(255),random(255));
Nefry.ndelay(500);
}
