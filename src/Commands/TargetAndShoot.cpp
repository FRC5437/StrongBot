#include "TargetAndShoot.h"

double targetX;
bool fired = false;

const double centerX = 120.0;
const double tolX = 20.0;
TargetAndShoot::TargetAndShoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(targeting);
	Requires(drivesubsystem);
	Requires(shooter);
}

// Called just before this Command runs the first time
void TargetAndShoot::Initialize()
{
	targetX = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void TargetAndShoot::Execute()
{
	targetX = targeting->Report();
	if (targetX < centerX - tolX) {
		drivesubsystem->Drive(0.5, -0.5);
	} else if (targetX > centerX + tolX) {
		drivesubsystem->Drive(-0.5, 0.5);
	} else {
		fired = true;
		drivesubsystem->Drive(0.0, 0.0);
		shooter->Fire();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TargetAndShoot::IsFinished()
{
	return fired;
}

// Called once after isFinished returns true
void TargetAndShoot::End()
{
	fired = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TargetAndShoot::Interrupted()
{

}
