void send_request(int node)
{
  LoRaMessage = String(node);
  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print(LoRaMessage);
  LoRa.endPacket();
  
  Serial.print("Sending packet: ");
  Serial.println(LoRaMessage);
}
