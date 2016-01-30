#include "OI.h"
#include "RobotMap.h"
#include "Commands/TargetAndShoot.h"
#include "Commands/Target.h"
#include "Commands/ShootBoulder.h"

OI::OI()
{
	// Process operator interface input here.
	joy1 = new Joystick(0);
	b11 = new JoystickButton(joy1, 1);
	b2 = new JoystickButton(joy1, 2);
	joy2 = new Joystick(1);
	b21 = new JoystickButton(joy2, 1);
	b22 = new JoystickButton(joy2, 2);

	b11->WhenPressed(new TargetAndShoot());
	b21->WhenPressed(new ShootBoulder());
	b22->WhenPressed(new Target());
	//b2->WhenPressed();
}

Joystick* OI::GetJoystick1() {
	return joy1;
}

Joystick* OI::GetJoystick2() {
	return joy2;
}
