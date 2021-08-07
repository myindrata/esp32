#include "BluetoothSerial.h" 

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;
int led = 13; 

void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("MyIndrata"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (led, OUTPUT);//Specify that LED pin is output
}

void loop() {
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49) // type 1 from terminal bluetooth
        {
        digitalWrite(led, HIGH);
        ESP_BT.println("LED turned ON");
        }
        
    if (incoming == 48)// send 0 type 1 from terminal bluetooth
        {
        digitalWrite(led, LOW);
        ESP_BT.println("LED turned OFF");
        }     
  }
  delay(20);
}
