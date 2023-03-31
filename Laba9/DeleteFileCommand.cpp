#include "DeleteFileCommand.h"


DeleteFileCommand::DeleteFileCommand(const Task& instruction): Command(instruction)
{
}

DeleteFileCommand::DeleteFileCommand() = default;

void DeleteFileCommand::Execute() const
{
	std::remove(task_.GetPathFile().c_str());
}

std::string DeleteFileCommand::GetName() const noexcept
{
	return name_;
}

bool DeleteFileCommand::IsCorrectName(const std::string& name) const noexcept
{
	return name == name_;
}

Command* DeleteFileCommand::Create(const Task& task)
{
	return new DeleteFileCommand(task);
}
