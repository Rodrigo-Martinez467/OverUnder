#include "vex.h"

using namespace vex;

void topRightOrBottomLeftSkills() {
	repeat( 4 ) {
		Drivetrain.setDriveVelocity(80.0, percent);
		wait(5, sec);

		repeat( 3 ) {
			Controller.rumble("-");
			wait(1, sec);
		}

		Drivetrain.driveFor(fwd, 45, inches, false);
		wait(0.5, sec);
		Drivetrain.setDriveVelocity(40.0, percent);
		waitUntil(Drivetrain.isDone());
		Drivetrain.driveFor(reverse, 45, inches);
	}
	Controller.rumble("...");

	Drivetrain.driveFor(40, inches);
	Drivetrain.turnFor(40, deg);
	Drivetrain.driveFor(20, inches);

}

void topLeftOrBottomRightSkills() {
	topRightOrBottomLeftSkills();
}

void programmingSkills(Config config) {
	switch (config) {
		default:
		case TOP_LEFT_BOTTOM_RIGHT:
			topLeftOrBottomRightSkills();
			break;
		case TOP_RIGHT_BOTTOM_LEFT:
			topRightOrBottomLeftSkills();
			break;
	}
}