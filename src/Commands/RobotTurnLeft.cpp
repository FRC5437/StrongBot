#include "RobotTurnLeft.h"

RobotTurnLeft::RobotTurnLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	SetTimeout(0.1);
}

// Called just before this Command runs the first time
void RobotTurnLeft::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RobotTurnLeft::Execute()
{
	drivesubsystem->Drive(-0.5, 0.5);

}

// Make this return true when this Command no longer needs to run execute()
bool RobotTurnLeft::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void RobotTurnLeft::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotTurnLeft::Interrupted()
{

}
