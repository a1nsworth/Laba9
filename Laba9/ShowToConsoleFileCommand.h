#pragma once

#include <fstream>
#include <iostream>

#include "Command.h"

class ShowToConsoleFileCommand : public Command
{
private:
	inline const static std::string name_ = "show";

public:
	explicit ShowToConsoleFileCommand(const Task& instruction);

	ShowToConsoleFileCommand();

	std::string GetName() const noexcept override;

	void Execute() const override;

	bool IsCorrectName(const std::string& name) const noexcept override;

	Command* Create(const Task& task) override;
};
