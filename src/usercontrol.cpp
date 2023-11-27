#include "vex.h"
using namespace vex;

void userControl(void) {
  Drivetrain.setDriveVelocity(80.0, percent);
  Brain.Screen.clearScreen();
  
  // place driver control in this while loop
  while (true) {
    LeftWheels.spin(fwd, Controller.Axis3.value() + Controller.Axis1.value(), percent);
    RightWheels.spin(fwd, Controller.Axis3.value() - Controller.Axis1.value(), percent);

    if (Controller.ButtonR2.pressing()) {
      Intake.spin(fwd);
    } else if (Controller.ButtonL2.pressing()) {
      Intake.spin(fwd);
    } else {
      Intake.stop();
    }

    wait(20, msec);
  }
}