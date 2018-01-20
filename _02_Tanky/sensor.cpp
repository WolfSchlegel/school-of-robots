#include <Arduino.h>
#include "sensor.h"

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
  int rightValue = analogRead(input_right);
  int leftValue = analogRead(input_left);

  if ( SENSOR_DEBUG ) {
    Serial.println("Right value is " + String(rightValue));
    Serial.println("Left value is " + String(leftValue));
  }

  Direction direction = getDirection2(rightValue, leftValue);
  Serial.println("Direction is " + directionToString(direction));
  
  return direction;
}
