#include "Targeting.h"
#include "../RobotMap.h"
#include "Commands/Target.h"

extern double target_x;
Targeting::Targeting() : Subsystem("ExampleSubsystem") {

}

void Targeting::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Target());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Targeting::FindTarget() {

}
