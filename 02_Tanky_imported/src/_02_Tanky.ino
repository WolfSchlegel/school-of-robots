/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#include "sensor.h"

const int VERSION = 37;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Executing Tanky version " + String(VERSION));
  
  Serial.println("Initialising Adafruit Motorshield v2");
  AFMS.begin();  // create with the default frequency 1.6KHz

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
  
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Finished setup");
}

const int SPEED_ZERO = 0;
const int SPEED_LOW = 70;
const int SPEED_HIGH = 140;

const int SPEED_DELTA = 10;
const int SPEED_DELAY = 50;

void moveLeft() {
  Serial.println("moving left...");
  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}

void moveRight() {
  Serial.println("moving right...");
  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
}

void moveForwards() {
  Serial.println("moving forward...");
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
  rightMotor->setSpeed(SPEED_HIGH); 
  leftMotor->setSpeed(SPEED_HIGH);  
}

void moveBackwards() {
  Serial.println("moving backwards....");
  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
  rightMotor->setSpeed(SPEED_LOW); 
  leftMotor->setSpeed(SPEED_LOW);  
}

void stop() {
  Serial.println("stopping.");
  rightMotor->setSpeed(SPEED_ZERO); 
  leftMotor->setSpeed(SPEED_ZERO);     
}

// experimental
void accelerate() {
  Serial.println("accelerating...");

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);

  for (int i = SPEED_LOW; i <= SPEED_HIGH; i += SPEED_DELTA){
    Serial.println("setting speed to " + String(i));

    rightMotor->setSpeed(i); 
    leftMotor->setSpeed(i);   
    delay(SPEED_DELAY);
   }
}

// still experimental
void decelerate() {
  Serial.println("braking hard...");

  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);

  for (int i = SPEED_HIGH; i >= SPEED_LOW; i -= SPEED_DELTA){
    Serial.println("setting speed to " + String(i));

    rightMotor->setSpeed(i); 
    leftMotor->setSpeed(i);   
    delay(SPEED_DELAY);
   }
}

void loop() {
  Direction direction = getDirection();

  switch(direction) {
    case BACKWARDS:
      moveBackwards();
      break;
    case FORWARDS:
      moveForwards();
      break;
    case LEFT:
      moveLeft();
      break;
    case RIGHT:
      moveRight();
      break;
  }

  delay(25);

}
