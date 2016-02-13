#include "RampCheck.h"

bool finished;
RampCheck::RampCheck()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	Requires(navx);
}

// Called just before this Command runs the first time
void RampCheck::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RampCheck::Execute()
{
	/*bool upramp = false;
	if (upramp == false) {
		drivesubsystem->Drive(1.0, 1.0);
		Wait(1.0);
	}

	while(navx->PitchGet() > 0.2) {
		drivesubsystem->Drive(0.75, 0.75);
		upramp = true;
		Wait(0.05);
	}

	if (upramp == true) {
		drivesubsystem->Drive(0.75, 0.75);
		Wait(0.05);
	}

	 if (navx->PitchGet() < -0.2) {
		Wait(0.75);
		upramp = false;
		drivesubsystem->Drive(0.0, 0.0);
		finished = true;
	}*/

	drivesubsystem->Drive(0.75, 0.75);
	Wait(4.25);
	drivesubsystem->Drive(0.0, 0.0);
	finished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool RampCheck::IsFinished()
{
	return finished;
}

// Called once after isFinished returns true
void RampCheck::End()
{
	finished = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RampCheck::Interrupted()
{

}
