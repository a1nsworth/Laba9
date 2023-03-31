#pragma once

#include <fstream>
#include <vector>

#include "Command.h"

class DeleteStringFromFileCommand : public Command
{
private:
	inline const static std::string name_ = "add_string";

	int GetIndexStr() const;

	int GetCountLines() const;

	void WriteToFile(const std::vector<std::string>& lines) const;

public:
	DeleteStringFromFileCommand(const Task& instruction);

	DeleteStringFromFileCommand();

	std::string GetName() const noexcept override;

	void Execute() const override;

	bool IsCorrectName(const std::string& name) const noexcept override;

	Command* Create(const Task& task) override;
};
