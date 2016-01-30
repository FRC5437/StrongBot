#ifndef Target_H
#define Target_H

#include "../CommandBase.h"
#include "WPILib.h"
class Target: public CommandBase
{
public:
	Target();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
