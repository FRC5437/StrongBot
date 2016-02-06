#ifndef TalonSet_H
#define TalonSet_H

#include "../CommandBase.h"
#include "WPILib.h"

class TalonSet: public CommandBase
{
public:
	TalonSet();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
