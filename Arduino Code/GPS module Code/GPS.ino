// #include <SoftwareSerial.h>

// // Choose two Arduino pins to use for software serial
// int RXPin = 7;
// int TXPin = 6;

// //Default baud of NEO-6M is 9600
// int GPSBaud = 9600;

// // Create a software serial port called "gpsSerial"
// SoftwareSerial gpsSerial(RXPin, TXPin);

// void setup()
// {
//   // Start the Arduino hardware serial port at 9600 baud
//   Serial.begin(9600);

// //   // Start the software serial port at the GPS's default baud
// //   gpsSerial.begin(GPSBaud);
// // }

// // void loop()
// // {
// //   // Displays information when new sentence is available.
// //   while (gpsSerial.available() > 0)
// //     Serial.write(gpsSerial.read());
// // }

// #include <TinyGPS++.h>
// #include <SoftwareSerial.h>
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_Sensor.h>
// #include <Wire.h>
// #include <math.h>

// // For GPS
// int RXPin = 7;
// int TXPin = 6;
// TinyGPSPlus gps;
// String lat, lon,alt;
// char msg[]="Location not available";
// int isGPSAvailable=0;


// SoftwareSerial GPS(RXPin, TXPin);
// void gpsdump();
// void getGPS();



// //  For MPU


// void setup() {
//   // put your setup code here, to run once:
//   Wire.begin();
  
//   Serial.begin(9600);
 
//   // GPS.begin(9600);
//   delay(300);

// }

// void loop() {
//   delay(1000);
//   getGPS();


// }


// void getGPS(){ 
//   // This function runs untill location is found ;
//   while (GPS.available() > 0)
//     if (gps.encode(GPS.read())){
//       gpsdump();
//     }
//   // If 5000 milliseconds pass and there are no characters coming in
//   // over the software serial port, show a "No GPS detected" error
//   if (millis() > 5000 && gps.charsProcessed() < 10)
//   {
//     Serial.println("No GPS detected");
//     delay(500);
//     getGPS();
//   }
// }

// void gpsdump (){
//   // Serial.println("Hello");
//   if (gps.location.isValid())
//   {
//     isGPSAvailable=1;
//     lat = String(gps.location.lat(), 6);
//     lon = String(gps.location.lng(), 6);
//     alt=String(gps.altitude.meters(), 6);
//     Serial.print("Latitude: ");
//     Serial.println(lat);
//     Serial.print("Longitude: ");
//     Serial.println(lon);

// }
// }
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Choose two Arduino pins to use for software serial
int RXPin = 7;
int TXPin = 6;

int GPSBaud = 9600;

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  // Serial.println(gpsSerial.available());
  while (gpsSerial.available() > 0)
  // Serial.println(gpsSerial.read());
    if (gps.encode(gpsSerial.read()))
      displayInfo();

  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    delay(1000);
    
  }
}

void displayInfo()
{
  Serial.println(gps.location.lat());
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}