#include <Servo.h>
Servo servo1;
const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance;
int Obj_distance=20; 
int servo_angel=180;  
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
servo1.attach(8);}
void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(7);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
if (distance <Obj_distance)
{servo1.write(servo_angel);
delay(3000);}
else
servo1.write(0);
delay(10);
}
