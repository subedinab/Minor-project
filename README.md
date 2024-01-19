## Crash Detection And alert system

This project aims to develop a crash detection system using a SIM600L GPS module and an accelerometer. The system will be able to detect vehicular crashes and send an alert to a designated contact.

# Crash detection system

This project aims to develop a crash detection system using a SIM600L GPS module and an accelerometer. The system will be able to detect vehicular crashes and send an alert to a designated contact.

## System components

* SIM600L GPS module
* Accelerometer
* Microcontroller
* Cellular modem
* Antenna

## System operation

The SIM600L GPS module will be used to determine the vehicle's location. The accelerometer will be used to detect sudden changes in acceleration. The microcontroller will be used to process data from the GPS module and accelerometer. The cellular modem will be used to send alerts to designated contacts.

The microcontroller will continuously monitor the accelerometer for sudden changes in acceleration. If the microcontroller detects a change in acceleration that is consistent with a crash, it will record the vehicle's location and time of the crash. The microcontroller will then send an alert to a designated contact. The alert will include the vehicle's location, time of the crash, and a link to a map showing the crash location.




## Some Images 

<figure>
  <img src="https://github.com/chhetri123/Minor-Project/assets/65161301/9e2f41a6-9d0c-4a2d-911f-14baab9acaae" style="width: 48%;" />
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="https://github.com/chhetri123/Minor-Project/assets/65161301/d03cf517-0904-4acb-acda-1cc3ff223952" alt="Image 2" style="width:48%;"/>
</figure>
<hr>
&nbsp;&nbsp;&nbsp;&nbsp;
<figure style="margin: auto;">
  <img src="https://github.com/chhetri123/Minor-Project/assets/65161301/96ee21c5-884c-465a-8421-2ac71c168ffe" style="width: 50%;" />
</figure>




## Feature

:heavy_check_mark: Accident Detection
:heavy_check_mark: Accident Prevention
:heavy_check_mark: Emergency Solution

## How Does It Works

* Accident Prevention
    ```
    To Prevent accident we used four sensor
    * Ultrasonic:  When the sensor detects an object nearly 30 cm it will stop the car.

    ```
* Accident Detection
    ```
    To Detect an accident we used only one sensor
    * Vibrator sensor: If the car crash, it will produce a signal. Based on the signal we do an emergency solution.
    ```
* Emergency Solution
    ```
    In Emergency solution we used some modules and a server
    * GPS NEO 6M: Get car current location in Latitude and Longitude.
    * SIM 800L: Do a post request with Latitude and Longitude and then send an SMS into the responsed phone number.
    * Server: The server calculate the sortest path between hospitals and the accident occured location and return hospital details as response.
    ```



## Module & Sensor Used

| S/N | Name/Model | Quantity | Type | Price | Image | Description
| :-- | :-- | :-- | :-- | :-- | :-- | :-- |
1 | Arduino UNO | 1 | Microcontroller | 750/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/arduino_uno.jpg) | Arduino Uno is a microcontroller board based on the ATmega328P (datasheet).
2 | 4WD Car Set | 1 | Car Chassis Kit | 550/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/car_casis.jpg) | Four-wheel drive (4WD) is a vehicle system that powers the front and rear wheel axles at the same speed to help gain traction, according to Car and Driver.
3 | L298N | 1 | Motor Driver | 140/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/l298n.jpg) | The L298N Motor Driver is a controller that uses an H-Bridge to easily control the direction and speed of up to 2 DC motors.
4 | SIM800L | 1 | Module | 280-400/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/sim_800_l.jpg) | SIM800L GSM/GPRS module is a miniature GSM modem, which can be integrated into a great number of IoT projects.
5 | GPS NEO 6M | 1 | Module | 600/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/gps_neo_6m.jpg) | The NEO-6M module includes one configurable UART interface for serial communication, but the default UART (TTL) baud rate here is 9,600.
6 | MQ3 | 1 | Sensor | 160/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/mq3.jpg) | Alcohol Sensor Module - MQ3. 4753. This module is made using Alcohol Gas Sensor MQ3. 
7 | Ultrasonic| 1 | Sensor | 100/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/sonar.jpg) | An ultrasonic sensor is an instrument that measures the distance to an object using ultrasonic sound waves.
8 | HC-05 | 1 | Module | 270/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/hc05.jpg) | The HC-05 is a popular module which can add two-way (full-duplex) wireless functionality to your projects.
9 | Antena | 1 | Module | 90/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/sim800l_antena.jpg) | Antenna for SIM800L GSM Module.
10 | 3.7v Battery | 3 | Module | 150/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/li_ion_battery.jpg) | 18650 3.7 Volt lithium-ion rechargeable batteries are cylindrical batteries used in mainly for laptop battery packs, telephones, electronic cigarettes, flashlights and cordless power tools.
11 | 1x Battery Case | 1 | Module | 25/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/battery_holder_1.jpg) | The primary function of a battery holder is to keep cells fixed in place safely and securely while conveying power from the batteries to the device in question.
12 | 2x Battery Case | 1 | Module | 30/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/battery_holder_2.png) | The primary function of a battery holder is to keep cells fixed in place safely and securely while conveying power from the batteries to the device in question.
13 | 2x Battery Charger | 1 | Module | 120/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/li_ion_battery_charger.jpg) | Proper charging of Li-ion batteries enables the best performance and longest operational life to be obtained.
14 | Soldering Iron | 1 | Module | 150/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/soldering_iron.jpg) | Spool of solder. 1.6mm. A soldering iron is a hand tool used in soldering.
15 | Soldering LID | 1 | Module | 20/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/soldering_lid.jpg) | Soldering Lid.
16 | Jumper Wire | 3 | Cable | 180/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/jumper_wire.jpg) | RF jumper cables - Jumper cables is a smaller and more bendable corrugated cable which is used to connect antennas and other components to network cabling.


## Conclusion

The crash detection system has the potential to improve driver safety by providing a quick and easy way to notify emergency services in the event of a crash. The system can also be used to track vehicle movements and provide insights into driver behavior.

## Team members

* Manish Chhetri (PAS076BEI015)
* Nirajan Paudel (PAS076BEI017)
* Nabaraj Subedi (PAS076BEI018)
* Sudharshan Acharya  (PAS076BEI042)


