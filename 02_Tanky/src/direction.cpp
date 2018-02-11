// Arduino.h still imported to provide String class
// TODO replace with c++ string type
//
#include <Arduino.h>

#include "robot.h"

// TODO direction.h is already included by robot.h, resolve dependency hell
//#include "direction.h"

String directionToString(Direction direction) {
  switch(direction) {
    case BACKWARDS:
      return "backwards";
    case FORWARDS:
      return "forwards";
    case LEFT:
      return "left";
    case RIGHT:
      return "right";
    default:
      return "undefined";
  }
}

Direction getDirection2(int rightValue, int leftValue){
  bool leftOnBlack = leftValue < IR_SENSOR_THRESHOLD;
  bool rightOnBlack = rightValue < IR_SENSOR_THRESHOLD;

  if (!leftOnBlack && !rightOnBlack) {
    return BACKWARDS;
  }
  if (leftOnBlack && rightOnBlack) {
    return FORWARDS;
  }
  if (leftOnBlack) {
    return LEFT;
  }
  if (rightOnBlack) {
    return RIGHT;
  }
  return FORWARDS;
}

Direction getDirection() {
  int rightValue = my_analogRead(input_right);
  int leftValue = my_analogRead(input_left);

  if ( SENSOR_DEBUG ) {
    my_println("right sensor value is " + String(rightValue));
    my_println("left sensor value is " + String(leftValue));
  }

  Direction direction = getDirection2(rightValue, leftValue);
  my_println("direction is " + directionToString(direction));

  return direction;
}
