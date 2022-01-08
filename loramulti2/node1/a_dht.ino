void startDHT()
{
  if (isnan(humidity) || isnan(temperature)) 
  {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }
}

void getReadings(){ //readsensor
  long rand1=random(10, 100);
  long rand2=random(101, 200);
  humidity = rand1; //dht.readHumidity();
  temperature = rand2; //dht.readTemperature();
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C "));
}
 
