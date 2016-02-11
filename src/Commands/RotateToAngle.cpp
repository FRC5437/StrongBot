#include "RotateToAngle.h"
#include "CommandBase.h"

double degrees, initDegrees;
int turnDegrees;
bool rightDir;

RotateToAngle::RotateToAngle(double targetDegrees)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	degrees = targetDegrees;
}

// Called just before this Command runs the first time
void RotateToAngle::Initialize()
{
	CommandBase::navx->ahrs->ZeroYaw();
	initDegrees = CommandBase::navx->ahrs->GetYaw();
	turnDegrees = initDegrees+degrees;
	if (turnDegrees > (initDegrees + 180)) {
		rightDir = true;
	}

	if (turnDegrees >= 180) {
		turnDegrees = (turnDegrees + 180) % 360 - 180;
	}

	if (turnDegrees <= -180) {
		turnDegrees = (turnDegrees - 180) % 360 + 180;
	}
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
	SmartDashboard::PutNumber("initdegrees", initDegrees);
	SmartDashboard::PutNumber("turndegrees", turnDegrees);
	SmartDashboard::PutNumber("yaw", CommandBase::navx->ahrs->GetYaw());


}

// Make this return true when this Command no longer needs to run execute()
bool RotateToAngle::IsFinished()
{
	return ((CommandBase::navx->ahrs->GetYaw()) <= (turnDegrees + 5.0) && (CommandBase::navx->ahrs->GetYaw()) >= (turnDegrees - 5.0));
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

}
