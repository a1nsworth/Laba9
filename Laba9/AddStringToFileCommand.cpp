#include "AddStringToFileCommand.h"

AddStringToFileCommand::AddStringToFileCommand(const Task& instruction): Command(instruction)
{
}

AddStringToFileCommand::AddStringToFileCommand() = default;

void AddStringToFileCommand::Execute() const
{
	std::ofstream f(task_.GetPathFile(), std::ios::app);
	f << task_.GetOptions();
	f.close();
}

std::string AddStringToFileCommand::GetName() const noexcept
{
	return name_;
}

bool AddStringToFileCommand::IsCorrectName(const std::string& name) const noexcept
{
	return name == name_;
}

Command* AddStringToFileCommand::Create(const Task& task)
{
	return new AddStringToFileCommand(task);
}
