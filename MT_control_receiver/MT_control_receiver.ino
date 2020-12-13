//15-nov-2019
//by mukit

int ch[9];
char ch_Command[9];
int pin[9]={A3,A4,A5,A6,A7,A8,A9,A10,A11};
//int WH_R[2]={32,30};
//int WH_L[2]={28,26};
//int AR_O[6]={12,10,8,6,4,2};
//int AR_C[6]={13,11,9,7,5,3};
int Lmotor;
int Rmotor;
void setup() {
  for(int i=0;i<9;i++){
   pinMode(pin[i],INPUT);
  }
//  for(int i=0;i<2;i++){
//   pinMode(WH_R[i],OUTPUT);
//   pinMode(WH_L[i],OUTPUT);
//  }
//  for(int i=0;i<2;i++){
//   digitalWrite(WH_R[i],LOW);
//   digitalWrite(WH_L[i],LOW);
//  }
//  for(int i=0;i<6;i++){
//   pinMode(AR_O[i],OUTPUT);
//   pinMode(AR_C[i],OUTPUT);
//  }
//  for(int i=0;i<6;i++){
//   digitalWrite(AR_O[i],HIGH);
//   digitalWrite(AR_C[i],HIGH);
//  }
   
  Serial.begin(9600);
}

void loop() {

  for(int i=0;i<9;i++){
   ch[i]=pulseIn(pin[i],HIGH);

  }
  
   
  for(int i=0;i<9;i++){

    if(ch[i]<1300){
      ch_Command[i]= 'F';
      }
    if(ch[i]>1300 && ch[i]< 1600){
      ch_Command[i]='S';
      }
    if(ch[i]>1600){
      ch_Command[i]='B';
      } 
  }

  AllChannelCheck();

  if(ch_Command[2]== 'B' && ch_Command[3]== 'B'){
   //StopArm(); 
   Serial.write('V');
  }else{
    
    if(ch_Command[3]=='F'){
      //BaseOpen();
      Serial.write('M');
     }else if(ch_Command[3]=='B'){
      //BaseClose();
      Serial.write('N');
      }
    if(ch_Command[2]=='F'){
      //Acc1Open();
      Serial.write('R');
     }else if(ch_Command[2]=='B'){
      //Acc1Close();
      Serial.write('F');
      }

    if(ch_Command[6]=='F'){
      //Acc2Open();
      Serial.write('T');
     }else if(ch_Command[6]=='B'){
      //Acc2Close();
      Serial.write('G');
      }

    if(ch_Command[5]=='F'){
      //Acc3Open();
      Serial.write('Y');
     }else if(ch_Command[5]=='B'){
      //Acc3Close();
      Serial.write('H');
      }

    if(ch_Command[8]=='F'){
      //WristOpen();
      Serial.write('>');
     }else if(ch_Command[8]=='B'){
      //WristClose();
      Serial.write('<');
      }             

    if(ch_Command[7]=='F'){
      //ClawOpen();
      Serial.write('O');
     }else if(ch_Command[7]=='B'){
      //ClawClose();
      Serial.write('P');
      }                  
    
   }
   
  if(ch_Command[0]=='F'){
    //FORWARD();
    Serial.write('W');
  }else if(ch_Command[0]=='B'){
    //BACKWARD();
    Serial.write('S');
  }else if(ch_Command[1]=='F'){
    //LEFT();
    Serial.write('A');
  }else if(ch_Command[
  1]=='B'){
    //RIGHT();
    Serial.write('D');
   }else{
    //WheelStop();
    Serial.write('B');
    }

Serial.println();
}

//void FORWARD(){
//
//  digitalWrite(WH_R[0],HIGH);
//  digitalWrite(WH_R[1],LOW);
//  digitalWrite(WH_L[0],HIGH);
//  digitalWrite(WH_L[1],LOW);  
//
//  Serial.print("Forward ");
//  Serial.print("   ");
//  }
//
//void BACKWARD(){
//
//  digitalWrite(WH_R[0],LOW);
//  digitalWrite(WH_R[1],HIGH);
//  digitalWrite(WH_L[0],LOW);
//  digitalWrite(WH_L[1],HIGH);  
//
//  Serial.print("BACKWARD");
//  Serial.print("   "); 
//  }
//
//void LEFT(){
//  digitalWrite(WH_R[0],HIGH);
//  digitalWrite(WH_R[1],LOW);
//  digitalWrite(WH_L[0],LOW);
//  digitalWrite(WH_L[1],HIGH);  
//
//  Serial.print("LEFT    ");
//  Serial.print("   ");
//  }
//
//void RIGHT(){
//  digitalWrite(WH_R[0],LOW);
//  digitalWrite(WH_R[1],HIGH);
//  digitalWrite(WH_L[0],HIGH);
//  digitalWrite(WH_L[1],LOW);  
//
//  Serial.print("RIGHT   ");
//  Serial.print("   ");
//  }
//void WheelStop(){
//  
//  digitalWrite(WH_R[0],LOW);
//  digitalWrite(WH_R[1],LOW);
//  digitalWrite(WH_L[0],LOW);
//  digitalWrite(WH_L[1],LOW);  
//
//  Serial.print("STOP    ");
//  Serial.print("   ");  
//  }

