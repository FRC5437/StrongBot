#include "CommandBase.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/Shooter.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveSubsystem* CommandBase::drivesubsystem = NULL;
Shooter* CommandBase::shooter = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivesubsystem = new DriveSubsystem();
	shooter = new Shooter();
	oi = new OI();
}
