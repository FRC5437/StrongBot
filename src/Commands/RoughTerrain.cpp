#include "RoughTerrain.h"

RoughTerrain::RoughTerrain()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	SetTimeout(2.5);
}

// Called just before this Command runs the first time
void RoughTerrain::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RoughTerrain::Execute()
{
	drivesubsystem->Drive(1.0, 1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool RoughTerrain::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void RoughTerrain::End()
{
	drivesubsystem->Drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RoughTerrain::Interrupted()
{

}
