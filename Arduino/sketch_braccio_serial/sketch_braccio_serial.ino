#include <eye-cosplayer.h>
//#include <Braccio.h>
#include <Servo.h>

Servo base, shoulder, elbow, wrist_ver, wrist_rot, gripper;

int wrist_rotation = 0;
int grip = 10;
int wrist_black;
int wrist_red;

void setup() {
  //Base (M1):90 degrees 0~180
  //Shoulder (M2): 45 degrees 15~165
  //Elbow (M3): 180 degrees 0~180
  //Wrist vertical (M4): 180 degrees 0~180
  //Wrist rotation (M5): 90 degrees 0~180
  //gripper (M6): 10 degrees 10~73
  Serial.begin(9600);
  Braccio.begin();
}
void loop() {
  /*
  Step Delay: a milliseconds delay between the movement 
  of each servo. Allowed values from 10 to 30 msec.
  M1=base Allowed values from 0 to 180 degrees
  M2=shoulder Allowed values from 15 to 165 degrees
  M3=elbow Allowed values from 0 to 180 degrees
  M4=wrist vertical Allowed values from 0 to 180 degrees
  M5=wrist rotation Allowed values from 0 to 180 degrees
  M6=gripper Allowed values from 10 to 73 degrees. 
     10: the toungue is open, 
     73: the gripper is closed.
  */
  //(step delay  M1 , M2 , M3 , M4 , M5 , M6);
  // もしProcessingから何か文字を受けとったら
  if (Serial.available() > 0) {
    //データの受信を開始
    int val = Serial.read();
    Serial.write(val);
    if (val == 1) {  
      Braccio.ServoMovement(1000, 0, 100, 0, 90, wrist_rotation, grip);
      Braccio.ServoMovement(1000, 10, 100, 0, 90, wrist_rotation, grip);
      Braccio.ServoMovement(1000, 0, 100, 0, 90, wrist_rotation, grip);
      Braccio.ServoMovement(1000, 10, 100, 0, 90, wrist_rotation, grip);
    }
    if (val == 2) {
      Braccio.ServoMovement(1000, 0, 100, 0, 90, wrist_rotation, grip);
      Braccio.ServoMovement(1000, 0, 110, 0, 90, wrist_rotation, grip);
      Braccio.ServoMovement(1000, 0, 100,  0, 90, wrist_rotation, grip);
      Braccio.ServoMovement(1000, 0, 110, 0, 90, wrist_rotation, grip);
    }
  }
}
