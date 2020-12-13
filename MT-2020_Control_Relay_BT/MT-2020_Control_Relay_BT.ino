/*
MT-2020 Control BT
Ashik Adnan
Date: 30-10-2019
*/

#include <SoftwareSerial.h>


//Right Motor Pins
#define RM1_F 30
#define RM1_B 32

//Left Motor Pins
#define LM1_F 26 
#define LM1_B 28

//Base Acc Pins
#define BASE_F 35
#define BASE_B 31

//Arm Acc Pins
#define ACC1_F 2
#define ACC1_B 3

#define ACC2_F 4
#define ACC2_B 5

#define ACC3_F 6
#define ACC3_B 7

#define CLAW_F 8
#define CLAW_B 9

#define WRIST_F 10
#define WRIST_B 11

//Extender
#define EXT_F 12
#define EXT_B 13

//FPV 
#define FPV1 52
#define FPV2 50


void setup() {
  
  pinMode(RM1_F,OUTPUT);
  pinMode(RM1_B,OUTPUT);
  
  pinMode(LM1_F,OUTPUT);
  pinMode(LM1_B,OUTPUT);
  
  pinMode(ACC1_F,OUTPUT);
  pinMode(ACC1_B,OUTPUT);

  pinMode(ACC2_F,OUTPUT);
  pinMode(ACC2_B,OUTPUT);
  
  pinMode(ACC3_F,OUTPUT);
  pinMode(ACC3_B,OUTPUT);

  pinMode(CLAW_F,OUTPUT);
  pinMode(CLAW_B,OUTPUT);
  
  pinMode(WRIST_F,OUTPUT);
  pinMode(WRIST_B,OUTPUT);
  
  pinMode(BASE_F,OUTPUT);
  pinMode(BASE_B,OUTPUT);

  pinMode(EXT_F,OUTPUT);
  pinMode(EXT_B,OUTPUT);
  
  pinMode(FPV1,OUTPUT);
  pinMode(FPV2,OUTPUT);

  digitalWrite(RM1_F,LOW);
  digitalWrite(RM1_B,LOW);

  digitalWrite(LM1_F,LOW);
  digitalWrite(LM1_B,LOW);

  digitalWrite(ACC1_F,HIGH);
  digitalWrite(ACC1_B,HIGH);

  digitalWrite(ACC2_F,HIGH);
  digitalWrite(ACC2_B,HIGH);

  digitalWrite(ACC3_F,HIGH);
  digitalWrite(ACC3_B,HIGH);
  
  digitalWrite(BASE_F,HIGH);
  digitalWrite(BASE_B,HIGH);
  
  digitalWrite(CLAW_F,HIGH);
  digitalWrite(CLAW_B,HIGH);
    
  digitalWrite(WRIST_F,HIGH);
  digitalWrite(WRIST_B,HIGH);

  digitalWrite(EXT_F,HIGH);
  digitalWrite(EXT_B,HIGH);

  digitalWrite(FPV1,HIGH);
  digitalWrite(FPV2,HIGH);

  Serial.begin(9600);

}

void loop() {
  while(Serial.available())
  {
    char state = Serial.read();
    Serial.print(state);
    switch(state)
    {

//Speed 
//      if (PWM >= 255){
//        PWM = 255;
//        }
//      if(PWM <= 0){
//        PWM = 0;
//        }
//        
//      case '+':
//      PWM = PWM+51;
//      break;
//      case '-':
//      PWM = PWM-51;
//      break;
      


//Wheel Drive      
      case 'F':
      goForward();
      break;
      case 'B':
      goBackward();
      break;
      case 'L':
      goLeft();
      break;
      case 'R':
      goRight();
      break;      
      case 'S':
      wheelStop();
      break;

//Arm

      case 'U':
      acc1Open();
      break;
      case 'u':
      acc1Close();
      break;

      case 'V':
      acc2Open();
      break;
      case 'v':
      acc2Close();
      break;

      case 'W':
      acc3Open();
      break;
      case 'w':
      acc3Close();
      break;

      case 'X':
      clawOpen();
      break;
      case 'x':
      clawClose();
      break;

//      case '>':
//      wristClockwise();
//      break;
//      case '<':
//      wristAnticlockwise();
//      break;
//
//      case 'M':
//      baseClockwise();
//      break;
//      case 'N':
//      baseAnticlockwise();
//      break;
//
//      case 'V':
//      armStop();
//      break;

//FPV
      case '8':
      fpvAnt();
      break;
      case '2':
      fpvReverse();
      break;
      case '4':
      fpvBox();
      break;
      case '6':
      fpvWrist();
      break;

//Extender
      case 'E':
      extenderOpen();
      break;
      case 'e':
      extenderClose();
      break;
      case 'C':
      extenderStop();
      break;

    }
  }
}

//wheel method....

void goForward()
{
  digitalWrite(RM1_F,HIGH);
  digitalWrite(RM1_B,LOW);

  digitalWrite(LM1_F,HIGH);
  digitalWrite(LM1_B,LOW);
  
  Serial.println("Forward");  
}

