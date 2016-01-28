#include "OI.h"
#include "Commands/TargetAndShoot.h"

OI::OI()
{
	// Process operator interface input here.
	joy = new Joystick(0);
	b1 = new JoystickButton(joy, 1);

	b1->WhenPressed(new TargetAndShoot());
}

Joystick* OI::GetJoystick() {
	return joy;
}
