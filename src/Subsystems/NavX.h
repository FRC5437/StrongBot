#ifndef NavX_H
#define NavX_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "AHRS.h"

class NavX: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	NavX();
	AHRS* ahrs;
	void InitDefaultCommand();
	void YawZero();
	int YawGet360();
	double PitchGet();
	double XDisplace();
};

#endif
