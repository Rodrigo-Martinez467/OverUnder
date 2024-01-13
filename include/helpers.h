#ifndef HELPERS_H
#define HELPERS_H

#include "vex_device.h"
#include "vex_color.h"
#include <array>

using namespace vex;
using namespace std;

void preAutonomous();
void autonomous(void);
void userControl(void);
void programmingSkills();

void topLeftOrBottomRight();
void topRightOrBottomLeft();

void tryCloseWings();
void tryOpenWings();

const int deadband(45);

// Assuming blue is on the left and red is on the right
enum Config {
    TOP_LEFT_BOTTOM_RIGHT,
    TOP_RIGHT_BOTTOM_LEFT
};

#endif