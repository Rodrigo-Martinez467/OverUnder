#include "vex.h"

using namespace vex;
using namespace std;

Config config;
canvas Canvas;
bool skills;

void switchAuton_cb() {
  switch (config) {
    default:
    case TOP_LEFT:
      config = TOP_RIGHT;
      break;
    case TOP_RIGHT: 
      config = BOTTOM_LEFT;
      break;
    case BOTTOM_LEFT:
      config = BOTTOM_RIGHT;
      break;
    case BOTTOM_RIGHT:
      config = TOP_LEFT;
      break;
  }
}

void toggleSkills() {
  skills = !skills;
}

string getDescription(Config config) {
  switch (config) {
    case TOP_LEFT: return "Top Left";
    case TOP_RIGHT: return "Top Right";
    case BOTTOM_LEFT: return "Bottom Left";
    case BOTTOM_RIGHT: return "Bottom Right";
  };
}

void screenPressed_cb() {
  Canvas.onScreenPressed();

  for ( paintable element : Canvas.getElements() ) {
    if ( element.getType() != TEXT ) continue;

    text* description = static_cast<text*>( &element );
    if ( description->getRole() != "desc" ) continue;

    description->setText( getDescription( config ) );
  }
}

void playAuton(Config config) {
  switch (config) {
    default:
    case TOP_LEFT:
    case BOTTOM_RIGHT:
      topLeftOrBottomRight();
      break;
    case TOP_RIGHT:
    case BOTTOM_LEFT:
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
}

void topRightOrBottomLeft() {
}

// Skills
void programmingSkills() {
  for (int i = 0; i < 4; i++) {
    wait(8, sec);

    Drivetrain.driveFor(fwd, 45, inches);
    Drivetrain.driveFor(reverse, 45, inches);
  }
}

void preAutonomous(void) {
  config = TOP_LEFT;
  skills = false;

  // default motor speeds
  Drivetrain.setDriveVelocity(80.0, percent);
  Drivetrain.setTurnVelocity(50.0, percent);
  Intake.setVelocity(80.0, percent);
  
  // actions to do when the program starts
  Brain.Screen.clearScreen();
  
  Canvas = canvas();

  screenButton switchAutonButton = screenButton( 60, 60, 120, blue, switchAuton_cb, text( "Switch Auton", 0, 0, mono40, blue ) );
  screenButton skillsButton = screenButton( 120, 60, 120, red, toggleSkills, text( "Toggle Skills", 0, 180, mono40, red ) );
  text description = text( getDescription(config), 0, 130, mono40, black, "desc" );

  Canvas.addElements( switchAutonButton, description );

  screenPressed_cb();
  Brain.Screen.pressed(screenPressed_cb);
}

void autonomous(void) {
  Brain.Screen.clearScreen();
  // place automonous code here
  skills = true;
  if (skills)
    programmingSkills();
  else
    playAuton(TOP_LEFT /*config*/);
}