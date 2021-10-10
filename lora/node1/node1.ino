//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>
 
//Libraries for LoRa
#include "DHT.h"
#define DHTPIN 4          //pin where the dht11 is connected
DHT dht(DHTPIN, DHT11);
 
//define the pins used by the LoRa transceiver module
#define ss 10
#define rst 9
#define dio0 2
 
#define BAND 433E6    //433E6 for Asia, 866E6 for Europe, 915E6 for North America
 
//packet counter
int readingID = 0;
 
int counter = 0;
String LoRaMessage = "";
 
float temperature = 0;
float humidity = 0;
  
void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  dht.begin();
  startDHT();
  startLoRA();
}
void loop() {
  getReadings();
  sendReadings();
  delay(500);
}
