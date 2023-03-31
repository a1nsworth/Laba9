#pragma once

#include "Command.h"

class ExitCommand : public Command
{
public:
	explicit ExitCommand(const Task& instruction);

	void Execute() const override;
};
