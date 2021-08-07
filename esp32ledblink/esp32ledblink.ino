/*
 * ESP32 LED Blink Example
 * Board ESP23 DEVKIT V1
 * ON Board LED GPIO 2
*/

 
int led=13; // Wemos lolin32 on board led pin 22

void setup() {
  // Set pin mode
  pinMode(led,OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
}
