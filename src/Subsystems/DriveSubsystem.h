#ifndef DriveSubsystem_H
#define DriveSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive* myDrive;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void Drive(double left, double right);
	void Drive(Joystick* joy);
};

#endif
