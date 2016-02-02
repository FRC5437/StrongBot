#include "LoadBoulder.h"

LoadBoulder::LoadBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
	SetTimeout(3);
}

// Called just before this Command runs the first time
void LoadBoulder::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LoadBoulder::Execute()
{
	shooter->Load();

}

// Make this return true when this Command no longer needs to run execute()
bool LoadBoulder::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void LoadBoulder::End()
{
	shooter->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoadBoulder::Interrupted()
{

}
