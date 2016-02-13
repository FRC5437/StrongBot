#include "NavX.h"
#include "../RobotMap.h"

NavX::NavX() : Subsystem("NavX") {
	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->ZeroYaw();
}

void NavX::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void NavX::YawZero() {
	ahrs->ZeroYaw();
}

int NavX::YawGet360() {
	int yaw = int (ahrs->GetYaw() + 180);
	return yaw;
}

double  NavX::PitchGet() {
	double pitch = ahrs->GetPitch();
	return pitch;
}

double NavX::XDisplace() {
	double displacement = ahrs->GetDisplacementX();
	return displacement;
}
