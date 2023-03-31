#pragma once

#include "Command.h"

#include <fstream>

class CreateFileCommand : public Command
{
private:
	inline static const std::string name_ = "create_file";

public:
	explicit CreateFileCommand(const Task& instruction);

	CreateFileCommand();

	void Execute() const override;

	std::string GetName() const noexcept override;

	bool IsCorrectName(const std::string& name) const noexcept override;

	Command* Create(const Task& task) override;
};
