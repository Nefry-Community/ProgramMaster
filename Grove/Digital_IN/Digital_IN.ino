#include <Nefry.h>
#define PIN D2
void setup() {
  Nefry.setProgramName("Digital IN");
  Nefry.println("Digital IN");
  pinMode(PIN,INPUT_PULLUP);//入力モード切り替え
}
void loop() {
  //D2がLOWになったときにNefryのLEDが青色に光る
  if(digitalRead(PIN)==LOW){
    //赤色になる（r,g,b）の順で色を指定できる
    Nefry.setLed(0,0,255);
    Nefry.println("D4 LOW");
  }else{
    //緑色になる
    Nefry.setLed(0,255,0);
  } 
  Nefry.ndelay(100);
}

