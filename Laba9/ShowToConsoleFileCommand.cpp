#include "ShowToConsoleFileCommand.h"

ShowToConsoleFileCommand::ShowToConsoleFileCommand(const Task& instruction): Command(instruction)
{
}

ShowToConsoleFileCommand::ShowToConsoleFileCommand() = default;

std::string ShowToConsoleFileCommand::GetName() const noexcept
{
	return name_;
}

void ShowToConsoleFileCommand::Execute() const
{
	std::ifstream file(task_.GetPathFile());

	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << '\n';
	}

	file.close();
}

bool ShowToConsoleFileCommand::IsCorrectName(const std::string& name) const noexcept
{
	return name == name_;
}

Command* ShowToConsoleFileCommand::Create(const Task& task)
{
	return new ShowToConsoleFileCommand(task);
}
