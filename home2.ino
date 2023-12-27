#define LED 7
#define ldr A0
#define Trig 6
#define Echo 5
#define FAN 3  
#include <DHT11.h>
#include <Servo.h>
Servo servo ; 
DHT11 dht(4);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(13);
  pinMode(LED , OUTPUT); 
  pinMode(Trig ,OUTPUT); 
 pinMode(Echo,INPUT);
 pinMode(FAN , OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(ldr);
  digitalWrite(Trig , LOW);
  delayMicroseconds(2) ; 
  digitalWrite(Trig , HIGH);
  delayMicroseconds(10) ; 
  digitalWrite(Trig ,LOW); 
  float distance = pulseIn(Echo ,HIGH);
  distance = distance/58 ; 
  Serial.println(val); 

  if (val <= 350 ){
   digitalWrite(LED , HIGH);
  }
  else
  {
   digitalWrite(LED , LOW);  
  }
  if(distance <= 20 ){
   for(int pos = 0 ; pos<= 180 ; pos++ ){
    servo.write(pos); 
    delay(10); 
   }
   delay(3000); 
   for(int pos = 180 ; pos >= 0 ; pos-- ){
    servo.write(pos); 
    delay(10); 
   }
  }
  float temprature = dht.readTemperature();
   Serial.println(temprature); 
   if(temprature > 22 ){
    digitalWrite(FAN , 1 ); 
   }else{
     digitalWrite(FAN , 0) ; 
   }



  delay(100); 

}
