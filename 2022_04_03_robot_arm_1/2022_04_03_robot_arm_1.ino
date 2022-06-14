#include <Servo.h>

Servo shoulder;
Servo elbow;
Servo wrist;

int shoulderPin = 5;
int elbowPin = 6;
int wristPin = 7;
int shoulderAngle = 90;
int elbowAngle = 90;
int wristAngle = 90;

void setup() {
  Serial.begin(9600);
  
  shoulder.attach(shoulderPin);
  elbow.attach(elbowPin);
  wrist.attach(wristPin);
  
  shoulder.write(shoulderAngle);
  elbow.write(elbowAngle);
  wrist.write(wristAngle);
}

void loop() {
  if(Serial.available()){
    shoulderAngle = Serial.parseInt();
    elbowAngle = Serial.parseInt();
    wristAngle = Serial.parseInt();
  }
//  if(shoulderAngle >= 0 && shoulderAngle <= 180 
//  && elbowAngle >= 0 && elbowAngle <= 180){
    shoulder.write(shoulderAngle);
    elbow.write(elbowAngle);
    wrist.write(wristAngle);
    Serial.print("Shoulder각도 : ");
    Serial.print(shoulderAngle);
    Serial.print("  Elbow각도 : ");
    Serial.print(elbowAngle);
    Serial.print("  wrist각도 : ");
    Serial.println(wristAngle);
//  }
}
