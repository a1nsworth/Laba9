#pragma once
#include <fstream>

#include "Command.h"

class AddStringToFileCommand : public Command
{
private:
	inline static std::string name_ = "add_string";

public:
	AddStringToFileCommand(const Task& instruction);

	AddStringToFileCommand();

	void Execute() const override;

	std::string GetName() const noexcept override;

	bool IsCorrectName(const std::string& name) const noexcept override;

	Command* Create(const Task& task) override;
};
