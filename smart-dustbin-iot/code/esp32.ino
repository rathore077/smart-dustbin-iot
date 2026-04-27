#define BLYNK_TEMPLATE_ID "TMPL3B9btGHNN"
#define BLYNK_TEMPLATE_NAME "smart dustbin"
#define BLYNK_AUTH_TOKEN "YWuML4tqZmRlWWn5-hMPZRCOP4Ym3d5K"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "OnePlus9RT";
char pass[] = "rahulsingh";

// Ultrasonic
#define TRIG 5
#define ECHO 18

// IR
#define IR 34

// Motor control pins
int IN1 = 26;
int IN2 = 27;
int IN3 = 14;
int IN4 = 12;

// Speed pins
int ENA = 25;
int ENB = 33;

int mode = 0;
int speedValue = 200;

BlynkTimer timer;

// PWM setup
void setupPWM() {
  ledcSetup(0, 5000, 8);
  ledcAttachPin(ENA, 0);

  ledcSetup(1, 5000, 8);
  ledcAttachPin(ENB, 1);
}

void setSpeed(int spd) {
  speedValue = spd;
  ledcWrite(0, speedValue);
  ledcWrite(1, speedValue);
}

// MOTOR FUNCTIONS
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  setSpeed(speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  setSpeed(speedValue);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  setSpeed(speedValue);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  setSpeed(speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Ultrasonic
long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;
}

// Blynk Controls
BLYNK_WRITE(V0){ if(mode==0) forward(); }
BLYNK_WRITE(V1){ if(mode==0) backward(); }
BLYNK_WRITE(V2){ if(mode==0) left(); }
BLYNK_WRITE(V3){ if(mode==0) right(); }

BLYNK_WRITE(V6){ mode = param.asInt(); }

BLYNK_WRITE(V7){
  int spd = param.asInt();
  setSpeed(spd);
}

// Send data
void sendData() {
  long d = getDistance();
  Blynk.virtualWrite(V4, d);

  if (d < 10)
    Blynk.virtualWrite(V5, 255);
  else
    Blynk.virtualWrite(V5, 0);
}

// IR Auto mode
void lineFollower() {
  int val = digitalRead(IR);

  if (val == 0) {
    forward();
  } else {
    stopMotors();
  }
}

// Setup
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  setupPWM();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendData);
}

// Loop
void loop() {
  Blynk.run();
  timer.run();

  if (mode == 1) {
    lineFollower();
  }
}
