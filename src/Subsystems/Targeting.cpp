#include "Targeting.h"
#include "../RobotMap.h"
#include "Commands/Target.h"

Targeting::Targeting() : Subsystem("targeting") {
	targetx = 0;
}

void Targeting::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Target());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Targeting::SetTarget(double targetX) {
	targetx = targetX;
}

double Targeting::Report() {
	SmartDashboard::PutNumber("target", targetx);
	return targetx;

}
