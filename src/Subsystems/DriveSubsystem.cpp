#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/DriveRobot.h"

DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem")
{
	CANTalon *left_motor = new CANTalon(1);
	CANTalon *right_motor = new CANTalon(2);
	CANTalon *left_slave = new CANTalon(3);
	left_slave->SetControlMode(CANSpeedController::kFollower);
	left_slave->Set(1);
	CANTalon *right_slave = new CANTalon(4);
	right_slave->SetControlMode(CANSpeedController::kFollower);
	right_slave->Set(2);
	myDrive = new RobotDrive(left_motor,right_motor);
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

void DriveSubsystem::Drive(Joystick* joy) {
	Drive(-joy->GetRawAxis(1), -joy->GetRawAxis(5));
}
