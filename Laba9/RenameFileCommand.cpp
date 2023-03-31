#include "RenameFileCommand.h"

RenameFileCommand::RenameFileCommand(const Task& instruction): Command(instruction)
{
}

RenameFileCommand::RenameFileCommand() = default;

std::string RenameFileCommand::GetName() const noexcept
{
	return name_;
}

void RenameFileCommand::Execute() const
{
	std::rename(task_.GetPathFile().c_str(), task_.GetOptions().c_str());
}

bool RenameFileCommand::IsCorrectName(const std::string& name) const noexcept
{
	return name_ == name;
}

Command* RenameFileCommand::Create(const Task& task)
{
	return new RenameFileCommand(task);
}
