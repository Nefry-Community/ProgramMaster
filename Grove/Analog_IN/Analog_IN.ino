#include <Nefry.h>
int sensorValue;
void setup() {
  Nefry.setProgramName("Analog IN");
  Nefry.println("Analog IN");
}
void loop() {
  sensorValue = analogRead(A0);
  Nefry.print("sensor = " );
  Nefry.println(sensorValue);
  Nefry.setLed(sensorValue/4,0,0);
  Nefry.ndelay(1000);
}
