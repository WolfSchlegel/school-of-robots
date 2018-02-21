// TODO use another string type and remove include
#include <Arduino.h>

#include "robot.h"

// TODO direction.h is already included by robot.h, resolve dependency hell
// conditional include to the rescue ?
//#include "direction.h"

const int VERSION = 42;

void setup() {
  my_setup();
  my_println("executing version " + String(VERSION));
}

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
  // accelerate();
  // my_delay(2500);
  // decelerate();
}
