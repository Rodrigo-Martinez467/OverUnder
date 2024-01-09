#include "vex.h"

using namespace vex;
using namespace ui;
using namespace std;
using namespace util;

Config config;
Canvas canvas;
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
	canvas.onScreenPressed( Brain.Screen.xPosition(), Brain.Screen.yPosition() );

	Text* desc = canvas.get<Text>("desc");
	desc->setText(getDescription(config));

	ScreenButton* skillsButton = canvas.get<ScreenButton>("skills");
	skillsButton->setColor(skills ? green : red);
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

	Catapult.spin(fwd);
}

// Skills
void programmingSkills() {
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

	tryCloseWings();

	// default motor speeds
	Drivetrain.setDriveVelocity(80.0, percent);
	Drivetrain.setTurnVelocity(50.0, percent);
	Intake.setVelocity(80.0, percent);
	Catapult.setVelocity(40.0, percent);

	// creating ui
	Brain.Screen.clearScreen();
	
	canvas = Canvas();

	ScreenButton switchAutonButton = ScreenButton( 60, 60, 120, 120, blue, switchAuton_cb, Text( "Switch Auton", 0, 0, mono40, blue ) );
	ScreenButton skillsButton = ScreenButton( 300, 60, 120, 120, red, toggleSkills, Text( "Toggle Skills", 0, 0, mono40, red ) );
	Text description = Text( getDescription(config), 90, 200, mono40, black );

	canvas.setElement("auton", switchAutonButton);
	canvas.setElement("skills", skillsButton);
	canvas.setElement("desc", description);

	canvas.paint();
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