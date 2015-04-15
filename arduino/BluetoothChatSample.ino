#include <SoftwareSerial.h>

SoftwareSerial serialcomm(10, 11); // RX | TX

int ledpin = 13;

int BluetoothData;


void setup() {
  serialcomm.begin(115200);
  serialcomm.println("Bluetooth is On. Send 1 to Turn On LED 13, Sen 0 to Turn Off");
  
  pinMode(ledpin, OUTPUT);
}

void sendMessage(const char msg[]) {
    serialcomm.print(msg);
}

void loop() {
     if (serialcomm.available()){

         BluetoothData=serialcomm.read();
  

         if (BluetoothData=='1'){
           digitalWrite(ledpin,HIGH);
           sendMessage("LED_ON");

         } else if (BluetoothData=='0') {
             digitalWrite(ledpin,LOW);
           sendMessage("LED_OFF");
         }
      }
}



