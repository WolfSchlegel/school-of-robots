#include "direction.h"
#include "speed.h"

int my_analogRead(int);
void my_delay(int);

void my_println(String);
void my_setup();

void accelerate();
void decelerate();
void moveForwards(int);
void moveBackwards(int);
void rotateClockwise(int);
void rotateCounterClockwise(int);
void stop(int);
void stop();
