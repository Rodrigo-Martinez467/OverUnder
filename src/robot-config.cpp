#include "vex.h"
using namespace vex;

brain Brain;
controller Controller = controller(primary);

motor BackLeftWheel = motor(PORT11, ratio18_1, true);
// motor MiddleLeftWheel = motor(PORT2, ratio18_1, true);
motor FrontLeftWheel = motor(PORT1, ratio18_1, true);

motor BackRightWheel = motor(PORT20, ratio18_1, false);
// motor MiddleRightWheel = motor(PORT10, ratio18_1, false);
motor FrontRightWheel = motor(PORT9, ratio18_1, false);

motor_group LeftWheels = motor_group(BackLeftWheel, FrontLeftWheel); 
motor_group RightWheels = motor_group(BackRightWheel, FrontRightWheel);

motor Intake = motor(PORT5, ratio18_1, false); 

drivetrain Drivetrain = drivetrain(LeftWheels, RightWheels, 320.0, 270.0, 240.0, mm, 1.0);