import gab.opencv.*; //OpenCVライブラリをインポート
import processing.video.*; //videoライブラリの読み込み（キャプチャに利用）
import java.awt.*; //ライブラリをインポート

Capture video; //カメラ用の変数
OpenCV opencv; //OpenCV用の画像メモリ

void setup() {
  size(640, 480);
  
  //キャプチャは320×240にする
  video = new Capture(this, width/2, height/2);
  //取り込んだ画像をOpenCV形式へ
  opencv = new OpenCV(this, width/2, height/2);
  
  //目のデータをロード
  opencv.loadCascade(OpenCV.CASCADE_EYE);
  
  video.start(); //キャプチャを開始
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