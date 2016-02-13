#include "OI.h"
#include "RobotMap.h"
#include "Commands/TargetAndShoot.h"
#include "Commands/Target.h"
#include "Commands/ShootBoulder.h"
#include "Commands/LoadBoulder.h"
#include "Commands/PrepBoulder.h"
#include "Commands/RumbleTest.h"
#include "Commands/AutoPos4.h"
//#include "Commands/RotateToAngle.h"
//#include "Commands/RampCheck.h"

OI::OI()
{
	//Command* command;
	//command = new ShootBoulder();
	// Process operator interface input here.
	joy1 = new Joystick(0);
	b11 = new JoystickButton(joy1, 1);
	//b12 = new JoystickButton(joy1, 2);
	joy2 = new Joystick(1);
	b21 = new JoystickButton(joy2, 1);
	b22 = new JoystickButton(joy2, 2);
	//b23 = new JoystickButton(joy2, 3);
	joy3 = new Joystick(2);
	b31 = new JoystickButton(joy3, 1);
	b32 = new JoystickButton(joy3, 2);
	b33 = new JoystickButton(joy3, 3);
	b34 = new JoystickButton(joy3, 4);

	b11->WhenPressed(new TargetAndShoot());
	b21->WhenPressed(new AutoPos4());
	//b22->WhenPressed(new RampCheck());
	b31->WhenPressed(new PrepBoulder());
	b32->WhenPressed(new LoadBoulder());
	b33->WhenPressed(new ShootBoulder());
	b34->WhenPressed(new RumbleTest());
	//b2->WhenPressed();
	//double fire = joy3->GetRawAxis(3);
	/*if (fire > .5) {
		command->Start();
	}*/
}

Joystick* OI::GetJoystick1() {
	return joy1;
}

Joystick* OI::GetJoystick2() {
	return joy2;
}

void OI::Rumble() {
	joy3->SetRumble(Joystick::kLeftRumble, 1.0);
	joy3->SetRumble(Joystick::kRightRumble, 1.0);
}

void OI::StopRumble() {
	joy3->SetRumble(Joystick::kLeftRumble, 0.0);
	joy3->SetRumble(Joystick::kRightRumble, 0.0);
}
