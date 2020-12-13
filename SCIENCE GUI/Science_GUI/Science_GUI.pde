/*------------------------------------------------------------------------------------
   Program:     port_select

   Description: Allows a serial port to be selected and connected to graphically.
                Has the following buttons:
                Up         - scrolls up through the serial port list 
                Down       - scrolls down through the serial port list
                Connect    - connects to the selected serial port
                Disconnect - disconnects from the serial port allowing a new serial
                             port to be connected to
                Refresh    - refreshes the list of serial ports. Useful if a new
                             serial device is connected to the PC after this app-
                             lication is started
                
   Purpose:     Allows the serial port to be selected within an application instead
                of hard-coding the port number
                
   Hardware:    Can be used to connect to Arduino or other serial devices
   
   Software:    Developed using Processing 2.2.1 (processing.org)
                Uses the Button class from:
                http://blog.startingelectronics.com/a-simple-button-for-processing-language-code/
                
   
------------------------------------------------------------------------------------*/

import controlP5.*;
import processing.serial.*;

Textarea connectionFeedback;
Textarea waterCapilary;
Textarea spectroscopy;



ControlP5 con;
PFont font3;
PFont font2;

Serial serial_port = null;        // the serial port

// serial port buttons
Button btn_serial_up;              // move up through the serial port list
Button btn_serial_dn;              // move down through the serial port list
Button btn_serial_connect;         // connect to the selected serial port
Button btn_serial_disconnect;      // disconnect from the serial port
Button btn_serial_list_refresh;    // refresh the serial port list

String serial_list;                // list of serial ports
int serial_list_index = 0;         // currently selected serial port 
int num_serial_ports = 0;          // number of serial ports in the list

int connectionLine = 1;
int wheelLine = 1;
int armLine = 1;
int cameraLine = 1;








void setup() {
  
  con = new ControlP5(this);
  
  // set the window size
  size (700, 450);
  PFont.list();
  
  font2 = createFont("calibri light", 16);
  font3 = createFont("calibri light", 13);
  
  
  // create the buttons
  btn_serial_up = new Button("^", 110, 125, 30, 20);
  btn_serial_dn = new Button("v", 110, 165, 30, 20);
  btn_serial_connect = new Button("Connect", 20, 250, 100, 25);
  btn_serial_disconnect = new Button("Disconnect", 20, 290, 100, 25);
  btn_serial_list_refresh = new Button("Refresh", 20, 210, 100, 25);
  
  // get the list of serial ports on the computer
  serial_list = Serial.list()[serial_list_index];
  
  //println(Serial.list());
  //println(Serial.list().length);
  
  // get the number of serial ports in the list
  num_serial_ports = Serial.list().length;
  
connectionFeedback = con.addTextarea("CONNECTION STATUS")
                .setPosition(15, 370)
                .setSize(150, 35)
                .setFont(font2)
                .setLineHeight(connectionLine)
                .setColor(color(0, 0, 0))
                .setColorBackground(color(240, 240, 240))
                .setColorForeground(color(250, 250, 250));
  

waterCapilary = con.addTextarea("WATER CAPILARY TEST")
                .setPosition(180, 180)
                .setSize(240, 225)
                .setFont(font2)
                .setLineHeight(wheelLine)
                .setColor(color(0, 0, 0))
                .setColorBackground(color(240, 240, 240))
                .setColorForeground(color(0, 0, 0));
  

spectroscopy = con.addTextarea("SPECTROSCOPY TEST")
                .setPosition(440, 180)
                .setSize(240, 225)
                .setFont(font2)
                .setLineHeight(armLine)
                .setColor(color(0, 0, 0))
                .setColorBackground(color(240, 240, 240))
                .setColorForeground(color(0, 0, 0));
  
}






void mousePressed() {
  // up button clicked
  if (btn_serial_up.MouseIsOver()) {
    if (serial_list_index > 0) {
      // move one position up in the list of serial ports
      serial_list_index--;
      serial_list = Serial.list()[serial_list_index];
    }
  }
  // down button clicked
  if (btn_serial_dn.MouseIsOver()) {
    if (serial_list_index < (num_serial_ports - 1)) {
      // move one position down in the list of serial ports
      serial_list_index++;
      serial_list = Serial.list()[serial_list_index];
    }
  }
  // Connect button clicked
  if (btn_serial_connect.MouseIsOver()) {
    if (serial_port == null) {
      // connect to the selected serial port
      serial_port = new Serial(this, Serial.list()[serial_list_index], 9600);
      fill(200, 100, 0);
      connectionFeedback.setText("Connected to "+serial_list);
    }
  }
  // Disconnect button clicked
  if (btn_serial_disconnect.MouseIsOver()) {
    if (serial_port != null) {
      // disconnect from the serial port
      serial_port.stop();
      serial_port = null;
      connectionFeedback.setText("Disconnected");
    }
  }
  // Refresh button clicked
  if (btn_serial_list_refresh.MouseIsOver()) {
    // get the serial port list and length of the list
    serial_list = Serial.list()[serial_list_index];
    num_serial_ports = Serial.list().length;
    connectionFeedback.setText(num_serial_ports+" Port(s) Found");
  }
}






