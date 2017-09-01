#include <Braccio.h>
#include <Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int wrist_rotation = 40;
int grip = 73;

void setup() {
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees 0~180
  //Shoulder (M2): 45 degrees 15~165
  //Elbow (M3): 180 degrees 0~180
  //Wrist vertical (M4): 180 degrees 0~180
  //Wrist rotation (M5): 90 degrees 0~180
  //gripper (M6): 10 degrees 10~73
  Braccio.begin();
  
  Braccio.ServoMovement(1000,           0,   110, 5, 2,  wrist_rotation,  grip); //
  Braccio.ServoMovement(1000,           30,  110, 5, 2,  wrist_rotation,  grip); //
}
void loop() {
  /*
  Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
  M1=base degrees. Allowed values from 0 to 180 degrees
  M2=shoulder degrees. Allowed values from 15 to 165 degrees
  M3=elbow degrees. Allowed values from 0 to 180 degrees
  M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
  M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
  M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
  //  //Wait 1 second
  //  delay(1000);
  //きれいな形でぐるぐる
  //(step delay  M1 , M2 , M3 , M4 , M5 , M6);
  
  Braccio.ServoMovement(1000,           0,   110, 5, 2,  wrist_rotation,  grip); //
  Braccio.ServoMovement(1000,           7,   110, 5, 2,  wrist_rotation,  grip); //
  Braccio.ServoMovement(1000,           0,   110, 5, 2,  wrist_rotation,  grip); //
  Braccio.ServoMovement(1000,           7,   110, 5, 2,  wrist_rotation,  grip); //
  Braccio.ServoMovement(1000,           0,   110, 5, 2,  wrist_rotation,  grip); //
  Braccio.ServoMovement(1000,           7,   110, 5, 2,  wrist_rotation,  grip); //

}
