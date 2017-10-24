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
int ayanami = 180;
int syaringan_kakashi = 53;
int syaringan_sasuke = 148;

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
      //写輪眼カカシ 判子

      //最初腕を振り上げる
      Braccio.ServoMovement(3000, 13, 90, 90, 90, syaringan_kakashi, grip);
      delay(delay_num);
      //朱肉に押す
      s = 35;
      e = 0;
      Braccio.ServoMovement(3000, 10, s, e, 128, syaringan_kakashi - 15, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 10, s, e, 128, syaringan_kakashi - 15, grip);
      delay(delay_num);
      //手の上で振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 90, syaringan_kakashi, grip);
      delay(delay_num);
      //手の上で判子が平行
      s = 40;
      e = 50;
      Braccio.ServoMovement(3000, 115, s, e, 90, syaringan_kakashi - 12, grip);
      delay(delay_num);
      //手に押す
      s = 35;
      e = 40;
      Braccio.ServoMovement(3000, 115, s, e, 90, syaringan_kakashi - 12, grip);
      delay(delay_num);
      s = 35;
      e = 36;
      Braccio.ServoMovement(3000, 115, s, e, 95, syaringan_kakashi - 12, grip);
      delay(delay_num);
      s = 38;
      e = 33;
      Braccio.ServoMovement(3000, 115, s, e, 100, syaringan_kakashi - 12, grip);
      delay(delay_num);
      s = 40;
      e = 30;
      Braccio.ServoMovement(3000, 115, s, e, 103, syaringan_kakashi - 12, grip);
      delay(delay_num);
      //ここまで判子
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 115, s, e, 120, syaringan_kakashi - 12, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
    }
    if (val == 3) {
      //写輪眼カカシ ペン
      
      //↓新しいバージョン
      
      //ここから眼を描く
      //上の辺
      //最初
      Braccio.ServoMovement(3000, 90, 45, 90, 133, 90, grip);
      delay(delay_num);
      //まず平行
      s = 50;
      e = 45;
      Braccio.ServoMovement(3000, 112, s, e, 110, pen + 5, grip);
      delay(delay_num);
      //ここから描く
      s = 40;
      e = 25;
      Braccio.ServoMovement(3000, 113, s, e, 118, pen + 5, grip);
      delay(delay_num);
      s = 47;
      e = 30;
      Braccio.ServoMovement(3000, 102, s, e, 113, pen + 5, grip);
      delay(delay_num);
      s = 51;
      e = 32;
      Braccio.ServoMovement(3000, 99, s, e, 113, pen + 5, grip);
      delay(delay_num);
      s = 57;
      e = 10;
      Braccio.ServoMovement(3000, 102, s, e, 113, pen, grip);
      delay(delay_num);
//      s = 55;
//      e = 6;
//      Braccio.ServoMovement(3000, 107, s, e, 130, pen, grip);
//      delay(delay_num);
//      s = 58;
//      e = 4;
//      Braccio.ServoMovement(3000, 110, s, e, 130, pen, grip);
//      delay(delay_num);
//      //反対側の点
//      s = 62;
//      e = 2;
//      Braccio.ServoMovement(3000, 116, s, e, 120, pen, grip);
//      delay(delay_num);
//      s = 60;
//      e = 20;
//      Braccio.ServoMovement(3000, 114, s, e, 85, pen, grip);
//      delay(delay_num);
//      //下の辺
//      s = 60;
//      e = 27;
//      Braccio.ServoMovement(3000, 116, s, e, 85, pen + 5, grip);
//      delay(delay_num);
//      s = 56;
//      e = 36;
//      Braccio.ServoMovement(3000, 116, s, e, 85, pen + 5, grip);
//      delay(delay_num);
//      s = 48;
//      e = 45;
//      Braccio.ServoMovement(3000, 113, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      s = 43;
//      e = 49;
//      Braccio.ServoMovement(3000, 112, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      s = 38;
//      e = 54;
//      Braccio.ServoMovement(3000, 107, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      s = 33;
//      e = 59;
//      Braccio.ServoMovement(3000, 104, s, e, 90, pen + 5, grip);
//      delay(delay_num);
      //ここまで
      s = 60;
      e = 70;
      Braccio.ServoMovement(3000, 104, s, e, 120, pen + 5, grip);
      delay(delay_num);
      s = 70;
      e = 90;
      Braccio.ServoMovement(3000, 104, s, e, 120, pen + 5, grip);
      delay(delay_num);
//      //最後腕を振り上げる
//      Braccio.ServoMovement(3000, 0, 90, 30, 130, pen, grip);
//      delay(delay_num);
      
      //↓いままでのバージョン
      
//      //ここから眼を描く
//      //上の辺
//      //最初
//      Braccio.ServoMovement(3000, 90, 45, 90, 133, 90, grip);
//      delay(delay_num);
//      s = 35;
//      e = 22;
//      Braccio.ServoMovement(3000, 114, s, e, 98, pen + 5, grip);
//      delay(delay_num);
//      s = 43;
//      e = 16;
//      Braccio.ServoMovement(3000, 104, s, e, 110, pen, grip);
//      delay(delay_num);
//      s = 46;
//      e = 13;
//      Braccio.ServoMovement(3000, 101, s, e, 130, pen, grip);
//      delay(delay_num);
//      s = 49;
//      e = 10;
//      Braccio.ServoMovement(3000, 102, s, e, 130, pen, grip);
//      delay(delay_num);
//      s = 55;
//      e = 6;
//      Braccio.ServoMovement(3000, 107, s, e, 130, pen, grip);
//      delay(delay_num);
//      s = 58;
//      e = 4;
//      Braccio.ServoMovement(3000, 110, s, e, 130, pen, grip);
//      delay(delay_num);
//      //反対側の点
//      s = 62;
//      e = 2;
//      Braccio.ServoMovement(3000, 116, s, e, 120, pen, grip);
//      delay(delay_num);
//      s = 60;
//      e = 20;
//      Braccio.ServoMovement(3000, 114, s, e, 85, pen, grip);
//      delay(delay_num);
//      //下の辺
//      s = 60;
//      e = 27;
//      Braccio.ServoMovement(3000, 116, s, e, 85, pen + 5, grip);
//      delay(delay_num);
//      s = 56;
//      e = 36;
//      Braccio.ServoMovement(3000, 116, s, e, 85, pen + 5, grip);
//      delay(delay_num);
//      s = 48;
//      e = 45;
//      Braccio.ServoMovement(3000, 113, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      s = 43;
//      e = 49;
//      Braccio.ServoMovement(3000, 112, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      s = 38;
//      e = 54;
//      Braccio.ServoMovement(3000, 107, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      s = 33;
//      e = 59;
//      Braccio.ServoMovement(3000, 104, s, e, 90, pen + 5, grip);
//      delay(delay_num);
//      //ここまで
//      s = 50;
//      e = 90;
//      Braccio.ServoMovement(3000, 104, s, e, 90, pen, grip);
//      delay(delay_num);
//      //最後腕を振り上げる
//      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
//      delay(delay_num);
    }
    if (val == 4) {
      //写輪眼サスケ 判子

      //最初腕を振り上げる
      Braccio.ServoMovement(3000, 13, 90, 90, 90, syaringan_sasuke, grip);
      delay(delay_num);
      //朱肉に押す
      s = 35;
      e = 0;
      Braccio.ServoMovement(3000, 7, s, e, 128, syaringan_sasuke - 8, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 7, s, e, 128, syaringan_sasuke - 8, grip);
      delay(delay_num);
      //手の上で判子振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 90, syaringan_sasuke, grip);
      delay(delay_num);
      //手の上で判子が平行
      s = 40;
      e = 40;
      Braccio.ServoMovement(3000, 109, s, e, 95, syaringan_sasuke + 3, grip);
      delay(delay_num);
      //判子を手に押す
      s = 35;
      e = 40;
      Braccio.ServoMovement(3000, 109, s, e, 95, syaringan_sasuke + 3, grip);
      delay(delay_num);
      s = 38;
      e = 37;
      Braccio.ServoMovement(3000, 109, s, e, 100, syaringan_sasuke + 3, grip);
      delay(delay_num);
      s = 40;
      e = 33;
      Braccio.ServoMovement(3000, 109, s, e, 103, syaringan_sasuke + 3, grip);
      delay(delay_num);
      //ここまで判子
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 108, s, e, 118, syaringan_sasuke, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
    }
    if (val == 5) {
      //写輪眼サスケ ペン

      //ここから眼を描く
      //上の辺
      //最初
      Braccio.ServoMovement(3000, 90, 45, 90, 133, 90, grip);
      delay(delay_num);
      s = 35;
      e = 22;
      Braccio.ServoMovement(3000, 114, s, e, 98, pen + 5, grip);
      delay(delay_num);
      s = 43;
      e = 16;
      Braccio.ServoMovement(3000, 104, s, e, 110, pen, grip);
      delay(delay_num);
      s = 46;
      e = 13;
      Braccio.ServoMovement(3000, 101, s, e, 130, pen, grip);
      delay(delay_num);
      s = 49;
      e = 10;
      Braccio.ServoMovement(3000, 102, s, e, 130, pen, grip);
      delay(delay_num);
      s = 55;
      e = 6;
      Braccio.ServoMovement(3000, 107, s, e, 130, pen, grip);
      delay(delay_num);
      s = 58;
      e = 4;
      Braccio.ServoMovement(3000, 110, s, e, 130, pen, grip);
      delay(delay_num);
      //反対側の点
      s = 62;
      e = 2;
      Braccio.ServoMovement(3000, 116, s, e, 120, pen, grip);
      delay(delay_num);
      s = 60;
      e = 20;
      Braccio.ServoMovement(3000, 114, s, e, 85, pen, grip);
      delay(delay_num);
      //下の辺
      s = 60;
      e = 27;
      Braccio.ServoMovement(3000, 116, s, e, 85, pen + 5, grip);
      delay(delay_num);
      s = 56;
      e = 36;
      Braccio.ServoMovement(3000, 116, s, e, 85, pen + 5, grip);
      delay(delay_num);
      s = 48;
      e = 45;
      Braccio.ServoMovement(3000, 113, s, e, 90, pen + 5, grip);
      delay(delay_num);
      s = 43;
      e = 49;
      Braccio.ServoMovement(3000, 112, s, e, 90, pen + 5, grip);
      delay(delay_num);
      s = 38;
      e = 54;
      Braccio.ServoMovement(3000, 107, s, e, 90, pen + 5, grip);
      delay(delay_num);
      s = 33;
      e = 59;
      Braccio.ServoMovement(3000, 104, s, e, 90, pen + 5, grip);
      delay(delay_num);
      //ここまで
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 104, s, e, 90, pen, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
      delay(delay_num);
    }
    if (val == 6) {
      //綾波レイ 判子

      //最初腕を振り上げる
      Braccio.ServoMovement(3000, 13, 90, 90, 90, ayanami, grip);
      delay(delay_num);
      //朱肉に押す
      s = 45;
      e = 0;
      Braccio.ServoMovement(3000, 10, s, e, 137, ayanami, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 10, s, e, 137, ayanami, grip);
      delay(delay_num);
      //判子を上に振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 90, ayanami, grip);
      delay(delay_num);
      //手の上で判子が平行
      s = 50;
      e = 30;
      Braccio.ServoMovement(3000, 115, s, e, 95, ayanami, grip);
      delay(delay_num);
      //判子を手に押す
      s = 40;
      e = 20;
      Braccio.ServoMovement(3000, 115, s, e, 100, ayanami, grip);
      delay(delay_num);
      s = 35;
      e = 25;
      Braccio.ServoMovement(3000, 115, s, e, 105, ayanami, grip);
      delay(delay_num);
      //ここまで
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 114, s, e, 133, ayanami, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
    }
    if (val == 7) {
      //綾波レイ ペン

      //ここから眼を描く
      //最初
      Braccio.ServoMovement(3000, 90, 60, 90, 133, 90, grip);
      delay(delay_num);
      s = 42;
      e = 16;
      Braccio.ServoMovement(3000, 110, s, e, 125, pen, grip);
      delay(delay_num);
      s = 47;
      e = 12;
      Braccio.ServoMovement(3000, 109, s, e, 125, pen, grip);
      delay(delay_num);
      s = 52;
      e = 7;
      Braccio.ServoMovement(3000, 109, s, e, 125, pen, grip);
      delay(delay_num);
      s = 57;
      e = 4;
      Braccio.ServoMovement(3000, 109, s, e, 125, pen, grip);
      delay(delay_num);
      s = 62;
      e = 1;
      Braccio.ServoMovement(3000, 110, s, e, 125, pen, grip);
      delay(delay_num);
      //ここまで
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 110, s, e, 125, pen, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
      delay(delay_num);
    }
    if (val == 8) {
      //ゴルゴ 判子

      //最初腕を振り上げる
      Braccio.ServoMovement(3000, 13, 90, 90, 90, golgo, grip);
      delay(delay_num);
      //朱肉に押す
      s = 45;
      e = 2;
      Braccio.ServoMovement(3000, 6, s, e, 137, golgo, grip);
      delay(delay_num);
      e = 90;
      Braccio.ServoMovement(3000, 6, s, e, 137, golgo, grip);
      delay(delay_num);
      //判子を上に振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 90, golgo, grip);
      delay(delay_num);
      //判子が手の上で平行
      s = 60;
      e = 40;
      Braccio.ServoMovement(3000, 111, s, e, 105, golgo, grip);
      delay(delay_num);
      //判子を手に押す
      s = 40;
      e = 20;
      Braccio.ServoMovement(3000, 111, s, e, 100, golgo, grip);
      delay(delay_num);
      //ここまで
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 111, s, e, 133, golgo, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 90, s, 90, 133, 90, grip);
      delay(delay_num);
    }
    if (val == 9) {
      //ゴルゴ ペン

      //顔の皺部分
      //最初
      Braccio.ServoMovement(3000, 90, 60, 90, 133, 90, grip);
      delay(delay_num);
      s = 41;
      e = 35;
      Braccio.ServoMovement(3000, 110, s, e, 90, pen + 15, grip);
      delay(delay_num);
      s = 30;
      e = 40;
      Braccio.ServoMovement(3000, 120, s, e, 90, pen + 15, grip);
      delay(delay_num);
      s = 40;
      e = 30;
      Braccio.ServoMovement(3000, 126, s, e, 90, pen + 15, grip);
      delay(delay_num);
      //ここまで
      s = 50;
      e = 90;
      Braccio.ServoMovement(3000, 102, s, e, 130, pen, grip);
      delay(delay_num);
      //最後腕を振り上げる
      Braccio.ServoMovement(3000, 0, 90, 30, 90, pen, grip);
      delay(delay_num);
    }
  }
}
