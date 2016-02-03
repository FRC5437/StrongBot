#include "TargetAndShoot.h"
#include "Commands/RobotTurnLeft.h"
#include "Commands/RobotTurnRight.h"
#include "Commands/ShootBoulder.h"
#include "../CommandBase.h"


const double CENTER_X = 240.0;
const double TOLERANCE_X = 20.0;
double targetX;

TargetAndShoot::TargetAndShoot()
{

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	CommandBase::targeting->Report();

	if (targetX < CENTER_X - TOLERANCE_X) {
		AddSequential(new RobotTurnLeft());
	} else if (targetX > CENTER_X + TOLERANCE_X) {
		AddSequential(new RobotTurnRight());
	} else {
		//AddSequential(new ShootBoulder());
		return;
	}

}

