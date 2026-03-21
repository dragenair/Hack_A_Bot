#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);   // front left
AF_DCMotor motor2(2, MOTOR12_1KHZ);   // back left
AF_DCMotor motor3(3, MOTOR34_1KHZ);   // front right
AF_DCMotor motor4(4, MOTOR34_1KHZ);   // back right

Servo servo1;
Servo servo2;



void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);  

  servo1.attach(10);    // Arm
  servo2.attach(9);     // Grip

  servo1.write(90);
  servo2.write(90);


}

void loop() {
  // put your main code here, to run repeatedly:
    
    servo2.write(90);
    delay(1000);
    servo2.write(180);
    delay(1000);
    


}

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

}

void release(){

}

void liftup(){

}

void putdown(){

}
