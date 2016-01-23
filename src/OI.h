#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* joy;
public:
	OI();
	Joystick* GetJoystick();
};

#endif
