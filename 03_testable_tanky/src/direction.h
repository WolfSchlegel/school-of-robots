const int INPUT_LEFT = 0;   // Yellow cable
const int INPUT_RIGHT = 1;  // Blue cable

const int IR_SENSOR_THRESHOLD = 600;
const bool SENSOR_DEBUG = true;

enum Direction {
  BACKWARDS,
  FORWARDS,
  LEFT,
  RIGHT,
  UNDEFINED
};

Direction getDirection();
