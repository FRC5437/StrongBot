#ifndef LoadBoulder_H
#define LoadBoulder_H

#include "../CommandBase.h"
#include "WPILib.h"

class LoadBoulder: public CommandBase
{
public:
	LoadBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
