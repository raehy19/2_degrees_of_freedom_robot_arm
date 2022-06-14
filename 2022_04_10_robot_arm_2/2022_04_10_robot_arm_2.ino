#include <Servo.h>
#define _USE_MATH_DEFINES
#include <math.h>

Servo shoulder;
Servo elbow;
Servo rotate;
Servo hand;
Servo wrist;

int rotatePin = 4;
int shoulderPin = 5;
int elbowPin = 6;

int wristPin = 7;
int handPin = 8;


double rotateAngle = 90;
double shoulderAngle = 90;
double elbowAngle = 90;
double wristAngle = 180;

int handOpen = 170;
int handClose = 80;
int isOpen = 1;

double armLength = 12;
double foreArmLength = 12;

double horizontal = 12;
double vertical = 12;
double distance = 0;

void setup() {
  Serial.begin(9600);
  shoulder.attach(shoulderPin);
  elbow.attach(elbowPin);
  rotate.attach(rotatePin);
  hand.attach(handPin);
  wrist.attach(wristPin);
  
  shoulder.write(shoulderAngle);
  elbow.write(elbowAngle);
  rotate.write(rotateAngle);
  hand.write(handOpen);
  wrist.write(wristAngle);
}

void loop() {
  if(Serial.available()){
    rotateAngle = Serial.parseInt();
    horizontal = Serial.parseInt();
    vertical = Serial.parseInt();
    isOpen = Serial.parseInt();
  }

  distance = sqrt( pow(horizontal,2) + pow(vertical,2) );
  
  elbowAngle = 180 / M_PI * acos((pow(armLength, 2) + pow(foreArmLength, 2) - pow(distance, 2)) / (2 * armLength * foreArmLength));
  
  shoulderAngle = 180 / M_PI * ( acos(horizontal / distance) - acos( (pow(armLength, 2) + pow(distance, 2) - pow(foreArmLength, 2)) / (2 * armLength * distance)) );

  wristAngle = 180 / M_PI * ( ( acos(vertical / distance) - acos( (pow(foreArmLength, 2) + pow(distance, 2) - pow(armLength, 2)) / (2 * foreArmLength * distance)) ) + M_PI/2);

  if (isOpen == 1) {
    hand.write(handOpen);
  }
  if (isOpen == 0) {
    hand.write(handClose);
  }
  
  shoulder.write(shoulderAngle); 
  elbow.write(elbowAngle);
  rotate.write(rotateAngle);
  wrist.write(wristAngle);
  
  
  Serial.print("Rotate각도 : ");
  Serial.print(rotateAngle);
  Serial.print("  Shoulder각도 : ");
  Serial.print(shoulderAngle);
  Serial.print("  Elbow각도 : ");
  Serial.print(elbowAngle);
  Serial.print("  Wristw각도 : ");
  Serial.print(wristAngle);
  Serial.print("  hand on ? : ");
  Serial.println(isOpen);
}
