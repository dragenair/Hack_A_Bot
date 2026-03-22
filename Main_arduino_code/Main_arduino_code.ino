#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo servo1; // Arm
Servo servo2; // Grip

// Variables for "Hold-to-Run" logic
unsigned long lastCommandTime = 0;
const int releaseTimeout = 250; 
bool isMoving = false;

// Variables for Smooth Servo movement
int armPos = 90; 
int gripPos = 0;

void setup() {
  Serial.begin(9600);

  // MAX SPEED SET TO 255
  motor1.setSpeed(150); 
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);  

  servo1.attach(10);
  servo2.attach(9);
  
  servo1.write(armPos); 
  servo2.write(gripPos);  
  
  stopMotors();
  Serial.println("--- MAX POWER LOADED ---");
  Serial.println("Speed: 255 | Arm Min: 0 degrees");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    lastCommandTime = millis(); 

    switch (command) {
      // --- Driving (WASD) ---
      case 'w': case 'W': moveForward();  isMoving = true; break;
      case 's': case 'S': moveBackward(); isMoving = true; break;
      case 'a': case 'A': turnLeft();     isMoving = true; break;
      case 'd': case 'D': turnRight();    isMoving = true; break;
      case ' ':           stopMotors();   isMoving = false; break;

      // --- Arm Control (T / G) ---
      case 't': case 'T': 
        armPos = min(armPos + 8, 180); // Increased jump to 8 for faster movement
        servo1.write(armPos); 
        break; 
      case 'g': case 'G': 
        armPos = max(armPos - 8, -25);   // Lower limit is now 0
        servo1.write(armPos); 
        break; 

      // --- Grip Control (F / H) ---
      case 'f': case 'F': 
        gripPos = max(gripPos - 8, 0);   
        servo2.write(gripPos); 
        break; 
      case 'h': case 'H': 
        gripPos = min(gripPos + 8, 90);  
        servo2.write(gripPos); 
        break; 

      case 'z': case 'Z': gripSequence(); break;
    }
  }

  // AUTO-STOP LOGIC
  if (isMoving && (millis() - lastCommandTime > releaseTimeout)) {
    stopMotors();
    isMoving = false;
  }
}

// --- MOVEMENT FUNCTIONS ---

void moveForward()  { motor1.run(FORWARD); motor2.run(FORWARD); motor3.run(FORWARD); motor4.run(FORWARD); }
void moveBackward() { motor1.run(BACKWARD); motor2.run(BACKWARD); motor3.run(BACKWARD); motor4.run(BACKWARD); }
void turnLeft()     { motor1.run(FORWARD); motor2.run(FORWARD); motor3.run(BACKWARD); motor4.run(BACKWARD); }
void turnRight()    { motor1.run(BACKWARD); motor2.run(BACKWARD); motor3.run(FORWARD); motor4.run(FORWARD); }
void stopMotors()   { motor1.run(RELEASE); motor2.run(RELEASE); motor3.run(RELEASE); motor4.run(RELEASE); }

void gripSequence() {
  armPos = 0;   servo1.write(armPos); 
  gripPos = 80; servo2.write(gripPos);
  armPos = 180; servo1.write(armPos);
}