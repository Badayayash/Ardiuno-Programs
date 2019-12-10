#include <HardwareSerial.h>
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int pin6 = 7;
int pin7 = 8;
int button = 9;
long randNumber;
int state = 0;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));  
}

void loop() {
  if(digitalRead(button) == HIGH && state ==0){
    randNumber = random(1,7);
    delay(100);
    Serial.print(randNumber);

    if( randNumber==6){
      six();
    }
    if( randNumber==5){
      five();
    }
    if( randNumber==4){
      four();
    }
    if( randNumber==3){
      three();
    }
    if( randNumber==2){
      two();
    }
    if( randNumber==1){
      one();
    }
    delay(5000);
    clearAll();
    state =0;
  }
}

void six(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,HIGH);
}
  
void five(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin7,HIGH);
  digitalWrite(pin4,HIGH);
}
void four(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin7,HIGH);
}
void three(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin4,HIGH);
  digitalWrite(pin7,HIGH);
}
void two(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin7,HIGH);
}
void one(){
  digitalWrite(pin4,HIGH);
}
void clearAll(){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,LOW);
  digitalWrite(pin4,LOW);
}
