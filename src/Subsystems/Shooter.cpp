#include "Shooter.h"
#include "../RobotMap.h"
CANTalon* left_wheel;
Shooter::Shooter() :
		Subsystem("Shooter")
{
	left_wheel = new CANTalon(5);
	CANTalon* right_wheel = new CANTalon(6);
	right_wheel->SetControlMode(CANSpeedController::kFollower);
	right_wheel->SetClosedLoopOutputDirection(true);
	right_wheel->Set(5);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Fire() {
	left_wheel->Set(-1.0);
}
