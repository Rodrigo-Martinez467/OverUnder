#include "vex.h"
using namespace vex;

int calcDeadband(int value) {
	return abs(value) < deadband ? 0 : value;
}

void toggleWings() {
	Wings.set( !Wings.value() );
}

void userControl(void) {
  	Drivetrain.setDriveVelocity(80.0, percent);
  	Brain.Screen.clearScreen();

	Controller.ButtonA.pressed(toggleWings);
  
  	// place driver control in this while loop
	while (true) {
		const int leftRight = calcDeadband(Controller.Axis1.value());
		const int fwdRev = calcDeadband(Controller.Axis3.value());
		
		LeftWheels.spin(fwd, fwdRev - leftRight, percent);
		RightWheels.spin(fwd, fwdRev + leftRight, percent);

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

		if (Controller.ButtonX.pressing())
			Catapult.spin(fwd);
		else
			Catapult.stop();
  	}
}