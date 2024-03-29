#include "CompressorSubsystem.h"
#include "../RobotMap.h"

Compressor* compressor;

CompressorSubsystem::CompressorSubsystem() :
		Subsystem("Compressor")
{
	compressor = new Compressor(0);
	compressor->SetClosedLoopControl(true);
}

void CompressorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
