#ifndef OI_H
#define OI_H

#include "WPILib.h"


class OI
{
private:
	Joystick* joy1;
	JoystickButton* b11;
	JoystickButton* b2;
	Joystick* joy2;
	JoystickButton* b21;
	//JoystickButton* b22;
	//JoystickButton* b23;
	Joystick* joy3;
	JoystickButton* b31;
	JoystickButton* b32;
	JoystickButton* b33;
	JoystickButton* b34;
public:
	OI();
	Joystick* GetJoystick1();
	Joystick* GetJoystick2();
	void Rumble();
	void StopRumble();
};

#endif
