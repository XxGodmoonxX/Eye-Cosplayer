//OpenCV
import gab.opencv.*; //OpenCVライブラリをインポート
import processing.video.*; //videoライブラリの読み込み（キャプチャに利用）
import java.awt.*; //ライブラリをインポート

Capture video; //カメラ用の変数
OpenCV opencv; //OpenCV用の画像メモリ

//OSC
import netP5.*;
import oscP5.*;
OscP5 oscP5;
//OSC送出先のネットアドレス
NetAddress myRemoteLocation;

void setup() {
  size(640, 480);
  
  //キャプチャは320×240にする
  video = new Capture(this, width/2, height/2);
  //取り込んだ画像をOpenCV形式へ
  opencv = new OpenCV(this, width/2, height/2);
  
  //目のデータをロード
  opencv.loadCascade(OpenCV.CASCADE_EYE);
  
  video.start(); //キャプチャを開始
  
  //OSC
  //受信用の変数。右の数字はポート番号。送信側のポート番号と合わせる。
  oscP5 = new OscP5(this, 12345);
  //OSC送信先のIPアドレスとポートを指定
  myRemoteLocation = new NetAddress("127.0.0.1", 12345);
  
  //データを送る先の関数を登録する。ここではgetDataは相手先の関数。
  //「/pattern」は送信側と受信側で同じである必要がある暗号
  oscP5.plug(this, "getData", "/pattern");
}

void draw() {
  // カメラが取り込める状態(動いている場合)はメモリに
  if(video.available()) video.read();
  
  scale(2); //画像を2倍に拡大
  opencv.loadImage(video); //ビデオ画像をメモリに展開
  image(video, 0, 0); //表示
  
  //目の領域
  noFill();
  stroke(0, 255, 0);
  strokeWeight(3);
  //顔検出結果の座標 eyes
  Rectangle[] eyes = opencv.detect();
  
  for (int i = 0; i < eyes.length; i++) {
    //println(eyes[i].x + "," + eyes[i].y);
    rect(eyes[i].x, eyes[i].y, eyes[i].width, eyes[i].height);
    text(eyes[i].width, eyes[i].x, eyes[i].y);
    text(eyes[i].height, eyes[i].x + 30, eyes[i].y);
  }
  
}