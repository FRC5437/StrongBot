#include "RobotTurnRight.h"

RobotTurnRight::RobotTurnRight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	SetTimeout(0.1);
}

// Called just before this Command runs the first time
void RobotTurnRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RobotTurnRight::Execute()
{
	drivesubsystem->Drive(0.5,-0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool RobotTurnRight::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void RobotTurnRight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotTurnRight::Interrupted()
{

}
