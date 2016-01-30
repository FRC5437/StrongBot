#ifndef RobotTurnRight_H
#define RobotTurnRight_H

#include "../CommandBase.h"
#include "WPILib.h"

class RobotTurnRight: public CommandBase
{
public:
	RobotTurnRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
