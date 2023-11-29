#ifndef HELPERS_H
#define HELPERS_H

#include "ui/paintable.hpp"
#include "vex_device.h"
#include "vex_color.h"
#include <array>

using namespace vex;
using namespace std;

extern bool skills;

void preAutonomous();
void autonomous(void);
void userControl(void);

void topLeftOrBottomRight();
void topRightOrBottomLeft();
void topLeftOrBottomRightSkills();
void topRightOrBottomLeftSkills();

void screenPressed_cb();

// Assuming blue is on the left and red is on the right
enum Config {
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
};

#endif