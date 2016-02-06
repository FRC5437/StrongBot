#include "RumbleTest.h"
#include "OI.h"

RumbleTest::RumbleTest()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	SetTimeout(2);
}

// Called just before this Command runs the first time
void RumbleTest::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RumbleTest::Execute()
{
	oi->Rumble();

}

// Make this return true when this Command no longer needs to run execute()
bool RumbleTest::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void RumbleTest::End()
{
	oi->StopRumble();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RumbleTest::Interrupted()
{

}
