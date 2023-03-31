#pragma once

#include "Command.h"

#include <fstream>

class DeleteFileCommand : public Command
{
private:
	inline static const std::string name_ = "delete_file";

public:
	explicit DeleteFileCommand(const Task& instruction);

	DeleteFileCommand();

	void Execute() const override;

	std::string GetName() const noexcept override;

	bool IsCorrectName(const std::string& name) const noexcept override;

	Command* Create(const Task& task) override;
};
