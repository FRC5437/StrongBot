#include "ShootBoulder.h"
bool fired = false;

ShootBoulder::ShootBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
}

// Called just before this Command runs the first time
void ShootBoulder::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShootBoulder::Execute()
{
	shooter->Fire();
	fired = true;

}

// Make this return true when this Command no longer needs to run execute()
bool ShootBoulder::IsFinished()
{
	return fired;
}

// Called once after isFinished returns true
void ShootBoulder::End()
{
	fired = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBoulder::Interrupted()
{

}