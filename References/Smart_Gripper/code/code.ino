// ESP32 or Arduino code for a smart gripper. 
// It measures temperature with a thermistor and detects when an object is being held with an EDS foam
// Gripper is actuated with a "dsservo DS3230 pro" servo motor.

#include <ESP32Servo.h>

// ------- termistor constants: NTC Thermistor MF52B ----------
const float R_SERIES = 10000.0;   // series resistor (ohms)
const float BETA     = 3950.0;    // MF52B beta value
const float R0       = 10000.0;   // resistance at 25°C
const float temp0    = 298.15;    // 25°C in Kelvin

// --------------- define pins -------------
const int thermPin = 32;   // thermistor voltage divider output
const int foamPin  = 34;   // foam voltage divider output
const int potPin   = 35;   // potentiometer 0–3.3V

const int servoPin1 = 18;
const int servoPin2 = 19;

// ----- initialize low pass filter -------
float foamFiltered = 0.0;
float tempFiltered = 0.0;

const float alpha = 0.1;  // low pass filtering constant

float pot = 0.0;

Servo servo1, servo2;

void setup() {
  Serial.begin(115200);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  // -------------- thermistor --------------
  float temperature_celsius = readThermistorC(thermPin);

  // ------- foam resistance sensing --------
  int foamRaw = analogRead(foamPin);
  float foamVoltage = foamRaw * (3.3 / 4095.0); // for 3.3 V logic. When using Arduino change it to 5.0
  foamFiltered = lowPassFilter(foamVoltage, foamFiltered, alpha);

  // -------------- plot data --------------
  Serial.print(temperature_celsius); Serial.print(" "); Serial.println(40*(foamFiltered-1)); // foam measurment is scaled for better visuals

  // ---- read potentiometer and set the servo angle ----
  pot = analogRead(potPin) / 4095.0;
  write270(servo1, 135 -35 + 110*pot);

  delay(10);
}



// -------------- functions ---------------
// low pass filter: smooths out the data
float lowPassFilter(float input, float prevOutput, float alpha) {
  return alpha * input + (1.0 - alpha) * prevOutput;
}

// write270: set the angle of a 270 deg servo. When using a 180 deg servo, use servo.h library or change the function to: int pulseWidth = map(angle, 0, 180, 500, 2500);
void write270(Servo &servo, int angle) {
  int pulseWidth = map(angle, 0, 270, 500, 2500); // Adjust if needed
  servo.writeMicroseconds(pulseWidth);
}

// readThermistorC: converts thermistor output to temperature in °C
float readThermistorC(int adcPin) {
  int raw = analogRead(adcPin);

  // Convert ADC to voltage
  float v = raw * (3.3 / 4095.0);

  // Thermistor resistance
  float r = R_SERIES * (v / (3.3 - v));

  // Beta equation
  float tempK = 1.0 / ( (1.0 / temp0) + (1.0 / BETA) * log(r / R0) );
  float tempC = tempK - 273.15;

  // Low-pass filter
  tempFiltered = lowPassFilter(tempC, tempFiltered, alpha*2);
  //Serial.print(tempC); Serial.print(" "); 
  //Serial.println(tempFiltered);


  return tempFiltered;
}