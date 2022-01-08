/*
 Lora Node1
https://www.electroniclinic.com/
 
*/
#include <SPI.h>              // include libraries
#include <LoRa.h>
 
int POT = A2; 
 
String outgoing;              // outgoing message
 
byte msgCount = 0;            // count of outgoing messages
byte MasterNode = 0xFF;     
byte Node1 = 0xBB;
 
 
void setup() {
  Serial.begin(9600);                   // initialize serial
  pinMode(POT, INPUT);
  while (!Serial);
 
  Serial.println("LoRa Duplex");
 
 
 
  if (!LoRa.begin(433E6)) {             // initialize ratio at 915 MHz
    Serial.println("LoRa init failed. Check your connections.");
    while (true);                       // if failed, do nothing
  }
 
  Serial.println("LoRa init succeeded.");
}
 
void loop() {
 
 
  // parse for a packet, and call onReceive with the result:
  onReceive(LoRa.parsePacket());
}
 
void sendMessage(String outgoing, byte MasterNode, byte otherNode) {
  LoRa.beginPacket();                   // start packet
  LoRa.write(MasterNode);              // add destination address
  LoRa.write(Node1);             // add sender address
  LoRa.write(msgCount);                 // add message ID
  LoRa.write(outgoing.length());        // add payload length
  LoRa.print(outgoing);                 // add payload
  LoRa.endPacket();                     // finish packet and send it
  msgCount++;                           // increment message ID
}
 
void onReceive(int packetSize) {
  if (packetSize == 0) return;          // if there's no packet, return
 
  // read packet header bytes:
  int recipient = LoRa.read();          // recipient address
  byte sender = LoRa.read();            // sender address
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length
 
  String incoming = "";
 
  while (LoRa.available()) {
    incoming += (char)LoRa.read();
  }
 
  if (incomingLength != incoming.length()) {   // check length for error
   // Serial.println("error: message length does not match length");
   ;
    return;                             // skip rest of function
  }
 
  // if the recipient isn't this device or broadcast,
  if (recipient != Node1 && recipient != MasterNode) {
    //Serial.println("This message is not for me.");
    ;
    return;                             // skip rest of function
  }
    Serial.println(incoming);
    int Val = incoming.toInt();
    if(Val == 34)
    { 
    String message = String(analogRead(POT)); 
    sendMessage(message,MasterNode,Node1);
    delay(100);
    }
  
}
