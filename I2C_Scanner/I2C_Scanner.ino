
//1 GND Ground
//2 VCC Power source (5V +/-10%)
//3 SDA I2C(5V) Data line
//4 SCL I2C(5V) Clock line
 
// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

#include <Wire.h>

void setup() {
  Serial.begin (9600);

  // Leonardo: wait for serial port to connect
  while (!Serial) 
    {
    }

  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  
  Wire.begin();
  for (byte i = 8; i < 127; i++)
  {
    Wire.beginTransmission (i);
//Wire.write(byte(0x4c));      // sets register pointer to echo #1 register (0x02)
    Serial.println(i);
    int err = Wire.endTransmission(false);
    Serial.println(err);
    if (err == 0||err == 1)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

void loop(){
  
}

