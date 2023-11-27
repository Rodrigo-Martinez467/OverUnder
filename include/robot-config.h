#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex_motor.h"
#include "vex_motorgroup.h"
#include "vex_controller.h"
#include "vex_drivetrain.h"

using namespace vex;

extern brain Brain;
extern controller Controller;

extern motor_group LeftWheels;
extern motor_group RightWheels;

extern motor Intake;

extern drivetrain Drivetrain;

void vexcodeInit(void);

#endif