void keyPressed(){
    
//  switch(key){
  
////Cases For Wheel
//    case 'w':
//      goForward();
//      break;
//    case 's':
//      goBackward();
//      break;
//    case 'a':
//      goLeft();
//      break;
//    case 'd':
//      goRight();
//      break;      
//    case 'b':
//      wheelStop();
//      break;
      

////Cases For Arm      
//    case 'v':
//      armStop();
//      break;      
//    case 'o':
//      clawOpen();
//      break;
//    case 'p':
//     clawClose();
//      break;      
//    case '.':
//      wristClockwise();
//      break;
//    case ',':
//      wristAnticlockwise();
//      break;
//    case 'y':
//      acc3Open();
//      break;
//    case 'h':
//      acc3Close();
//      break;
//    case 't':
//      acc2Open();
//      break;
//    case 'g':
//      acc2Close();
//      break;
//    case 'r':
//      acc1Open();
//      break;
//    case 'f':
//      acc1Close();
//      break;
//    case 'm':
//      baseClockwise();
//      break;
//    case 'n':
//      baseAnticlockwise();
//      break;
      
////Extender
//    case 'E':
//      extenderOpen();
//      break;
//    case 'e':
//      extenderClose();
//      break;
//    case 'c':
//      extenderStop();
//      break;

////FPV
//    case '8':
//      fpvAnt();
//      break;
//    case '2':
//      fpvReverse();
//      break;
//    case '4':
//      fpvBox();
//      break;
//    case '6':
//      fpvWrist();
//      break;
      

   
  
  //}

}

void keyReleased() {
  
  switch(key){
  
//  //Cases For Wheel
//    case 'w':
//      wheelStop();
//      break;
//    case 's':
//      wheelStop();
//      break;
//    case 'a':
//      wheelStop();
//      break;
//    case 'd':
//      wheelStop();
//      break;      
      

////Cases For Arm          
//    case 'o':
//      armStop();
//      break;
//    case 'p':
//     armStop();
//      break;      
//    case '.':
//      armStop();
//      break;
//    case ',':
//      armStop();
//      break;
//    case 'y':
//      armStop();
//      break;
//    case 'h':
//      armStop();
//      break;
//    case 't':
//      armStop();
//      break;
//    case 'g':
//      armStop();
//      break;
//    case 'r':
//      armStop();
//      break;
//    case 'f':
//      armStop();
//      break;
//    case 'm':
//      armStop();
//      break;
//    case 'n':
//      armStop();
//      break;
      
////Extender
//    case 'E':
//      extenderStop();
//      break;
//    case 'e':
//      extenderStop();
//      break;
  
  }
}








void draw() {
  
  background(255, 255, 255);
  
  fill(200, 100, 0); 
  textSize(20);
  text("BRACU MONGOL-TORI 2020", 230, 30);
  text("SCIENCE GUI", 290, 57);
  fill(0, 0, 0); 
  textFont(font2);
  text("COM PORTS", 35, 110);
  text("© 2019, Ashik Adnan | All Rights Reserved", 200, 432);
  textFont(font3);
  text("CONNECTION STATUS", 20, 360);
  text("WATER CAPILARY TEST RESULT", 220, 170);
  text("SPECTROSCOPY TEST RESULT", 480, 170);

  
  
  // draw the buttons in the application window
  btn_serial_up.Draw();
  btn_serial_dn.Draw();
  btn_serial_connect.Draw();
  btn_serial_disconnect.Draw();
  btn_serial_list_refresh.Draw();
  // draw the text box containing the selected serial port
  DrawTextBox("Select Port", serial_list, 15, 125, 85, 60);
  
}


// function for drawing a text box with title and contents
void DrawTextBox(String title, String str, int x, int y, int w, int h)
{
  fill(255);
  rect(x, y, w, h);
  fill(0);
  textAlign(LEFT);
  textSize(14);
  text(title, x + 10, y + 10, w - 20, 20);
  textSize(12);  
  text(str, x + 10, y + 40, w - 20, h - 10);
}


// button class used for all buttons
class Button {
  String label;
  float x;    // top left corner x position
  float y;    // top left corner y position
  float w;    // width of button
  float h;    // height of button
  
  // constructor
  Button(String labelB, float xpos, float ypos, float widthB, float heightB) {
    label = labelB;
    x = xpos;
    y = ypos;
    w = widthB;
    h = heightB;
  }
  
