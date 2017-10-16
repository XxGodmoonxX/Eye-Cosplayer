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
  
  button = cp5.addButton("straight")
    .setLabel("Straight")
    .setPosition(250, 150)
    .setSize(100, 50);
    
  button = cp5.addButton("syaringan_kakashi")
    .setLabel("Syaringan_kakashi")
    .setPosition(150, 250)
    .setSize(100, 50);
    
  button = cp5.addButton("syaringan_sasuke")
    .setLabel("Syaringan_sasuke")
    .setPosition(350, 250)
    .setSize(100, 50);
    
  button = cp5.addButton("ayanami")
    .setLabel("Ayanami")
    .setPosition(150, 350)
    .setSize(100, 50);
  
  button = cp5.addButton("golgo")
    .setLabel("Golgo")
    .setPosition(350, 350)
    .setSize(100, 50);
}

void draw() {
}

void keyPressed() {
  if (key == 's') {
    straight();
  }
  if (key == '1') {
    syaringan_kakashi();
  }
  if (key == '2') {
    syaringan_sasuke();
  }
  if (key == '3') {
    ayanami();
  }
  if (key == '4') {
    golgo();
  }
}

void straight() {
  myPort.write(1);
  println(myPort.read());
}

void syaringan_kakashi() {
  myPort.write(2);
  println(myPort.read());
}
void syaringan_sasuke() {
  myPort.write(3);
  println(myPort.read());
}
void ayanami() {
  myPort.write(4);
  println(myPort.read());
}
void golgo() {
  myPort.write(5);
  println(myPort.read());
}