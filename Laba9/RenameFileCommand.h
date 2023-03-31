#pragma once

#include <fstream>

#include "Command.h"

class RenameFileCommand : public Command
{
private:
	inline const static std::string name_ = "rename_file";

public:
	RenameFileCommand(const Task& instruction);

	RenameFileCommand();

	std::string GetName() const noexcept override;

	void Execute() const override;

	bool IsCorrectName(const std::string& name) const noexcept override;

	Command* Create(const Task& task) override;
};
