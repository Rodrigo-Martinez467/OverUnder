#include "vex.h"
using namespace vex;

int calcDeadband(int value) {
  return abs(value) < deadband ? 0 : value;
}

void userControl(void) {
  Drivetrain.setDriveVelocity(80.0, percent);
  Brain.Screen.clearScreen();
  
  // place driver control in this while loop
  while (true) {
    const int leftRight = calcDeadband(Controller.Axis1.value());
    const int fwdRev = calcDeadband(Controller.Axis3.value());
    
    LeftWheels.spin(fwd, fwdRev - leftRight, percent);
    RightWheels.spin(fwd, fwdRev + leftRight, percent);

    if (Controller.ButtonR2.pressing()) {
      Intake.spin(fwd);
    } else if (Controller.ButtonL2.pressing()) {
      Intake.spin(reverse);
    } else {
      Intake.stop();
    }

    wait(20, msec);
  }
}