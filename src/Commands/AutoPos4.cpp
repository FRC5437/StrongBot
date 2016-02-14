#include "AutoPos4.h"
#include "RampCheck.h"
#include "PrepBoulder.h"
#include "RotateToAngle.h"
#include "ShootBoulder.h"
#include "Target.h"
#include "TargetAndShoot.h"

AutoPos4::AutoPos4()
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
	AddSequential(new RampCheck());
	//AddSequential(new RotateToAngle(-14));
	Wait(0.3);
	AddSequential(new PrepBoulder());
	AddSequential(new TargetAndShoot());
	Wait(0.5);
	AddSequential(new ShootBoulder());
}
