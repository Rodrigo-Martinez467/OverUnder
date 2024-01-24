#include "vex.h"
using namespace vex;

bool catapultSpinning;

int calcDeadband(int value) {
	return abs(value) < deadband ? 0 : value;
}

void toggleCatapult() {
	catapultSpinning = !catapultSpinning;
	if (catapultSpinning) {
		Catapult.spin(fwd);
	}
	else {
		Catapult.stop();
	}
}

void userControl(void) {
  	catapultSpinning = false;
	
	Drivetrain.setDriveVelocity(80.0, percent);
  	Brain.Screen.clearScreen();

	Controller.ButtonX.pressed(toggleCatapult);
  
  	// place driver control in this while loop
	while (true) {
		const int leftRight = calcDeadband(Controller.Axis1.value());
		const int fwdRev = calcDeadband(Controller.Axis3.value());
		
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

		wait(20, msec);
  	}
}