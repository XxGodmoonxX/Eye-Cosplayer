//本番用

#include <eye-cosplayer.h>
#include <Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_ver;
Servo wrist_rot;
Servo gripper;

int pen = 90;
int golgo = 0;
int ayanami = 175;
int syaringan_kakashi = 35;
int syaringan_sasuke = 135;

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
      Braccio.ServoMovement(3000, 0, 90, 90, 90, 90, grip);
    }
    if (val == 2) {  
      //写輪眼カカシ
      
      //最初腕を振り上げる
      
      Braccio.ServoMovement(3000, 13, 90, 90, 90, syaringan_kakashi, grip);
      delay(delay_num);
      
      //朱肉に押す
      
      s = 35;
      e = 0;
      Braccio.ServoMovement(3000, 10,s,e,128, syaringan_kakashi, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 10,s,e,128, syaringan_kakashi, grip);
      delay(delay_num);
      
      //判子を手に押す
      
      Braccio.ServoMovement(3000, 90,90,90,90, syaringan_kakashi, grip);
      delay(delay_num);
      s = 33;
      e = 5;
      Braccio.ServoMovement(3000, 113,s,e,120, syaringan_kakashi, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 110,s,e,133, syaringan_kakashi, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 13, s, 90, 133, 90, grip);
      delay(delay_num);
      
    }
    if (val == 3) {
      //写輪眼サスケ
      
      //最初腕を振り上げる
      
      Braccio.ServoMovement(3000, 13, 90, 90, 90, syaringan_sasuke, grip);
      delay(delay_num);
      
      //判子
      
      //朱肉に押す
      
      s = 35;
      e = 0;
      Braccio.ServoMovement(3000, 10,s,e,128, syaringan_sasuke, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 10,s,e,128, syaringan_sasuke, grip);
      delay(delay_num);
      
      //判子を手に押す
      
      Braccio.ServoMovement(3000, 90,90,90,90, syaringan_sasuke, grip);
      delay(delay_num);
      s = 33;
      e = 5;
      Braccio.ServoMovement(3000, 113,s,e,120, syaringan_sasuke, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 110,s,e,133, syaringan_sasuke, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 13, s, 90, 133, 90, grip);
      delay(delay_num);
      
    }
    if (val == 4) {
      //綾波レイ
      
      //最初腕を振り上げる
      
      Braccio.ServoMovement(3000, 13, 90, 90, 90, ayanami, grip);
      delay(delay_num);
      
      //朱肉に押す
      
      s = 42;
      e = 5;
      Braccio.ServoMovement(3000, 13,s,e,133, ayanami, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 13,s,e,133, ayanami, grip);
      delay(delay_num);
      
      //判子を手に押す
      
      Braccio.ServoMovement(3000, 90,90,90,90, ayanami, grip);
      delay(delay_num);
      s = 42;
      e = 6;
      Braccio.ServoMovement(3000, 110,s,e,133, ayanami, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 110,s,e,133, ayanami, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 13, s, 90, 133, 90, grip);
      delay(delay_num);
      
    }
    if (val == 5) {
      //ゴルゴ
      
      //最初腕を振り上げる
      
      Braccio.ServoMovement(3000, 13, 90, 90, 90, golgo, grip);
      delay(delay_num);
      
      //朱肉に押す
      
      s = 42;
      e = 5;
      Braccio.ServoMovement(3000, 5,s,e,133, golgo, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 5,s,e,133, golgo, grip);
      delay(delay_num);
      
      //判子を手に押す
      
      Braccio.ServoMovement(3000, 90,90,90,90, golgo, grip);
      delay(delay_num);
      s = 42;
      e = 6;
      Braccio.ServoMovement(3000, 110,s,e,133, golgo, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 110,s,e,133, golgo, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 13, s, 90, 133, 90, grip);
      delay(delay_num);
      
    }
  }
}
