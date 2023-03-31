#include "CreateFileCommand.h"

CreateFileCommand::CreateFileCommand(const Task& instruction): Command(instruction)
{
}

CreateFileCommand::CreateFileCommand() = default;

void CreateFileCommand::Execute() const
{
	std::ofstream file(task_.GetPathFile());
	file.close();
}

std::string CreateFileCommand::GetName() const noexcept
{
	return name_;
}

bool CreateFileCommand::IsCorrectName(const std::string& name) const noexcept
{
	return name_ == name;
}

Command* CreateFileCommand::Create(const Task& task)
{
	return new CreateFileCommand(task);
}
