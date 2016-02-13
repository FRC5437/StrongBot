#include "RotateToAngle.h"
#include "CommandBase.h"

int degrees;
int initDegrees;
int turnDegrees;
bool rightDir;
int x;

RotateToAngle::RotateToAngle(int targetDegrees)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	Requires(navx);
	degrees = targetDegrees;
	initDegrees = 180;
}

// Called just before this Command runs the first time
void RotateToAngle::Initialize()
{
	navx->ahrs->ZeroYaw();
	Wait(0.08);
	initDegrees = (navx->YawGet360());
	turnDegrees = initDegrees+degrees;
	if (turnDegrees > initDegrees) {
		rightDir = true;
	}

	if (turnDegrees >= 360) {
		turnDegrees = turnDegrees % 360;
	}

	if (turnDegrees <= 0) {
		turnDegrees = turnDegrees % 360 + 360;
	}
	x = x+1;
}

// Called repeatedly when this Command is scheduled to run
void RotateToAngle::Execute()
{
	if (rightDir == true) {
		drivesubsystem->Drive(0.75, -0.75);
	} else if (rightDir == false) {
		drivesubsystem->Drive(-0.75, 0.75);
	} else {
		drivesubsystem->Drive(0.0, 0.0);
	}
	Wait(0.05);


}

// Make this return true when this Command no longer needs to run execute()
bool RotateToAngle::IsFinished()
{
	return ((navx->YawGet360()) <= (turnDegrees + 3) && (navx->YawGet360()) >= (turnDegrees - 3));
}

// Called once after isFinished returns true
void RotateToAngle::End()
{
	drivesubsystem->Drive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToAngle::Interrupted()
{
	navx->YawZero();
}
