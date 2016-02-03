#include "Targeting.h"
#include "../RobotMap.h"
#include "Commands/Target.h"

std::shared_ptr<NetworkTable> grip;

Targeting::Targeting() : Subsystem("targeting") {
	targetx = 0.0;
	grip = NetworkTable::GetTable("GRIP");
}

void Targeting::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Target());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Targeting::SetTarget() {
   auto areas = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
   centerX = grip->GetNumberArray("myContoursReport/centerX", llvm::ArrayRef<double>());

   double targetArea = -1.0, temp = 0.0;
   for (uint i = 0; i < areas.size(); i++) {
	 if (areas[i] > targetArea) {
	    targetArea = areas[i];
		temp = centerX[i];
	 }
   }

   if (targetArea >= 0.0) {
      targetx = temp;
      SmartDashboard::PutNumber("chh - target", targetx);
   }
}

double Targeting::Report() {
	SmartDashboard::PutNumber("target", targetx);
	return targetx;

}
