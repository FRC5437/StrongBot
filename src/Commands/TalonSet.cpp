#include "TalonSet.h"
#include "Subsystems/DriveSubsystem.h"

TalonSet::TalonSet()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
}

// Called just before this Command runs the first time
void TalonSet::Initialize()
{
	SmartDashboard::PutString("test", "TalonSet initialized");
}

// Called repeatedly when this Command is scheduled to run
void TalonSet::Execute()
{
	drivesubsystem->Disabled();
}

// Make this return true when this Command no longer needs to run execute()
bool TalonSet::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TalonSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TalonSet::Interrupted()
{

}
