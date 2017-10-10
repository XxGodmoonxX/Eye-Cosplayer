//Arduinoとの通信部分
//シリアルライブラリの取り込み
import processing.serial.*;
Serial myPort; //シリアルポート

//ボタン部分
//ControlP5ライブラリーの読み込み
//import controlP5.*;
import controlP5.Button;
import controlP5.ControlP5;
//ControlP5をcp5として宣言
ControlP5 cp5;
Button button;

//OSC通信
import netP5.*;
import oscP5.*;
OscP5 oscP5;
int receivePort;

void setup() {
  size(600, 600);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
  
  //ボタン部分
  cp5 = new ControlP5(this);
  
  button = cp5.addButton("enterA")
    .setLabel("Enter A")
    .setPosition(250, 150)
    .setSize(100, 50);
    
  button = cp5.addButton("enterB")
    .setLabel("Enter B")
    .setPosition(250, 250)
    .setSize(100, 50);
    
  //OSC部分
  oscP5 = new OscP5(this, receivePort);
}

void draw() {
}

void enterA() {
  myPort.write(1);
  println(myPort.read());
}

void enterB() {
  myPort.write(2);
  println(myPort.read());
}