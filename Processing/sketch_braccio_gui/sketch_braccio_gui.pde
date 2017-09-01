//シリアルライブラリの取り込み
import processing.serial.*;
Serial port;

//ControlP5ライブラリーの読み込み
import controlP5.*;
//ControlP5をcp5として宣言
ControlP5 cp5;

//スライダーを宣言
Slider base;
Slider shoulder;
Slider elbow;
Slider wrist_rot;
Slider wrist_ver;
Slider gripper;

//ボタンを宣言
Button button;

void setup() {
  size(600, 600);
  
  //シリアルポートの設定
  //port = new Serial();
  
  //ContorlP5を初期化
  cp5 = new ControlP5(this);
  
    //スライダーbaseを追加
  base = cp5.addSlider("BASE")
    .setPosition(200, 100)
    .setRange(0, 180)
    .setValue(0)
    .setNumberOfTickMarks(91)
    .setSize(200, 30);
    
    //スライダーshoulderを追加
  shoulder = cp5.addSlider("SHOULDER")
    .setPosition(200, 150)
    .setRange(15, 165)
    .setValue(15)
    .setNumberOfTickMarks(46)
    .setSize(200, 30);
    
    //スライダーelbowを追加
  elbow = cp5.addSlider("ELBOW")
    .setPosition(200, 200)
    .setRange(0, 180)
    .setValue(0)
    .setNumberOfTickMarks(181)
    .setSize(200, 30);
    
    //スライダーwrist_rotを追加
  wrist_rot = cp5.addSlider("WRIST_ROT")
    .setPosition(200, 250)
    .setRange(0, 180)
    .setValue(0)
    .setNumberOfTickMarks(181)
    .setSize(200, 30);
    
    //スライダーwrist_verを追加
  wrist_ver = cp5.addSlider("WRIST_VER")
    .setPosition(200, 300)
    .setRange(0, 180)
    .setValue(0)
    .setNumberOfTickMarks(91)
    .setSize(200, 30);
    
    //スライダーgripperを追加
  gripper = cp5.addSlider("GRIPPER")
    .setPosition(200, 350)
    .setRange(10, 73)
    .setValue(10)
    .setNumberOfTickMarks(11)
    .setSize(200, 30);
    
  button = cp5.addButton("ENTER")
    .setPosition(250, 450)
    .setSize(100, 30);
    
}

void draw() {
  background(100);
}