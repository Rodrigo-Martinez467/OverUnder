/** ----------------------------------------------------------------------------
 * 
 * 		Project: Deez
 * 		Author: Rod and Arav and of course the one and ONLY Andrew
 * 		Created: 8/23/2023
 * 		Configuration:
 * 			Drivetrain - 4 Wheel Drive
 * 
 * 			Intake Motor - Port 5
 * 			Wings Pneumatic - Triport A
 * 
---------------------------------------------------------------------------- */

// Include the V5 Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace std;
using namespace vex;

int main() {
	// create competition instance
	competition Competition;

	// Set up callbacks for autonomous and driver control periods.
	Competition.autonomous(autonomous);
	Competition.drivercontrol(userControl);

	// Run the pre-autonomous function.
	preAutonomous();

	// Prevent main from exiting with an infinite loop.
	while (true)
		wait(100, msec);
}

void tryCloseWings() {
	if ( Wings.value() )
		Wings.close();
}

void tryOpenWings() {
	if ( !Wings.value() )
		Wings.open();
}