#include "vex.h"
using namespace vex;

int driverDirection;

int calcDeadband(int value) {
	return abs(value) < deadband ? 0 : value;
}

// Makes the robot move backwards, making the back bar the front
void invertControls() {
	driverDirection *= -1;
}

void userControl(void) {
  	driverDirection = 1;
	
	Drivetrain.setDriveVelocity(80.0, percent);
  	Brain.Screen.clearScreen();
	Controller.ButtonA.pressed(invertControls);
  
  	// place driver control in this while loop
	while (true) {
		const int leftRight = calcDeadband(Controller.Axis1.value());
		const int fwdRev = calcDeadband(Controller.Axis2.value()) * driverDirection;
		
		LeftWheels.spin(fwd, fwdRev + leftRight, percent);
		RightWheels.spin(fwd, fwdRev - leftRight, percent);

		const bool inFwd = Controller.ButtonR2.pressing();
		const bool inRev = Controller.ButtonL2.pressing();

		if (inFwd && inRev)
			Intake.stop();
		else if (inFwd)
			Intake.spin(fwd);
		else if (inRev)
			Intake.spin(reverse);
		else
			Intake.stop();

		if (Controller.ButtonX.pressing())
			Catapult.spin(fwd);
		else
			Catapult.stop();

		wait(20, msec);
  	}
}