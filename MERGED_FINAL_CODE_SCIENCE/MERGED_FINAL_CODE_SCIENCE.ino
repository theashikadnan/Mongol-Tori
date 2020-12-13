//SPECTROSCOPY TEST
/*
    NITROGEN(N) RED
    Phosphorus(P) BLUE
    Potassium(K) PURPLE
    */
    //NITROGEN(N) RED,sensor01
    #define aS0 2
    #define aS1 3
    #define aS2 4
    #define aS3 5
    #define oneSensorOut 6
    //int led01=2;
    //int br01=50;
    
    //Phosphorus(P) BLUE,sensor 2
    #define bS0 7
    #define bS1 8
    #define bS2 9
    #define bS3 10
    #define twoSensorOut 11
    //int led02=3;
    //int br02=70;
    
    //Potassium(K) PURPLE,sensor 3
    #define cS0 17
    #define cS1 28
    #define cS2 38
    #define cS3 30
    #define threeSensorOut 40
    //int led03=4;
    //int br03=70;
    
    //sensor04,amino (A) blue
    #define dS0 22
    #define dS1 42
    #define dS2 24
    #define dS3 44
    #define fourSensorOut 26
    //int led04=5;
    //int br04=70;
    
    int frequency = 0;
     float R;
     float G;
     float B;
  signed int P ;
  
  //WATER CAPILLARY TEST
    int resval = 0;  // holds the value
    int respin = A0; // sensor pin used

  //load cell
  #include "HX711.h"

  #define DOUT  33
  #define CLK  32
  HX711 scale; //HX711 scale(7, 6);
  
  float calibration_factor = -761;
  float units;
  float ounces;

  //PUMP MOTOR
  #define enB 23
  #define in3 27
  #define in4 25

  //SERVO
  #include <Servo.h>
  Servo myservo;  // create servo object to control a servo
  
  
//  byte byteRead;
    char byteRead = Serial.read();

