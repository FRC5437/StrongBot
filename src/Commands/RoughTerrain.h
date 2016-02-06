#ifndef RoughTerrain_H
#define RoughTerrain_H

#include "../CommandBase.h"
#include "WPILib.h"

class RoughTerrain: public CommandBase
{
public:
	RoughTerrain();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
