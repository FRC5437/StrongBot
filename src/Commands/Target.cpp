#include "Target.h"
Target::Target()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(targeting);
}


// Called just before this Command runs the first time
void Target::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Target::Execute()
{
	targeting->SetTarget();
	CommandBase::targeting->Report();

}

// Make this return true when this Command no longer needs to run execute()
bool Target::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Target::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Target::Interrupted()
{

}
