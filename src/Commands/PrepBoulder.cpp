#include "PrepBoulder.h"
#include "Subsystems/Shooter.h"

PrepBoulder::PrepBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
	SetTimeout(0.1);
}

// Called just before this Command runs the first time
void PrepBoulder::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PrepBoulder::Execute()
{
	shooter->Maintain();
	shooter->Prep();
}

// Make this return true when this Command no longer needs to run execute()
bool PrepBoulder::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void PrepBoulder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepBoulder::Interrupted()
{

}
