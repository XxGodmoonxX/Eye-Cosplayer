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

int grip = 10; //gripの角度
int delay_num = 1000; //それぞれの間のディレイ

int s; //shoulderの角度
int e; //elbowの角度

void setup() {
  Serial.begin(9600);
  Braccio.begin();
}
void loop() {
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
      
      //ここまで判子
      
      e = 90;
      Braccio.ServoMovement(3000, 110,s,e,133, syaringan_kakashi, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
      
      //ここから眼を描く
      
      //上の辺
      
      s = 30;
      e = 20;
      Braccio.ServoMovement(3000, 108,s,e,180-s-5, pen, grip);
      delay(delay_num);
      s = 42;
      e = 15;
      Braccio.ServoMovement(3000, 110,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 46;
      e = 11;
      Braccio.ServoMovement(3000, 98,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 49;
      e = 7;
      Braccio.ServoMovement(3000, 102,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 55;
      e = 4;
      Braccio.ServoMovement(3000, 105,s,e,180-s, pen, grip);
      delay(delay_num);
      //反対側手前の点
      s = 58;
      e = 0;
      Braccio.ServoMovement(3000, 108,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 53;
      e = 0;
      Braccio.ServoMovement(3000, 108,s,e,180-s, pen, grip);
      delay(delay_num);
      
      //下の辺
      
      s = 50;
      e = 4;
      Braccio.ServoMovement(3000, 110,s,e,180-s+10, pen, grip);
      delay(delay_num);
      s = 46;
      e = 7;
      Braccio.ServoMovement(3000, 112,s,e,180-s+10, pen, grip);
      delay(delay_num);
      s = 42;
      e = 11;
      Braccio.ServoMovement(3000, 114,s,e,180-s+5, pen, grip);
      delay(delay_num);
      s = 35;
      e = 20;
      Braccio.ServoMovement(3000, 105,s,e,180-s-5, pen, grip);
      delay(delay_num);
      s = 30;
      e = 25;
      Braccio.ServoMovement(3000, 102,s,e,180-s-10, pen, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 102,s,e,180-s-10, pen, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
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
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
      
      //ここから眼を描く
      
      //上の辺
      
      s = 30;
      e = 20;
      Braccio.ServoMovement(3000, 108,s,e,180-s-5, pen, grip);
      delay(delay_num);
      s = 42;
      e = 15;
      Braccio.ServoMovement(3000, 100,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 46;
      e = 11;
      Braccio.ServoMovement(3000, 98,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 49;
      e = 7;
      Braccio.ServoMovement(3000, 102,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 55;
      e = 4;
      Braccio.ServoMovement(3000, 105,s,e,180-s, pen, grip);
      delay(delay_num);
      //反対側手前の点
      s = 58;
      e = 0;
      Braccio.ServoMovement(3000, 108,s,e,180-s, pen, grip);
      delay(delay_num);
      s = 53;
      e = 0;
      Braccio.ServoMovement(3000, 108,s,e,180-s, pen, grip);
      delay(delay_num);
      
      //下の辺
      
      s = 50;
      e = 4;
      Braccio.ServoMovement(3000, 110,s,e,180-s+10, pen, grip);
      delay(delay_num);
      s = 46;
      e = 7;
      Braccio.ServoMovement(3000, 112,s,e,180-s+10, pen, grip);
      delay(delay_num);
      s = 42;
      e = 11;
      Braccio.ServoMovement(3000, 114,s,e,180-s+5, pen, grip);
      delay(delay_num);
      s = 35;
      e = 20;
      Braccio.ServoMovement(3000, 105,s,e,180-s-5, pen, grip);
      delay(delay_num);
      s = 30;
      e = 25;
      Braccio.ServoMovement(3000, 102,s,e,180-s-10, pen, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 102,s,e,180-s-10, pen, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
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
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
      
      //ここから眼を描く
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 102,s,e,180-s-10, pen, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
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
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
      
      //顔の皺部分
      
      s = 30;
      e = 20;
      Braccio.ServoMovement(3000, 113,s,e,180-s+10, pen, grip);
      delay(delay_num);
      //
      s = 35;
      e = 16;
      Braccio.ServoMovement(3000, 115,s,e,180-s+5, pen, grip);
      delay(delay_num);
      //
      s = 40;
      e = 14;
      Braccio.ServoMovement(3000, 117,s,e,180-s-5, pen, grip);
      delay(delay_num);
      
      //ここまで
      
      e = 90;
      Braccio.ServoMovement(3000, 102,s,e,180-s-10, pen, grip);
      delay(delay_num);
      
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
      delay(delay_num);
    }
  }
}
