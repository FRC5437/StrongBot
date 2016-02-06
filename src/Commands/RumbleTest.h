#ifndef RumbleTest_H
#define RumbleTest_H

#include "../CommandBase.h"
#include "WPILib.h"

class RumbleTest: public CommandBase
{
public:
	RumbleTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
