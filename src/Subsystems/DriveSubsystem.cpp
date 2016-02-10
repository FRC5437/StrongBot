#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/DriveRobot.h"

CANTalon* left_motor;
CANTalon* right_motor;

DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem")
{
	left_motor = new CANTalon(1);
	left_motor->Set(0.0);
	right_motor = new CANTalon(2);
	right_motor->Set(0.0);
	CANTalon *left_slave = new CANTalon(3);
	left_slave->Set(0.0);
	left_slave->SetControlMode(CANSpeedController::kFollower);
	left_slave->Set(1);
	CANTalon *right_slave = new CANTalon(4);
	right_slave->Set(0.0);
	right_slave->SetControlMode(CANSpeedController::kFollower);
	right_slave->Set(2);
	myDrive = new RobotDrive(left_motor,right_motor);
	myDrive->SetSafetyEnabled(false);
}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveRobot());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSubsystem::Drive(double left, double right) {
	myDrive->TankDrive(left, right);
}

void DriveSubsystem::Drive(Joystick* joy1, Joystick* joy2) {
	Drive(-joy1->GetRawAxis(1), -joy2->GetRawAxis(1));
}

void DriveSubsystem::Disabled() {
	left_motor->ConfigNeutralMode(CANTalon::kNeutralMode_Jumper);
	right_motor->ConfigNeutralMode(CANTalon::kNeutralMode_Jumper);
}
