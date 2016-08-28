#include <Wire.h>

//1 GND Ground
//2 VCC Power source (5V +/-10%)
//3 SDA I2C(5V) Data line
//4 SCL I2C(5V) Clock line
 
void setup(){
  Serial.begin(9600);
  Serial.println("Setting up thermal sensor");
  delay(500);
  thermalSensorSetup();
  Serial.println("Getting data");
}

void loop(){
  readThermalSensor();
  Serial.println("DATA:");
  outputThermalData();
  delay(60000);
}
