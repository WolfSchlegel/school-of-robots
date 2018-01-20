/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->  http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *moving = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *turning = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  Serial.println(":)");
  AFMS.begin();  // create with the default frequency 1.6KHz
  Serial.println("After AFMS.begin()");
  // Set the speed to start, from 0 (off) to 255 (max speed)
  turning->setSpeed(0);
  moving->setSpeed(0);

  digitalWrite(LED_BUILTIN, HIGH);

  turning->run(FORWARD);
  moving->run(FORWARD);

  Serial.println("End of setup!");
}

const int SPEED_LOW = 0;
const int SPEED_HIGH = 200;

void turnClockwise() {
  turning->run(FORWARD);
  turning->setSpeed(SPEED_HIGH); 
}

void turnCounterclockwise() {
  turning->run(BACKWARD);
  turning->setSpeed(SPEED_HIGH); 
}

void moveForward() {
  moving->run(FORWARD);
  moving->setSpeed(SPEED_HIGH);   
}

void moveBackward() {
  moving->run(BACKWARD);
  moving->setSpeed(SPEED_HIGH);   
}

void stop() {
  turning->setSpeed(SPEED_LOW); 
  moving->setSpeed(SPEED_LOW);     
}

// CONTINUE HERE

void turnOnSpot() {
  turning->setSpeed(SPEED_HIGH); 
  moving->setSpeed(SPEED_LOW);   
}

void moveForwardsWhileTurningClockwise() {
  turning->run(FORWARD);
  turning->setSpeed(SPEED_HIGH); 
  
  moving->run(FORWARD);
  moving->setSpeed(SPEED_HIGH);   
}

void moveBackwardsWhileTurningClockwise() {
  turning->run(FORWARD);
  turning->setSpeed(SPEED_HIGH); 
  
  moving->run(BACKWARD);
  moving->setSpeed(SPEED_HIGH);   
}

void moveForwardsWhileTurningAnticlockwise() {
  turning->run(BACKWARD);
  turning->setSpeed(SPEED_HIGH); 
  
  moving->run(FORWARD);
  moving->setSpeed(SPEED_HIGH);   
}

void moveBackwardsWhileTurningAnticlockwise() {
  turning->run(BACKWARD);
  turning->setSpeed(SPEED_HIGH); 
  
  moving->run(BACKWARD);
  moving->setSpeed(SPEED_HIGH);   
}

void loop() {
  String version = String(5);
  Serial.println("In loop, version " + version);
  
  moveBackward();
  
  delay(25);
}
