#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <math.h>

// For GPS
int RXPin = 7;
int TXPin = 6;
TinyGPSPlus gps;
String lat="26.794969", lon="87.292176",alt;

char msg[]="Location not available";
int isGPSAvailable=0;


SoftwareSerial GPS(RXPin, TXPin);
void gpsdump();
void getGPS();

//  For MPU

Adafruit_MPU6050 mpu;
void getMpuData();
float Impact();
const float thresSensitivity=11;
float Ax,Ay,Az,oldAx,oldAy,oldAz,dx,dy,dz;
float magnitude=0.0;
int vibration=0,devibrate=75;
unsigned long time1;
unsigned long impact_time;
unsigned long alert_delay = 30000; //30 seconds
bool isAccident=0;
bool Accident_detected=0;

//  For GSM module
SoftwareSerial GSM(3, 2);
void setUpGSM();
void initModule();

char inchar;
const String EMERGENCY_PHONE ="+9779867059058";
char o[] = "OK";
char r[] = "READY";

//  FOr BlueTooth module
void sendBluetoothStatus();
const int rxPin = 4;
const int txPin = 5;
unsigned long WAITING_TIME=10000;

// Create a software serial port for bluetooth
SoftwareSerial btSerial(rxPin, txPin);
unsigned  long btTime;

// 
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  
  btSerial.begin(9600);
  // GSM.begin(9600);
  Serial.begin(9600);
  getMpuData();
  delay(300);
  // setUpGSM();j 
  Serial.print("Initializing GSM Module\n");
  delay(1000);
  Serial.print("Initialized GSM Module\n");
  // GPS.begin(9600);
  delay(300);
  Serial.print("Initialing GPS Location \n");
  Serial.print("latitude: "+lat+"\n");
  Serial.print("Longitude:"+ lon+"\n");
  // for (unsigned long start = millis(); millis() - start < 1000;){
  // while (GPS.available() > 0)
  //   if (gps.encode(GPS.read())){
  //     gpsdump();    }

  
  // }
  // time1 = micros(); 
}

void loop() {
  if(isAccident==0){
    if (micros() - time1 > 1999) Impact();
  }else{
    isAccident=0;
    Serial.print("\n******************************************\n");
    Serial.println("Accident Occured!!");
    Serial.print("Magnitude: "); 
    Serial.println(magnitude);
    // getGPS();
    Accident_detected=1;
    impact_time = millis();
    Serial.print("\n******************************************\n");

    if(Accident_detected){
  btTime=millis();
  sendBluetoothStatus();

}

}
}
void sendBluetoothStatus(){
  btSerial.println("emergency");
  if (Serial.available() > 0) {
    String data = Serial.readString();
    btSerial.write(data.c_str());
    // echo the data to the serial monitor
  }
  // Check if there's incoming data from the Bluetooth module
  while((millis()-btTime)< WAITING_TIME){
    btSerial.begin(9600);
  if (btSerial.available() > 0) {
    // Read the incoming data
    int data = btSerial.read();
    // Echo the data to the Serial Monitor
  
    Accident_detected = 0;
    impact_time = 0;
    // Serial.println(data);
    if(data=='n'){
      Serial.print("It was False Tiggering \n");
    return;
    }
    if(data=='y'){
       Serial.print("Message Will send to Rescue Center\n");
      sendAlert();
      return;
    }
    
  }

}
 Serial.print("Message Will send to Rescue Center\n");
 sendAlert();
}

void getGPS(){ 
  // This function runs untill location is found ;
  while (GPS.available() > 0)
    if (gps.encode(GPS.read())){
      gpsdump();
    }
  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    delay(500);
    getGPS();
  }
}

void gpsdump (){
  // Serial.println("Hello");
  if (gps.location.isValid())
  {
    isGPSAvailable=1;
    lat = String(gps.location.lat(), 6);
    lon = String(gps.location.lng(), 6);
    alt=String(gps.altitude.meters(), 6);
    Serial.print("Latitude: ");
    Serial.println(lat);
    Serial.print("Longitude: ");
    Serial.println(lon);
    Serial.print("Altitude: ");
    Serial.println(alt);
}

}
//  MPU functionality 
void getMpuData(){
if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		  delay(500);
		getMpuData();
	}
	Serial.println("MPU6050 Found!");
	// set accelerometer range to +-8G
	mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
	// set gyro range to +- 500 deg/s
	mpu.setGyroRange(MPU6050_RANGE_2000_DEG);
	// set filter bandwidth to 21 Hz
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);
  Ax=a.acceleration.x;
  Ay=a.acceleration.y;
  Az=a.acceleration.z;
  Serial.print("\n");
    return;
}

float Impact(){
  time1 = micros();
  sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);
  oldAx=Ax;
  oldAy=Ay;
  oldAz=Az;
  Ax=a.acceleration.x;
  Ay=a.acceleration.y;
  Az=a.acceleration.z;

  vibration--;
  if(vibration < 0) vibration = 0;   

  if(vibration > 0) return;
  dx=Ax-oldAx;
  dy=Ay-oldAy;
  dz=Az-oldAz;                                        
  magnitude = sqrt(sq(dx) + sq(dy) + sq(dx));
// Serial.print(magnitude);

  if (magnitude >= thresSensitivity){
    isAccident=1;
    vibration = devibrate;
  } else{
   
    magnitude=0;
  }
  
}


// GSM Functionality
void setUpGSM(){
  Serial.println("Initializing GSM Module....");
  GSM.println("AT");
  updateGSMSerial();
  GSM.println("ATI");
  updateGSMSerial();
  GSM.println("AT+COPS?");
  updateGSMSerial();
  GSM.println("AT+CBC");
  updateGSMSerial();
  
}

//   Sending SMS to emergency Contacts
void sendAlert()
{
  String sms_data;
  sms_data = "Accident Alert!!\r";
  sms_data += "https://www.google.com/maps?q=";
  sms_data += lat + "," + lon;
  Serial.print(sms_data);
  Serial.print("\n");
   Serial.println("SMS Sent to the Emergency Contact");
  // sendSms(sms_data);
}


 void sendSms(String text)
{
  //return;
  GSM.println("AT"); //Once the handshake test is successful, it will back to OK
  updateGSMSerial();
  GSM.println("AT+CMGF=1"); // Configuring TEXT mode
  updateGSMSerial();
  GSM.println("AT+CMGS=\"+9779866007834\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateGSMSerial();
  GSM.print(text); //text content
  updateGSMSerial();
  GSM.write(26);
  Serial.println("SMS Sent to the Emergency Contact");
}



void updateGSMSerial()
{
  delay(1000);
  while (Serial.available()) 
  {
    GSM.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(GSM.available()) 
  {
    Serial.write(GSM.read());//Forward what Software Serial received to Serial Port
  }
}



