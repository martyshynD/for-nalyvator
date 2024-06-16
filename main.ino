#include <Arduino.h> 
#include <Servo.h>

int int1 = 8;
int int2 = 9;
int int3 = 12;
int int4 = 13;
int buttonPin = 7;
Servo servo; 
boolean a; 

void setup(){
  Serial.begin(9600);
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  servo.attach(10);
  servo.write(0);
}

void loop(){
  a = digitalRead(buttonPin);
  Serial.println(a);
  if (a == 1){
    digitalWrite(int1, HIGH);
    digitalWrite(int2, LOW);
    servo.write(90);
    delay(300);
    digitalWrite(int3, HIGH);
    digitalWrite(int4, LOW);
    
  } 
  if (a == 0){
    digitalWrite(int3, LOW);
    digitalWrite(int4, LOW);
    delay(500);
    digitalWrite(int1, HIGH);
    digitalWrite(int2, LOW);
    servo.write(0);
    delay(200);
    digitalWrite(int1, LOW);
    digitalWrite(int2, LOW);
  }
}