void setup() {
  // put your setup code here, to run once:
   //SPECTROSCOPY TEST
      pinMode(aS0, OUTPUT);
      pinMode(aS1, OUTPUT);
      pinMode(aS2, OUTPUT);
      pinMode(aS3, OUTPUT);
      pinMode(oneSensorOut, INPUT);
      //pinMode(led01,OUTPUT);
      //analogWrite(led01,br01);
      
      // Setting frequency-scaling to 20%
      digitalWrite(aS0,HIGH);
      digitalWrite(aS1,LOW);

      
      pinMode(bS0, OUTPUT);
      pinMode(bS1, OUTPUT);
      pinMode(bS2, OUTPUT);
      pinMode(bS3, OUTPUT);
      pinMode(twoSensorOut, INPUT);
      //pinMode(led02,OUTPUT);
      //analogWrite(led02,br02);
      
      // Setting frequency-scaling to 20%
      digitalWrite(bS0,HIGH);
      digitalWrite(bS1,LOW);
      
      pinMode(cS0, OUTPUT);
      pinMode(cS1, OUTPUT);
      pinMode(cS2, OUTPUT);
      pinMode(cS3, OUTPUT);
      pinMode(threeSensorOut, INPUT);
      //pinMode(led03,OUTPUT);
      //analogWrite(led03,br03);
      
      // Setting frequency-scaling to 20%
      digitalWrite(cS0,HIGH);
      digitalWrite(cS1,LOW);

      pinMode(dS0, OUTPUT);
      pinMode(dS1, OUTPUT);
      pinMode(dS2, OUTPUT);
      pinMode(dS3, OUTPUT);
      pinMode(fourSensorOut, INPUT);
     // pinMode(led04,OUTPUT);
      //analogWrite(led04,br04);
      digitalWrite(dS0,HIGH);
      digitalWrite(dS1,LOW);
      
      //load cell
       Serial.println("HX711 weighing");
       scale.set_scale(calibration_factor);
      
       scale.begin(DOUT, CLK);
       scale.set_scale();
       scale.tare();
       Serial.println("Readings:");

       //PUMP MOTOR
       pinMode(enB, OUTPUT);
       pinMode(in3, OUTPUT);
       pinMode(in4, OUTPUT);

       //SERVO
       myservo.attach(6);  // attaches the servo on pin 9 to the servo object
       myservo.write(180);
       
       Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//   Serial.print(byteRead);
spectro();
   while (Serial.available()) {
     char byteRead = Serial.read();
//       if(byteRead== 'a' ){
//          Serial.print(byteRead);
//          Serial.println();  
//          
//          Serial.println(byteRead);
//                  
//       }
        if(byteRead== 'c' ){
        for(int i=0;i<32766;i++){
          Serial.write(byteRead);
          //WATER CAPILLARY TEST
          Serial.print("Water capillary test reading= ");
          resval = analogRead(respin); //Read data from analog pin and store it to resval variable
          Serial.println(resval);
          delay(100);
          
          //PUMP MOTOR ON
            digitalWrite(in3,LOW);
            digitalWrite(in4,HIGH);
            analogWrite(enB,255);
            
            if(Serial.available()) {
              char i = Serial.read();
              if(i=='s'){
                break;
              }
            }
              delay(100);
            }
        }
       else if(byteRead== 'l' ){
          for(int i=0; i<32500; i++){
          Serial.write(byteRead);
          //load cell       
          Serial.print("Reading:");
          units = scale.get_units(),10;
          
          ounces = units * 0.035274;
          Serial.print(units/1000);
          Serial.println(" grams");
          
          if(Serial.available()) {
              char i = Serial.read();
              if(i=='b'){
                break;
              }
            }
            
          delay(1000);
          
          }
       }
        else if(byteRead== 's' ){
            Serial.write(byteRead);
            digitalWrite(in3,LOW);
            digitalWrite(in4,LOW);
            analogWrite(enB,255);
        }
         else if(byteRead== 't' ){
            Serial.write(byteRead);
             myservo.write(90);// sets the servo position according to the scaled value
             delay(15); // waits for the servo to get there
         }
         else if(byteRead== 'p' ){
            Serial.print(byteRead);
            myservo.write(10);
            
         } 
   }
}
void spectro() {
    //SPECTROSCOPY TEST
                  Serial.print("spectro one");//For  NITROGEN(N) RED
                  Serial.println();
                  // Setting red filtered photodiodes to be read
                  digitalWrite(aS2,LOW);
                  digitalWrite(aS3,LOW);
                  // Reading the output frequency
                  frequency = pulseIn(oneSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("R= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  R=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Green filtered photodiodes to be read
                  digitalWrite(aS2,HIGH);
                  digitalWrite(aS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(oneSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("G= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  G=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Blue filtered photodiodes to be read
                  digitalWrite(aS2,LOW);
                  digitalWrite(aS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(oneSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("B= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  B=frequency;
                  Serial.println("  ");
                  delay(100);
                  P=R-B;
                  if(B<G&&B<R){
                    
                     if (-1<P&&P<1){
                     Serial.println("Processing");
            //         Serial.println("Purple Opacity");
            //         Serial.print( abs((B+R)/P));
                        
                     }else{  
                    Serial.println("Processing");
            //         Serial.println("Blue Opacity");
            //  Serial.print(abs((B)/P));
              Serial.println();
                     }  
                  }else if(G<B&&G<R){
                    
                    Serial.println("Processing");
            //         Serial.println("Green Opacity ");
            //    Serial.print((abs(G-R)+abs(G-B))/2.0);
                 Serial.println();
                    }else if(R<B&&R<G){
                       if (-1<P && P<1){
                        Serial.println("Processing");
            //             Serial.println("Purple Opacity");
            //      Serial.print( abs((B+R)/P));
                   Serial.println();
                       } else{
                      Serial.println("NITROGEN DETECTED");
                       Serial.print("NITROGEN Opacity : ");
                Serial.print(abs(R*100/75));
                 Serial.println();
                      } 
                      
                    }else{
                      Serial.println("Processing");
                      }
                      delay(1000);
            
            Serial.println("  ");
            Serial.println("  ");
            
            
            
                  Serial.print("spectro two");//For Phosphorus(P) BLUE
                  Serial.println();
                       // Setting red filtered photodiodes to be read
                  digitalWrite(bS2,LOW);
                  digitalWrite(bS3,LOW);
                  // Reading the output frequency
                  frequency = pulseIn(twoSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("R= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  R=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Green filtered photodiodes to be read
                  digitalWrite(bS2,HIGH);
                  digitalWrite(bS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(twoSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("G= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  G=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Blue filtered photodiodes to be read
                  digitalWrite(bS2,LOW);
                  digitalWrite(bS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(twoSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("B= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  B=frequency;
                  Serial.println("  ");
                  delay(100);
                  P=R-B;
                  if(B<G&&B<R){
                    
                     if (-3<P&&P<3){
                     Serial.println("Processing");
            //         Serial.println("Purple Opacity");
            //         Serial.print( abs((B+R)/P));
                   Serial.println();
                        
                     }else{  
                    Serial.println("PHOSPHORUS DETECTED");
                     Serial.print("PHOSPHORUS Opacity : ");
             Serial.print(abs(B*100/75));
              Serial.println();
                    }
                  }else if(G<B&&G<R){
                    
                    Serial.println("Processing");
            //         Serial.println("Green Opacity ");
            //    Serial.print((abs(G-R)+abs(G-B))/2.0);
                 Serial.println();
                    }else if(R<B&&R<G){
                       if (-3<P && P<3){
                        Serial.println("Processing");
            //             Serial.println("Purple Opacity");
            //      Serial.print( abs((B+R)/P));
                   Serial.println();
                       } else{
                      Serial.println("Processing");
            //           Serial.println("RED Opacity");
            //    Serial.print(abs(R/P));
                 Serial.println();
                      } 
                      
                    }else{
                      Serial.println("Processing");
                      }
                      delay(1000);
            
            
            Serial.println("  ");
            Serial.println("  ");
            
            
            
                  Serial.print("spectro three"); //  For  Potassium(K) PURPLE
                  Serial.println();
                       // Setting red filtered photodiodes to be read
                  digitalWrite(cS2,LOW);
                  digitalWrite(cS3,LOW);
                  // Reading the output frequency
                  frequency = pulseIn(threeSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("R= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  R=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Green filtered photodiodes to be read
                  digitalWrite(cS2,HIGH);
                  digitalWrite(cS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(threeSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("G= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  G=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Blue filtered photodiodes to be read
                  digitalWrite(cS2,LOW);
                  digitalWrite(cS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(threeSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("B= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  B=frequency;
                  Serial.println("  ");
                  delay(100);
                  P=R-B;
                  if(B<G&&B<R){
                    
                     if (-7<P&&P<7){
                     Serial.println("Pottasium DETECTED");
                     Serial.print("Pottasium Opacity : ");
                     Serial.print((((R+B)/2)*100)/3000);
                   Serial.println();
                        
                     }else{  
                    Serial.println("Processing");
            //         Serial.println("Blue Opacity");
            // Serial.print(abs((B)/P));
              Serial.println();
                    }
                  }else if(G<B&&G<R){
                    
                    Serial.println("Processing");
            //         Serial.println("Green Opacity ");
            //    Serial.print((abs(G-R)+abs(G-B))/2.0);
                 Serial.println();
                    }else if(R<B&&R<G){
                       if (-20<P && P<20){
                        Serial.println("Pottasium DETECTED");
                         Serial.print("Pottasium Opacity : ");
                  Serial.print((((R+B)/2)*100)/3000);
                   Serial.println();
                       } else{
                      Serial.println("Processing");
            //           Serial.println("RED Opacity");
            //    Serial.print(abs(R/P));
                 Serial.println();
                      } 
                      
                    }else{
                      Serial.println("Processing");
                      }
                      delay(1000);
                      Serial.println("  ");
                      Serial.println("  ");
            
                      Serial.print("spectro four");//For Amonia(P) BLUE
                  Serial.println();
                       // Setting red filtered photodiodes to be read
                  digitalWrite(dS2,LOW);
                  digitalWrite(dS3,LOW);
                  // Reading the output frequency
                  frequency = pulseIn(fourSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("R= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  R=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Green filtered photodiodes to be read
                  digitalWrite(dS2,HIGH);
                  digitalWrite(dS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(fourSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("G= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  G=frequency;
                  Serial.print("  ");
                  delay(100);
                  // Setting Blue filtered photodiodes to be read
                  digitalWrite(dS2,LOW);
                  digitalWrite(dS3,HIGH);
                  // Reading the output frequency
                  frequency = pulseIn(fourSensorOut, LOW);
                  // Printing the value on the serial monitor
                  Serial.print("B= ");//printing name
                  Serial.print(frequency);//printing RED color frequency
                  B=frequency;
                  Serial.println("  ");
                  delay(100);
                  P=R-B;
                  if(B<G&&B<R){
                    
                     if (-3<P&&P<3){
                     Serial.println("Processing");
            //         Serial.println("Purple Opacity");
            //         Serial.print( abs((B+R)/P));
                   Serial.println();
                        
                     }else{  
                    Serial.println("Amonia DETECTED");
                     Serial.print("Amonia Opacity : ");
             Serial.print(abs(B*100/75));
              Serial.println();
                    }
                  }else if(G<B&&G<R){
                    
                    Serial.println("Processing");
            //         Serial.println("Green Opacity ");
            //    Serial.print((abs(G-R)+abs(G-B))/2.0);
                 Serial.println();
                    }else if(R<B&&R<G){
                       if (-3<P && P<3){
                        Serial.println("Processing");
            //             Serial.println("Purple Opacity");
            //      Serial.print( abs((B+R)/P));
                   Serial.println();
                       } else{
                      Serial.println("Processing");
            //           Serial.println("RED Opacity");
            //    Serial.print(abs(R/P));
                 Serial.println();
                      } 
                      
                    }else{
                      Serial.println("Processing");
                      }
            
            Serial.println();
  }
