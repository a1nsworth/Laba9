#include "ContainerTypesCommands.h"

ContainerTypesCommands::ContainerTypesCommands(const std::vector<Command*>& commands)
{
	for (const auto command : commands)
	{
		Add(command);
	}
}

std::vector<Command*> ContainerTypesCommands::GetCommands() const
{
	return commands_;
}

void ContainerTypesCommands::SetCommands(const std::vector<Command*>& commands)
{
	commands_ = commands;
}

void ContainerTypesCommands::Add(Command* command)
{
	commands_.push_back(command);
}

Command* ContainerTypesCommands::CreateCommand(const std::string& name) const
{
	for (const auto command : commands_)
	{
		if (command->IsCorrectName(name))
		{
			return command->Create(Task());
		}
	}
	return nullptr;
}

Command* ContainerTypesCommands::CreateCommand(const std::string& name, const Task& task) const
{
	for (const auto command : commands_)
	{
		if (command->IsCorrectName(name))
		{
			return command->Create(task);
		}
	}
	return nullptr;
}
