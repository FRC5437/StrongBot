#include "Shooter.h"
#include "../RobotMap.h"


CANTalon* left_wheel;
CANTalon* right_wheel;
DoubleSolenoid* ball_kicker;


Shooter::Shooter() :
		Subsystem("Shooter")
{
	left_wheel = new CANTalon(5);
	left_wheel->Set(0.0);
	right_wheel = new CANTalon(6);
	right_wheel->Set(0.0);
	ball_kicker = new DoubleSolenoid(0, 1);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Prep() {
	left_wheel->Set(-1);
	right_wheel->Set(1);
}

void Shooter::Fire() {
	ball_kicker->Set(DoubleSolenoid::kForward);
}

void Shooter::Maintain() {
	ball_kicker->Set(DoubleSolenoid::kOff);
}

void Shooter::Retract() {
	ball_kicker->Set(DoubleSolenoid::kReverse);
}

void Shooter::Load() {
	left_wheel->Set(0.5);
	right_wheel->Set(-0.5);
}

void Shooter::Stop() {
	left_wheel->Set(0.0);
	right_wheel->Set(0.0);
	ball_kicker->Set(DoubleSolenoid::kOff);
}
