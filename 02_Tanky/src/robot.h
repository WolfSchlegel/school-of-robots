#include "direction.h"

int my_analogRead(int);
void my_delay(int);

void my_println(String);
void my_setup();

// void runLeftMotor(Direction);
// void runRightMotor(Direction);
//
// void setLeftSpeed(int);
// void setRightSpeed(int);

void moveForwards(int);
void moveBackwards(int);
void rotateClockwise(int);
void rotateCounterClockwise(int);
void stop(int);
