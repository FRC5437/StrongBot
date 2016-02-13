#ifndef RotateToAngle_H
#define RotateToAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateToAngle: public CommandBase
{
public:
	RotateToAngle(int degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
