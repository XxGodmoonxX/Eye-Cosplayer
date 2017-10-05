#include <eye-cosplayer.h>
//#include <Braccio.h>
#include <Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_ver;
Servo wrist_rot;
Servo gripper;

int wrist_rotation = 180;
int grip = 10;
int delay_num = 1000;

int s; //shoulderの角度
int e; //elbowの角度

void setup() {
  //Base (M1):90 degrees 0~180
  //Shoulder (M2): 45 degrees 15~165
  //Elbow (M3): 180 degrees 0~180
  //Wrist vertical (M4): 180 degrees 0~180
  //Wrist rotation (M5): 90 degrees 0~180
  //gripper (M6): 10 degrees 10~73
  Serial.begin(9600);
  Braccio.begin();
  
//  Braccio.ServoMovement(1000, 0, 110, 5, 2, wrist_rotation, grip);
//  Braccio.ServoMovement(1000, 30, 110, 5, 2, wrist_rotation, grip);
}
void loop() {
  /*
  Step Delay: a milliseconds delay between the movement of each servo.  
  Allowed values from 10 to 30 msec.
  M1=base 0 to 180 degrees
  M2=shoulder from 15 to 165 degrees
  M3=elbow from 0 to 180 degrees
  M4=wrist vertical from 0 to 180 degrees
  M5=wrist rotation from 0 to 180 degrees
  M6=gripper Allowed values from 10 to 73 degrees. 
     10: the toungue is open, 73: the gripper is closed.
  */
  //  //Wait 1 second
  //  delay(1000);
  //(step delay  M1 , M2 , M3 , M4 , M5 , M6);
  
  //もしProcessingから何か文字を受け取ったら
  if (Serial.available() > 0) {
    //データの受信を開始
    int val = Serial.read();
    Serial.write(val);
    if (val == 1) {
      //最初の基準合わせるやつ。
      Braccio.ServoMovement(3000, 0, 90, 90, 90, wrist_rotation, grip);
    }
    if (val == 2) {  
      //最初腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, wrist_rotation, grip);
      delay(delay_num);
      
      //ここから眼を描く
      s = 33;
      e = 19;
      Braccio.ServoMovement(3000, 18,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 42;
      e = 15;
      Braccio.ServoMovement(3000, 12,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 46;
      e = 11;
      Braccio.ServoMovement(3000, 10,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 49;
      e = 7;
      Braccio.ServoMovement(3000, 15,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      
      s = 53;
      e = 3;
      Braccio.ServoMovement(3000, 18,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      
      s = 49;
      e = 7;
      Braccio.ServoMovement(3000, 20,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 46;
      e = 11;
      Braccio.ServoMovement(3000, 22,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 42;
      e = 15;
      Braccio.ServoMovement(3000, 21,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 33;
      e = 19;
      Braccio.ServoMovement(3000, 17,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, wrist_rotation, grip);
      delay(delay_num);
    }
  }
}
