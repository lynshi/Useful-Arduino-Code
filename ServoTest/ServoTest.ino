//can test multiple servos at once; assumes that only valid pins are used
#include <Servo.h>

#define STARTPIN 30
#define ENDPIN 31
#define SPINDELAY 25

Servo myServo;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo test code running. Servo should sweep 180 degrees from left to right, then back.");
}

void loop() {
  for (int n = STARTPIN; n <= ENDPIN; n++) {
    moveServo(n);
  }

  Serial.println("Done!");
  
  delay(60000);
}

void moveServo(int pin) {
  for (int i = 0; i <= 180; i++) {
    myServo.attach(pin);
    delay(SPINDELAY);
    myServo.write(i);
    delay(SPINDELAY);
    myServo.detach(); //attach/detach reduced jittering of servos as observed in a previous project
  }

  for (int i = 179; i >= 0; i--) {
    myServo.attach(pin);
    delay(SPINDELAY);
    myServo.write(i);
    delay(SPINDELAY);
    myServo.detach(); //delays and attach/detach eliminated jittering of servos as observed in a previous project
  }

  Serial.print("Servo at pin ");
  Serial.print(pin);
  Serial.println(" is done.");
  return;
}