//void BaseOpen(){
//
//  digitalWrite(AR_O[0],LOW);
//  digitalWrite(AR_C[0],HIGH);
//  Serial.print("BaseOpen");
//  Serial.print("   ");
//  }
//  
//void BaseClose(){
//  digitalWrite(AR_O[0],HIGH);
//  digitalWrite(AR_C[0],LOW);
//  Serial.print("BaseClose");
//  Serial.print("   ");
//  } 
//void BaseStop(){
//  digitalWrite(AR_O[0],HIGH);
//  digitalWrite(AR_C[0],HIGH);
//  Serial.print("BaseStop");
//  Serial.print("   ");  
//  }
//
//void Acc1Open(){
//  digitalWrite(AR_O[1],LOW);
//  digitalWrite(AR_C[1],HIGH);
//  Serial.print("Acc1Open");
//  Serial.print("   ");
//  }
//
//void Acc1Close(){
//  digitalWrite(AR_O[1],HIGH);
//  digitalWrite(AR_C[1],LOW);
//  Serial.print("Ac1Close");
//  Serial.print("   ");
//  }
//  void Acc1Stop(){
//  digitalWrite(AR_O[1],HIGH);
//  digitalWrite(AR_C[1],HIGH);
//  Serial.print("Acc1Stop");
//  Serial.print("   ");
//  }
//
//  
//void Acc2Open(){
//  digitalWrite(AR_O[2],LOW);
//  digitalWrite(AR_C[2],HIGH);  
//  Serial.print("Acc2Open");
//  Serial.print("   ");
//  }
//void Acc2Close(){
//  digitalWrite(AR_O[2],HIGH);
//  digitalWrite(AR_C[2],LOW); 
//  Serial.print("Ac2Close");
//  Serial.print("   "); 
//  }
//void Acc2Stop(){
//  digitalWrite(AR_O[2],HIGH);
//  digitalWrite(AR_C[2],HIGH); 
//  Serial.print("Acc2Stop");
//  Serial.print("   "); 
//  }
//
//  
//void Acc3Open(){
//  digitalWrite(AR_O[3],LOW);
//  digitalWrite(AR_C[3],HIGH); 
//  Serial.print("Acc3Open");
//  Serial.print("   "); 
// }
// 
//void Acc3Close(){
//  digitalWrite(AR_O[3],HIGH);
//  digitalWrite(AR_C[3],LOW);
//  Serial.print("Ac3Close");
//  Serial.print("   ");  
// }
//
//void Acc3Stop(){
//  digitalWrite(AR_O[3],HIGH);
//  digitalWrite(AR_C[3],HIGH);
//  Serial.print("Acc3Stop");
//  Serial.print("   ");  
// }
//
//
// 
//void WristOpen(){
//  digitalWrite(AR_O[4],LOW);
//  digitalWrite(AR_C[4],HIGH); 
//  Serial.print("WrstOpen");
//  Serial.print("   "); 
// }
// 
//void WristClose(){
//  digitalWrite(AR_O[4],HIGH);
//  digitalWrite(AR_C[4],LOW); 
//  Serial.print("WstClose");
//  Serial.print("   "); 
// }
//
//void WristStop(){
//  digitalWrite(AR_O[4],HIGH);
//  digitalWrite(AR_C[4],HIGH); 
//  Serial.print("WristStop");
//  Serial.print("   "); 
// }
// 
//void ClawOpen(){
//  digitalWrite(AR_O[5],LOW);
//  digitalWrite(AR_C[5],HIGH);
//  Serial.print("ClawAntiC");
//  Serial.print("   ");  
// }
// 
//void ClawClose(){
//  digitalWrite(AR_O[5],HIGH);
//  digitalWrite(AR_C[5],LOW); 
//  Serial.print("ClwClock");
//  Serial.print("   "); 
// }
//
//void ClawStop(){
//  digitalWrite(AR_O[5],HIGH);
//  digitalWrite(AR_C[5],HIGH); 
//  Serial.print("ClawStop");
//  Serial.print("   "); 
// }
// 
//void StopArm(){
//  for(int i=0;i<6;i++){
//   digitalWrite(AR_O[i],HIGH);
//   digitalWrite(AR_C[i],HIGH);
//  }
//  Serial.print("StopArm ");
//  Serial.print("   ");
//  
// }

void AllChannelCheck(){
  for(int i=0;i<9;i++){
   Serial.print(ch[i]);
   Serial.print("   ");
  }
}
