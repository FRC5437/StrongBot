#ifndef TargetAndShoot_H
#define TargetAndShoot_H

#include "../CommandBase.h"
#include "WPILib.h"

class TargetAndShoot: public CommandBase
{
public:
	TargetAndShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
