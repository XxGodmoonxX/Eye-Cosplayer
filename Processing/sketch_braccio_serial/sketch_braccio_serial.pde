//シリアルライブラリの取り込み
import processing.serial.*;
//import cc.arduino.*;
//Arduino arduino;
Serial myPort; //シリアルポート

//ControlP5ライブラリーの読み込み
import controlP5.*;
//ControlP5をcp5として宣言
ControlP5 cp5;

Button button;

void setup() {
  size(600, 600);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
  
  cp5 = new ControlP5(this);
  
  button = cp5.addButton("enterA")
    .setLabel("Straight")
    .setPosition(250, 150)
    .setSize(100, 50);
    
  button = cp5.addButton("enterB")
    .setLabel("Draw Eye")
    .setPosition(250, 250)
    .setSize(100, 50);
}

void draw() {
}

void keyPressed() {
  if (key == 's') {
    enterA();
  }
  if (key == 'd') {
    enterB();
  }
}

void enterA() {
  myPort.write(1);
  println(myPort.read());
}

void enterB() {
  myPort.write(2);
  println(myPort.read());
}