  // draw the button in the window
  void Draw() {
    fill(250);
    stroke(140);
    rect(x, y, w, h, 10);
    textAlign(CENTER, CENTER);
    fill(0);
    text(label, x + (w / 2), y + (h / 2));
  }
  
  // returns true if the mouse cursor is over the button
  boolean MouseIsOver() {
    if (mouseX > x && mouseX < (x + w) && mouseY > y && mouseY < (y + h)) {
      return true;
    }
    return false;
  }
}




//Methods For Wheel Run


//void goForward()
//{
//  serial_port.write('W');
//  wheelFeedback.setText("Forward");
//  println("Forward");
//}
//void goBackward()
//{
//   serial_port.write('S');
//  wheelFeedback.setText("Backward"); 
//  println("Backward");
//}
//void goLeft()
//{
//   serial_port.write('A');
//  wheelFeedback.setText("Left"); 
//  println("Left");
//}
//void goRight()
//{
//   serial_port.write('D');
//  wheelFeedback.setText("Right");
//  println("Right");
//}
//void wheelStop()
//{
//   serial_port.write('B');
//  wheelFeedback.setText("Rover Stop");
//  println("Rover Stop");
//}



//Methods For Arm Run


//void armStop()
//{
//  serial_port.write('V');
//  armFeedback.setText("Arm Stop");
//  println("Arm Stop");
//}
//void clawOpen()
//{
//  serial_port.write('O');
//  armFeedback.setText("Claw Open");
//  println("Claw Open");
//}
//void clawClose()
//{
//  serial_port.write('P');
//  armFeedback.setText("Claw Close");
//  println("Claw Close");
//}
//void wristClockwise()
//{
//  serial_port.write('>');
//  armFeedback.setText("Wrist Clockwise");
//  println("Wrist Clockwise");
//}
//void wristAnticlockwise()
//{
//  serial_port.write('<');
//  armFeedback.setText("Wrist Anticlockwise");  
//  println("Wrist Anticlockwise");  
//}
//void acc3Open()
//{
//  serial_port.write('Y');
//  armFeedback.setText("Actuator 3 Open");  
//  println("Actuator 3 Open");  
//}
//void acc3Close()
//{
//  serial_port.write('H');
//  armFeedback.setText("Actuator 3 Close");  
//  println("Actuator 3 Close");  
//}
//void acc2Open()
//{
//  serial_port.write('T');
//  armFeedback.setText("Actuator 2 Open");
//  println("Actuator 2 Open");
//}
//void acc2Close()
//{
//  serial_port.write('G');
//  armFeedback.setText("Actuator 2 Close"); 
//  println("Actuator 2 Close"); 
//}
//void acc1Open()
//{
//  serial_port.write('R');
//  armFeedback.setText("Actuator 1 Open");  
//  println("Actuator 1 Open");  
//}
//void acc1Close()
//{
//  serial_port.write('F');
//  armFeedback.setText("Actuator 1 Close"); 
//  println("Actuator 1 Close"); 
//}
//void baseClockwise()
//{
//  serial_port.write('M');
//  armFeedback.setText("Base Rotating Clockwise");  
//  println("Base Rotating Clockwise");  
//}
//void baseAnticlockwise()
//{
//  serial_port.write('N');
//  armFeedback.setText("Base Rotating Anticlockwise");  
//  println("Base Rotating Anticlockwise");  
//}



////Methods For FPV Switching


//void fpvAnt()
//{
//  serial_port.write('8');
//  cameraFeedback.setText("Fpv Camera View From Antena");  
//  println("Fpv Camera View From Antena");  
//}
//void fpvReverse()
//{
//  serial_port.write('2');
//  cameraFeedback.setText("Reverse Fpv Camera View");  
//  println("Reverse Fpv Camera View");  
//}
//void fpvBox()
//{
//  serial_port.write('4');
//  cameraFeedback.setText("Fpv Camera View From Box");  
//  println("Fpv Camera View From Box");  
//}
//void fpvWrist()
//{
//  serial_port.write('6');
//  cameraFeedback.setText("Fpv Camera View From Wrist"); 
//  println("Fpv Camera View From Wrist"); 
//}


////Methods For Extender

//void extenderOpen()
//{
//  serial_port.write('E');
//  armFeedback.setText("Extender Opening"); 
//  println("Extender Opening"); 
//}
//void extenderClose()
//{
//  serial_port.write('e');
//  armFeedback.setText("Extender Closing"); 
//  println("Extender Closing"); 
//}
//void extenderStop()
//{
//  serial_port.write('C');
//  armFeedback.setText("Extender Stop");
//  println("Extender Stop");
//}
