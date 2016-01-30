#ifndef Targeting_H
#define Targeting_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Targeting: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Targeting();
	void InitDefaultCommand();
	void FindTarget();
};

#endif
