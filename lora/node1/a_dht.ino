void startDHT()
{
  if (isnan(humidity) || isnan(temperature)) 
  {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }
}

void getReadings(){
  long rand1=random(10, 20);
  long rand2=random(20, 30);
  humidity = rand1; //dht.readHumidity();
  temperature = rand2; //dht.readTemperature();
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C "));
}
 
void sendReadings() {
  LoRaMessage = String(readingID) + "/" + String(temperature) + "&" + String(humidity) ;
  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print(LoRaMessage);
  LoRa.endPacket();
  
  Serial.print("Sending packet: ");
  Serial.println(readingID);
  readingID++;
  Serial.println(LoRaMessage);
}
