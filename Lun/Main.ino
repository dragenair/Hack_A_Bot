#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <nRF24L01.h>

//RF24 radio(9, 10);

const byte address[6] = "00001";

struct Data {
  bool up;
  bool down;
  bool left;
  bool right;
};

Data data;

AF_DCMotor motor1(1, MOTOR12_1KHZ);   // front left
AF_DCMotor motor2(2, MOTOR12_1KHZ);   // back left
AF_DCMotor motor3(3, MOTOR34_1KHZ);   // front right
AF_DCMotor motor4(4, MOTOR34_1KHZ);   // back right

Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
  /*
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);

  radio.startListening();

  */

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);  

  servo1.attach(10);    // Arm
  servo2.attach(9);     // Grip

  servo1.write(90);
  servo2.write(0);
}

void loop(){
  moveforward();
  delay(2000);
  grip();
  delay(6000);
  release();
  delay(500);

}

/*
void loop() {

  if (radio.available()) {
    radio.read(&data, sizeof(data));

    if (data.up) {
      moveforward();
    }
    else if (data.down) {
      moveBackward();
    }
    else if (data.left) {
      turnLeft();
    }
    else if (data.right) {
      turnRight();
    }
    else {
      stop();
    }
  }
}
*/

void moveforward(){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft(){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void turnRight(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void grab(){
  servo2.write(80);
}

void release(){
  servo2.write(0);
}

void liftup(){
  servo1.write(90);
}

void putdown(){
  servo1.write(0);
}

void grip(){
  putdown();
  delay(1000);

  grab();
  delay(1000);

  liftup();
  //delay(4000);
  //release();
  //delay(300);
}
