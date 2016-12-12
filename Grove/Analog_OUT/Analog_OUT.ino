#include <Nefry.h>
#define PIN D4
void setup() {
  Nefry.setProgramName("Analog OUT");
  Nefry.println("Analog OUT");
}
int value ;
void loop() {
  for (value = 0; value <= 255; value += 5 ) {
    analogWrite(PIN, value );
    Nefry.setLed(value,0,0);
    Nefry.ndelay( 30 );
  }
  for (value = 255; value >= 0; value -= 5 ) {
    analogWrite(PIN, value );
    Nefry.setLed(value,0,0);
    Nefry.ndelay( 30 );
  }
}

