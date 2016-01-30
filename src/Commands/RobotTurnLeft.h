#ifndef RobotTurnLeft_H
#define RobotTurnLeft_H

#include "../CommandBase.h"
#include "WPILib.h"

class RobotTurnLeft: public CommandBase
{
public:
	RobotTurnLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
