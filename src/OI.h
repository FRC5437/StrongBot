#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* joy;
	JoystickButton* b1;
public:
	OI();
	Joystick* GetJoystick();
};

#endif
