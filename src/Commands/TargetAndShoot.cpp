#include "TargetAndShoot.h"

std::shared_ptr<NetworkTable> grip;

double targetX;

const double centerX = 120.0;
const double tolX = 20.0;
TargetAndShoot::TargetAndShoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	Requires(shooter);
	grip = NetworkTable::GetTable("GRIP");
}

// Called just before this Command runs the first time
void TargetAndShoot::Initialize()
{
	targetX = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void TargetAndShoot::Execute()
{
	auto areas = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
			Xcenter = grip->GetNumberArray("myContoursReport/centerX", llvm::ArrayRef<double>());

	double targetArea = -1.0, temp = 0.0;
	for (uint i = 0; i < areas.size(); i++) {
		if (areas[i] > targetArea) {
			targetArea = areas[i];
			temp = Xcenter[i];
		}
	}

	if (targetArea >= 0.0) {
		targetX = temp;
	}

	if (targetX < centerX - tolX) {
		drivesubsystem->Drive(-0.5, 0.5);
		Wait(0.05);
	}
	if (targetX > centerX + tolX) {
		drivesubsystem->Drive(0.5, -0.5);
		Wait(0.05);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TargetAndShoot::IsFinished()
{
	return ((targetX > centerX - tolX) && (targetX < centerX + tolX));
}

// Called once after isFinished returns true
void TargetAndShoot::End()
{
	drivesubsystem->Drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TargetAndShoot::Interrupted()
{

}
