#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#include "robot.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

int my_analogRead(int input) {
  return analogRead(input);
}

void my_delay(int value) {
  delay(value);
}

void my_println(String value) {
  Serial.println(value);
}

void my_setup() {
  Serial.begin(9600);

  Serial.println("initialising Adafruit Motorshield v2");
  AFMS.begin();  // create with the default frequency 1.6KHz

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("finished setup");
}

// experimental
void accelerate() {
  Serial.println("accelerating...");

  // rightMotor->run(FORWARD);
  // leftMotor->run(FORWARD);
  for (int i = SPEED_LOW; i <= SPEED_HIGH; i += SPEED_DELTA){
    Serial.println("setting speed to " + String(i));

    rightMotor->setSpeed(i);
    leftMotor->setSpeed(i);
    delay(SPEED_DELAY);
   }
}

// still experimental
void decelerate() {
  Serial.println("decelerating...");

  // rightMotor->run(FORWARD);
  // leftMotor->run(FORWARD);

  for (int i = SPEED_HIGH; i >= SPEED_LOW; i -= SPEED_DELTA){
    Serial.println("setting speed to " + String(i));

    rightMotor->setSpeed(i);
    leftMotor->setSpeed(i);
    delay(SPEED_DELAY);
   }
}

void moveForwards(int speed) {
  Serial.println("moving forwards...");
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(speed);
  leftMotor->setSpeed(speed);
}

void moveBackwards(int speed) {
  Serial.println("moving backwards...");
  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(speed);
  leftMotor->setSpeed(speed);
}

void rotateClockwise(int speed) {
  Serial.println("moving counterclockwise...");
  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(speed);
  leftMotor->setSpeed(speed);
}

void rotateCounterClockwise(int speed) {
  Serial.println("moving counterclockwise...");
  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(speed);
  leftMotor->setSpeed(speed);
}

void stop(int speed) {
  Serial.println("stopping...");
  rightMotor->setSpeed(speed);
  leftMotor->setSpeed(speed);
}

void stop() {
  stop(0);
}
