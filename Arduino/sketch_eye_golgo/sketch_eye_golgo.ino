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
      
      //ゴルゴの眉の上部分
      
//      s = 57;
//      e = 2;
      Braccio.ServoMovement(3000, 16,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 48;
//      e = 9;
      Braccio.ServoMovement(3000, 10,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 42;
//      e = 15;
      Braccio.ServoMovement(3000, 5,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 30;
//      e = 20;
      Braccio.ServoMovement(3000, 14,s,e,180-s-5, wrist_rotation, grip);
      delay(delay_num);
      
      //ゴルゴの眉の下部分
      
//      s = 30;
//      e = 20;
      Braccio.ServoMovement(3000, 14,s,e,180-s-5, wrist_rotation, grip);
      delay(delay_num);
//      s = 42;
//      e = 15;
      Braccio.ServoMovement(3000, 7,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 44;
//      e = 15;
      Braccio.ServoMovement(3000, 9,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 49;
//      e = 7;
      Braccio.ServoMovement(3000, 18,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      
      //一旦ペンを上げる
      s = 90;
      Braccio.ServoMovement(3000, 18,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      
      //ゴルゴの眉左下のシワ的な部分
      
//      s = 53;
//      e = 4;
      Braccio.ServoMovement(3000, 17,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 61;
//      e = 0;
      s = 30;
      e = 20;
      Braccio.ServoMovement(3000, 22,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 55;
//      e = 5;
      Braccio.ServoMovement(3000, 25,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
//      s = 50;
//      e = 10;
      Braccio.ServoMovement(3000, 28,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      //一旦ペンを上げる
      s = 90;
      Braccio.ServoMovement(3000, 28,s,e,180-s-5, wrist_rotation, grip);
      delay(delay_num);
      
      //ゴルゴの眼の部分
      /*
      //上の辺
      s = 31;
      e = 19;
      Braccio.ServoMovement(3000, 17,s,e,180-s-8, wrist_rotation, grip);
      delay(delay_num);
      s = 51;
      e = 6;
      Braccio.ServoMovement(3000, 17,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      //角度を変える（ペンを引くために）
      s = 53;
      e = 5;
      Braccio.ServoMovement(3000, 19,s,e,180-s, wrist_rotation-10, grip);
      delay(delay_num);
      //下の辺
      s = 53;
      e = 5;
      Braccio.ServoMovement(3000, 22,s,e,180-s, wrist_rotation-10, grip);
      delay(delay_num);
      //角度戻す
      s = 51;
      e = 6;
      Braccio.ServoMovement(3000, 22,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 40;
      e = 16;
      Braccio.ServoMovement(3000, 17,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      //下と上結ぶ
      s = 33;
      e = 18;
      Braccio.ServoMovement(3000, 13,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      //一旦ペンを上げる
      s = 90;
      Braccio.ServoMovement(3000, 13,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      
      //ゴルゴの眼の中の部分
      
      //頂点
      s = 42;
      e = 15;
      Braccio.ServoMovement(3000, 15,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      s = 42;
      e = 15;
      Braccio.ServoMovement(3000, 20,s,e,180-s, wrist_rotation, grip);
      delay(delay_num);
      */
      
      
      
//      s = 58;
//      e = 0;
//      Braccio.ServoMovement(3000, 16,s,e,180-s, wrist_rotation, grip);
//      delay(delay_num);
      
      
      
//      s = 53;
//      e = 0;
//      Braccio.ServoMovement(3000, 18,s,e,180-s, wrist_rotation, grip);
//      delay(delay_num);
//      
//      s = 50;
//      e = 4;
//      Braccio.ServoMovement(3000, 20,s,e,180-s+10, wrist_rotation, grip);
//      delay(delay_num);
//      s = 46;
//      e = 7;
//      Braccio.ServoMovement(3000, 22,s,e,180-s+10, wrist_rotation, grip);
//      delay(delay_num);
//      s = 42;
//      e = 11;
//      Braccio.ServoMovement(3000, 24,s,e,180-s+5, wrist_rotation, grip);
//      delay(delay_num);
//      s = 35;
//      e = 20;
//      Braccio.ServoMovement(3000, 15,s,e,180-s-5, wrist_rotation, grip);
//      delay(delay_num);
//      s = 30;
//      e = 25;
//      Braccio.ServoMovement(3000, 12,s,e,180-s-10, wrist_rotation, grip);
//      delay(delay_num);
      //ここまで
      
      s = 90;
      Braccio.ServoMovement(3000, 12,s,e,180-s-10, wrist_rotation, grip);
      delay(delay_num);
      
      
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, wrist_rotation, grip);
      delay(delay_num);
    }
  }
}
