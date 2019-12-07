/*************************************************************
 Download latest Blynk library here:
   https://github.com/blynkkk/blynk-library/releases/latest
 Blynk is a platform with iOS and Android apps to control
 Arduino, Raspberry Pi and the likes over the Internet.
 You can easily build graphic interfaces for all your
 projects by simply dragging and dropping widgets.
   Downloads, docs, tutorials: http://www.blynk.cc
   Sketch generator:           http://examples.blynk.cc
   Blynk community:            http://community.blynk.cc
   Follow us:                  http://www.fb.com/blynkapp
                               http://twitter.com/blynk_app
 Blynk library is licensed under MIT license
 This example code is in public domain.
*************************************************************
 This example shows how to use ESP8266 Shield (with AT commands)
 to connect your project to Blynk.
 WARNING!
   It's very tricky to get it working. Please read this article:
   http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware
 Change WiFi ssid, pass, and Blynk auth token to run :)
 Feel free to apply it to any other example. It's simple!
*************************************************************/
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YQzkgAw1LqdjWyZRkYgv6v-aLCogrLmT";
int trigPin = 7;
int echoPin = 6;
int outpin = 12;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Best of Fuck";
char pass[] = "qwerty1234";
// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1
// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX
// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200
ESP8266 wifi(&Serial);

void setup()
{
 // Debug console
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 delay(10);
 // Set ESP8266 baud rate
 Serial.begin(ESP8266_BAUD);
 delay(10);
 Blynk.begin(auth, wifi, ssid, pass);
}
void loop()
{
 long duration, distance;
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(1000);
 digitalWrite(trigPin, LOW);
 duration=pulseIn(echoPin, HIGH);
 distance =(duration/2)/29.1;
 digitalWrite(outpin, distance);
 Blynk.run();
 Blynk.virtualWrite(V5, distance);
} 
