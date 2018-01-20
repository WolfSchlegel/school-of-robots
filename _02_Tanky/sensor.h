const int input_left = 0;   // Yellow cable
const int input_right = 1;  // Blue cable

const int IR_SENSOR_THRESHOLD = 600;
const bool SENSOR_DEBUG = false;

enum Direction {
  BACKWARDS,
  FORWARDS,
  LEFT,
  RIGHT,
  UNDEFINED
};

Direction getDirection();
