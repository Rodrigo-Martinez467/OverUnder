#include "vex.h"

using namespace vex;
using namespace std;

Config config;
canvas Canvas;

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

string getDescription(Config config) {
  switch (config) {
    case TOP_LEFT: return "Top Left";
    case TOP_RIGHT: return "Top Right";
    case BOTTOM_LEFT: return "Bottom Left";
    case BOTTOM_RIGHT: return "Bottom RIght";
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

// Autonomouses / autonomi / autons or something
void topLeftOrBottomRight() {
  Drivetrain.driveFor(5, inches);
  
  Drivetrain.turnFor(-60, degrees);
  Drivetrain.driveFor(15, inches);

  Drivetrain.turnFor(17, degrees);
  Drivetrain.driveFor(50, inches);
}

void topRightOrBottomLeft() {
  Drivetrain.turnFor(55, degrees);
  Drivetrain.driveFor(30, inches);
  
  Drivetrain.turnFor(-120, degrees);
  Drivetrain.driveFor(20, inches);
}

void preAutonomous(void) {
  config = TOP_LEFT;

  Drivetrain.setDriveVelocity(40.0, percent);
  Intake.setVelocity(80.0, percent);
  
  // actions to do when the program starts
  Brain.Screen.clearScreen();
  
  Canvas = canvas();

  screenButton switchAutonButton = screenButton(60, 60, 120, blue, switchAuton_cb, text("Switch Auton", 0, 0, mono40, white));

  text description = text(getDescription(config), 0, 130, mono40, white, "desc");

  Canvas.addElements( switchAutonButton, description );

  screenPressed_cb();

  Brain.Screen.pressed(screenPressed_cb);
}

void autonomous(void) {
  Brain.Screen.clearScreen();
  // place automonous code here
  playAuton(config);
}