#include <SoftwareSerial.h>

const int rxPin = 5;
const int txPin = 4;
unsigned long WAITING_TIME=10000;

// Create a software serial port for bluetooth
SoftwareSerial btSerial(rxPin, txPin);
unsigned  long btTime;


void setup() {
  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
 if (Serial.available() > 0) {
    String data = Serial.readString();
    // data+=" \nSensitivity : 80 \n Magnitude :80";
    // Send the data to the Bluetooth module
    btSerial.write(data.c_str());
    // echo the data to the serial monitor
        Serial.println(data);
  }

  // if (Serial.available()>0) {
   if (btSerial.available() > 0) {
    // Read the incoming data
    int data = btSerial.read();
    // Echo the data to the Serial Monitor
    Serial.println(data);
  }
}
