#include "vex.h"
using namespace vex;

brain Brain;
controller Controller = controller(primary);

motor BackLeftWheel = motor(PORT11, ratio18_1, false);
motor MiddleLeftWheel = motor(PORT2, ratio18_1, false);
motor FrontLeftWheel = motor(PORT1, ratio18_1, false);

motor BackRightWheel = motor(PORT20, ratio18_1, true);
motor MiddleRightWheel = motor(PORT10, ratio18_1, true);
motor FrontRightWheel = motor(PORT9, ratio18_1, true);

motor_group LeftWheels = motor_group(BackLeftWheel, MiddleLeftWheel, FrontLeftWheel); 
motor_group RightWheels = motor_group(BackRightWheel, MiddleRightWheel, FrontRightWheel);

motor Intake = motor(PORT5, ratio18_1, false);

drivetrain Drivetrain = drivetrain(LeftWheels, RightWheels, 320.0, 270.0, 152.0, mm, 1.0);