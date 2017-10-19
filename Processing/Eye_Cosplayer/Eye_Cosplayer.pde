//本番用

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
    .setLabel("s_Straight")
    .setPosition(250, 50)
    .setSize(100, 50);
    
  button = cp5.addButton("syaringan_kakashi")
    .setLabel("1_Syaringan_kakashi")
    .setPosition(150, 150)
    .setSize(100, 50);
    
  button = cp5.addButton("syaringan_kakashi_pen")
    .setLabel("2_Syaringan_kakashi_pen")
    .setPosition(150, 250)
    .setSize(100, 50);
    
  button = cp5.addButton("syaringan_sasuke")
    .setLabel("3_Syaringan_sasuke")
    .setPosition(350, 150)
    .setSize(100, 50);
    
  button = cp5.addButton("syaringan_sasuke_pen")
    .setLabel("4_Syaringan_sasuke_pen")
    .setPosition(350, 250)
    .setSize(100, 50);
    
  button = cp5.addButton("ayanami")
    .setLabel("5_Ayanami")
    .setPosition(150, 350)
    .setSize(100, 50);
    
  button = cp5.addButton("ayanami_pen")
    .setLabel("6_Ayanami_pen")
    .setPosition(150, 450)
    .setSize(100, 50);
  
  button = cp5.addButton("golgo")
    .setLabel("7_Golgo")
    .setPosition(350, 350)
    .setSize(100, 50);
    
  button = cp5.addButton("golgo_pen")
    .setLabel("8_Golgo_pen")
    .setPosition(350, 450)
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
    syaringan_kakashi_pen();
  }
  if (key == '3') {
    syaringan_sasuke();
  }
  if (key == '4') {
    syaringan_sasuke_pen();
  }
  if (key == '5') {
    ayanami();
  }
  if (key == '6') {
    ayanami_pen();
  }
  if (key == '7') {
    golgo();
  }
  if (key == '8') {
    golgo_pen();
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
void syaringan_kakashi_pen() {
  myPort.write(3);
  println(myPort.read());
}
void syaringan_sasuke() {
  myPort.write(4);
  println(myPort.read());
}
void syaringan_sasuke_pen() {
  myPort.write(5);
  println(myPort.read());
}
void ayanami() {
  myPort.write(6);
  println(myPort.read());
}
void ayanami_pen() {
  myPort.write(7);
  println(myPort.read());
}
void golgo() {
  myPort.write(8);
  println(myPort.read());
}
void golgo_pen() {
  myPort.write(9);
  println(myPort.read());
}