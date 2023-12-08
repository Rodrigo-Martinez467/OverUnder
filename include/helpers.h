#ifndef HELPERS_H
#define HELPERS_H

#include "ui/paintable.hpp"
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

const int deadband(30);

// Assuming blue is on the left and red is on the right
enum Config {
    TOP_LEFT_BOTTOM_RIGHT,
    TOP_RIGHT_BOTTOM_LEFT
};

#endif