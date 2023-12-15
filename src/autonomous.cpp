#include "vex.h"

using namespace vex;
using namespace ui;
using namespace std;
using namespace Util;

Config config;
canvas Canvas;
bool skills;

void switchAuton_cb() {
	switch (config) {
		default:
		case TOP_LEFT_BOTTOM_RIGHT:
			config = TOP_RIGHT_BOTTOM_LEFT;
			break;
		case TOP_RIGHT_BOTTOM_LEFT: 
			config = TOP_LEFT_BOTTOM_RIGHT;
			break;
	}
}

void toggleSkills() {
	skills = !skills;
}

string getDescription(Config config) {
	switch (config) {
		case TOP_LEFT_BOTTOM_RIGHT: return "Top Left or Bottom Right";
		case TOP_RIGHT_BOTTOM_LEFT: return "Top Right or Bottom Left";
	}
}

void screenPressed() {
	Canvas.onScreenPressed( Brain.Screen.xPosition(), Brain.Screen.yPosition() );

	text* descriptionPtr = cast<paintable, text>(Canvas.get("desc"));
	descriptionPtr->setText(getDescription(config));

	screenButton* skillsButtonPtr = cast<paintable, screenButton>(Canvas.get("skills"));
	skillsButtonPtr->setColor(skills ? blue : green);
}

void playAuton(Config config) {
	switch (config) {
		default:
		case TOP_LEFT_BOTTOM_RIGHT:
			topLeftOrBottomRight();
			break;
		case TOP_RIGHT_BOTTOM_LEFT:
			topRightOrBottomLeft();
			break;
	}
}

void spinIntake() {
	Intake.spinFor(fwd, 500, msec);
}

void spinOuttake() {
	Intake.spinFor(reverse, 500, msec);
}

// Autons
/**
 * drive forward
*/
void topLeftOrBottomRight() {
	Drivetrain.setDriveVelocity(80.0, percent);
	Drivetrain.driveFor(45, inches, true);
}

void topRightOrBottomLeft() {
	Drivetrain.setDriveVelocity(80.0, percent);
	Drivetrain.driveFor(45, inches, true);
}

void newSkills() {
	tryCloseWings();

	wait(3, sec);

	while(true)
		Catapult.spin(fwd);
}

// Skills
void programmingSkills() {
	tryCloseWings();
	
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

void preAutonomous(void) {
	config = TOP_LEFT_BOTTOM_RIGHT;
	skills = false;

	// default motor speeds
	Drivetrain.setDriveVelocity(80.0, percent);
	Drivetrain.setTurnVelocity(50.0, percent);
	Intake.setVelocity(80.0, percent);

	// creating ui
	Brain.Screen.clearScreen();
	
	Canvas = canvas();

	screenButton switchAutonButton = screenButton( 60, 60, 120, blue, switchAuton_cb, text( "Switch Auton", 0, 0, mono40, blue ) );
	screenButton skillsButton = screenButton( 300, 60, 120, red, toggleSkills, text( "Toggle Skills", 0, 0, mono40, red ) );
	text description = text( getDescription(config), 90, 200, mono40, black );

	Canvas.setElement("auton", switchAutonButton);
	Canvas.setElement("skills", skillsButton);
	Canvas.setElement("desc", description);

	Canvas.paint();
	Brain.Screen.pressed(screenPressed);
}

void autonomous(void) {
	Brain.Screen.clearScreen();

	if (skills)
		programmingSkills();
	else
		playAuton(config);

	tryCloseWings();
}