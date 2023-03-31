#include "ExitCommand.h"

ExitCommand::ExitCommand(const Task& instruction): Command(instruction)
{
}

void ExitCommand::Execute() const
{
	exit(0);
}
