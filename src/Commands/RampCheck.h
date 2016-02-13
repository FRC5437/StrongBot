#ifndef RampCheck_H
#define RampCheck_H

#include "../CommandBase.h"
#include "WPILib.h"

class RampCheck: public CommandBase
{
public:
	RampCheck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
