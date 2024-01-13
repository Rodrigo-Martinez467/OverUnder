#include "vex.h"
using namespace vex;

int dir;
bool out;

int calcDeadband(int value) {
	return abs(value) < deadband ? 0 : value;
}

void toggleWings() {
	Wings.set( !Wings.value() );
}

void prepareCatapult() {
	Catapult.spin(fwd);
}

void stopCatapult() {
	Catapult.stop();
}

void invertControls() {
	dir *= -1;
}

void userControl(void) {
  	dir = 1;
	
	Drivetrain.setDriveVelocity(80.0, percent);
  	Brain.Screen.clearScreen();

	// Controller.ButtonA.pressed(toggleWings);
	Controller.ButtonX.pressed(spinCatapult);
	Controller.ButtonX.released(stopCatapult);
	// Controller.ButtonA.pressed(invertControls);
  
  	// place driver control in this while loop
	while (true) {
		const int leftRight = calcDeadband(Controller.Axis1.value()) * dir;
		const int fwdRev = calcDeadband(Controller.Axis3.value()) * dir;
		
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