void goBackward()
{
  digitalWrite(RM1_F,LOW);
  digitalWrite(RM1_B,HIGH);

  digitalWrite(LM1_F,LOW);
  digitalWrite(LM1_B,HIGH);
  
  Serial.println("Backward");  
}

void goLeft()
{
  digitalWrite(RM1_F,HIGH);
  digitalWrite(RM1_B,LOW);

  digitalWrite(LM1_F,LOW);
  digitalWrite(LM1_B,HIGH);
  
  Serial.println("Left");  
}

void goRight()
{
  digitalWrite(RM1_F,LOW);
  digitalWrite(RM1_B,HIGH);

  digitalWrite(LM1_F,HIGH);
  digitalWrite(LM1_B,LOW);
  
  Serial.println("Right");  
}

void wheelStop()
{
  digitalWrite(RM1_F,LOW);
  digitalWrite(LM1_F,LOW);
  digitalWrite(RM1_B,LOW);
  digitalWrite(LM1_B,LOW);

  Serial.println("Wheel Stop");
}

//arm_Base method....

void baseClockwise()
{
  digitalWrite(BASE_F,LOW);
  digitalWrite(BASE_B,HIGH);

  Serial.println("Base Clockwise");  
}

void baseAnticlockwise()
{
  digitalWrite(BASE_F,HIGH);
  digitalWrite(BASE_B,LOW);

  Serial.println("Base Anticlockwise");  
}

//actuator1 method....

void acc1Open()
{
  digitalWrite(ACC1_F,LOW);
  digitalWrite(ACC1_B,HIGH);

  Serial.println("Actuator1 Open");  
}

void acc1Close()
{
  digitalWrite(ACC1_F,HIGH);
  digitalWrite(ACC1_B,LOW);

  Serial.println("Actuator1 Close");  
}

//actuator2 method....

void acc2Open()
{
  digitalWrite(ACC2_F,LOW);
  digitalWrite(ACC2_B,HIGH);

  Serial.println("Actuator2 Open");  
}

void acc2Close()
{
  digitalWrite(ACC2_F,HIGH);
  digitalWrite(ACC2_B,LOW);

  Serial.println("Actuator2 Close");  
}

//actuator3 method....

void acc3Open()
{
  digitalWrite(ACC3_F,LOW);
  digitalWrite(ACC3_B,HIGH);

  Serial.println("Actuator3 Open");  
}

void acc3Close()
{
  digitalWrite(ACC3_F,HIGH);
  digitalWrite(ACC3_B,LOW);

  Serial.println("Actuator3 Close");  
}

//claw method....

void clawOpen()
{
  digitalWrite(CLAW_F,LOW);
  digitalWrite(CLAW_B,HIGH);

  Serial.println("Claw Open");
}

void clawClose()
{
  digitalWrite(CLAW_F,HIGH);
  digitalWrite(CLAW_B,LOW);

  Serial.println("Claw Close");
}

//wrist method....

void wristClockwise()
{
  digitalWrite(WRIST_F,LOW);
  digitalWrite(WRIST_B,HIGH);

  Serial.println("Wrist CW");  
}

void wristAnticlockwise()
{
  digitalWrite(WRIST_F,HIGH);
  digitalWrite(WRIST_B,LOW);

  Serial.println("Wrist CCW");  
}

void armStop()
{
  
  digitalWrite(ACC1_F,HIGH);
  digitalWrite(ACC1_B,HIGH);
  
  digitalWrite(ACC2_F,HIGH);
  digitalWrite(ACC2_B,HIGH);
  
  digitalWrite(ACC3_F,HIGH);
  digitalWrite(ACC3_B,HIGH);
  
  digitalWrite(CLAW_F,HIGH);
  digitalWrite(CLAW_B,HIGH);
  
  digitalWrite(WRIST_F,HIGH);
  digitalWrite(WRIST_B,HIGH);
  
  digitalWrite(BASE_F,HIGH);
  digitalWrite(BASE_B,HIGH);

  Serial.println("Arm Stop");   
}


//Extender Methods

void extenderOpen()
{
  digitalWrite(EXT_F,LOW);
  digitalWrite(EXT_B,HIGH);

  Serial.println("Extender Open");  
}
void extenderClose()
{
  digitalWrite(EXT_F,HIGH);
  digitalWrite(EXT_B,LOW);

  Serial.println("Extender Close");  
}

void extenderStop()
{
  digitalWrite(EXT_F,HIGH);
  digitalWrite(EXT_B,HIGH);

  Serial.println("Extender Stop");  
}



//FPV Methods

void fpvAnt()
{
  digitalWrite(FPV1,LOW);

  Serial.println("FPV Antena");  
}

void fpvReverse()
{
  digitalWrite(FPV1,HIGH);

  Serial.println("FPV Reverse");  
}

void fpvBox()
{
  digitalWrite(FPV2,LOW);

  Serial.println("FPV Box");  
}

void fpvWrist()
{
  digitalWrite(FPV2,HIGH);

  Serial.println("FPV Wrist");  
}
