#include "TargetAndShoot.h"
#include "RobotMap.h"

const double CENTER_X = 160.0;
const double TOLERANCE_X = 20.0;
std::shared_ptr<NetworkTable> grip;
bool fired = false;
TargetAndShoot::TargetAndShoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
}

// Called just before this Command runs the first time
void TargetAndShoot::Initialize()
{
    grip = NetworkTable::GetTable("GRIP");
}

// Called repeatedly when this Command is scheduled to run
void TargetAndShoot::Execute()
{
	auto areas = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
			 xs = grip->GetNumberArray("myContoursReport/centerX", llvm::ArrayRef<double>());

	double targetArea = -1.0, targetX = 0.0;
	for (int i = 0; i < areas.size(); i++) {
		if (areas[i] > targetArea) {
			targetArea = areas[i];
			targetX = xs[i];
		}
	}

	if (targetArea < 0.0) {
			return;
	}

	if (targetX < CENTER_X - TOLERANCE_X) {
			drivesubsystem->Drive(0.5,-0.5);
	} else if (targetX > CENTER_X + TOLERANCE_X) {
			drivesubsystem->Drive(-0.5,0.5);
	} else {
		DriverStation::ReportError("FIRE");
		fired = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TargetAndShoot::IsFinished()
{
	return fired;
}

// Called once after isFinished returns true
void TargetAndShoot::End()
{
	fired = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TargetAndShoot::Interrupted()
{

}
