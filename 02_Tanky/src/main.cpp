// TODO use another string type and remove include
#include <Arduino.h>

#include "robot.h"

// TODO direction.h is already included by robot.h, resolve dependency hell
// conditional include to the rescue ?
//#include "direction.h"

const int VERSION = 41;

void setup() {
  my_setup();
  my_println("executing version " + String(VERSION));
}

const int SPEED_ZERO = 0;
const int SPEED_LOW = 60;
const int SPEED_HIGH = 120;

// const int SPEED_DELTA = 10;
// const int SPEED_DELAY = 50;

// void moveLeft() {
//   my_println("moving left...");
//   runRightMotor(FORWARDS);
//   runLeftMotor(BACKWARDS);
// }
//
// void moveRight() {
//   my_println("moving right...");
//   runRightMotor(BACKWARDS);
//   runLeftMotor(FORWARDS);
// }
//
// void moveForwards() {
//   my_println("moving forward...");
//   runRightMotor(FORWARDS);
//   runLeftMotor(FORWARDS);
//   setRightSpeed(SPEED_HIGH);
//   setLeftSpeed(SPEED_HIGH);
// }
//
// void moveBackwards() {
//   my_println("moving backwards....");
//   runRightMotor(BACKWARDS);
//   runLeftMotor(BACKWARDS);
//   setRightSpeed(SPEED_LOW);
//   setLeftSpeed(SPEED_LOW);
// }

// void stop() {
//   my_println("stopping.");
//   setRightSpeed(SPEED_ZERO);
//   setLeftSpeed(SPEED_ZERO);
//
// }

// TODO experimental
// void accelerate() {
//   my_println("accelerating...");
//   runRightMotor(FORWARDS);
//   runLeftMotor(FORWARDS);
//
//   for (int i = SPEED_LOW; i <= SPEED_HIGH; i += SPEED_DELTA){
//     my_println("setting speed to " + String(i));
//     setRightSpeed(i);
//     setLeftSpeed(i);
//     my_delay(SPEED_DELAY);
//    }
// }

// TODO still experimental
// void decelerate() {
//   my_println("braking hard...");
//   runRightMotor(FORWARDS);
//   runLeftMotor(FORWARDS);
//
//   for (int i = SPEED_HIGH; i >= SPEED_LOW; i -= SPEED_DELTA){
//     my_println("setting speed to " + String(i));
//     setRightSpeed(i);
//     setLeftSpeed(i);
//     my_delay(SPEED_DELAY);
//    }
// }

void loop() {

  // TODO debug backwards motion
  // moveBackwards();

  Direction direction = getDirection();

  switch(direction) {
    case BACKWARDS:
      moveBackwards(SPEED_LOW);
      break;
    case FORWARDS:
      moveForwards(SPEED_HIGH);
      break;
    case LEFT:
      rotateCounterClockwise(SPEED_HIGH);
      break;
    case RIGHT:
      rotateClockwise(SPEED_HIGH);
      break;
    default:
      stop(SPEED_ZERO);
  }

  my_delay(25);
}
