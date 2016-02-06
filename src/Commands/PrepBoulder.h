#ifndef PrepBoulder_H
#define PrepBoulder_H

#include "../CommandBase.h"
#include "WPILib.h"

class PrepBoulder: public CommandBase
{
public:
	PrepBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
