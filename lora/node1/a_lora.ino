//Initialize LoRa module
void startLoRA()
{
  LoRa.setPins(ss, rst, dio0); //setup LoRa transceiver module
 
  while (!LoRa.begin(BAND) && counter < 10) {
    Serial.print(".");
    counter++;
    delay(500);
  }
  LoRa.setTxPower(20); //max 20
  LoRa.setSignalBandwidth(62.5E3);
  /*signalBandwidth - signal bandwidth in Hz, defaults to 125E3.
  Supported values are 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3, 41.7E3, 62.5E3, 125E3, 250E3, and 500E3.*/
  if (counter == 10) 
  {
    // Increment readingID on every new reading
    readingID++;
    Serial.println("Starting LoRa failed!"); 
  }
  Serial.println("LoRa Initialization OK!");
  delay(2000);
}
