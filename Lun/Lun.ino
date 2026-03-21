#include <AFMotor.h>
#include <SoftwareSerial.h>


AF_DCMotor motor1(1, MOTOR12_1KHZ);  
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ); 
AF_DCMotor motor4(4, MOTOR34_1KHZ);  

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);  

}

void loop() {
  // put your main code here, to run repeatedly:

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

}
