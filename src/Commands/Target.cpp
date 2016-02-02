#include "Target.h"
#include "globals.h"
Target::Target()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(targeting);
}
std::shared_ptr<NetworkTable> grip;
extern double target_x;
// Called just before this Command runs the first time
void Target::Initialize()
{
	grip = NetworkTable::GetTable("GRIP");
}

// Called repeatedly when this Command is scheduled to run
void Target::Execute()
{
	auto areas = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
				 xs = grip->GetNumberArray("myContoursReport/centerX", llvm::ArrayRef<double>());

		double targetArea = -1.0, targetX = 0.0;
		for (uint i = 0; i < areas.size(); i++) {
			if (areas[i] > targetArea) {
				targetArea = areas[i];
				targetX = xs[i];
			}
		}

		if (targetArea < 0.0) {
				return;
		}

	    targeting->SetTarget(targetX);

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
