#ifndef RotateToAngle_H
#define RotateToAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateToAngle: public CommandBase
{
public:
	RotateToAngle(double degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
