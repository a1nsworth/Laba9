#pragma once

#include <vector>
#include <algorithm>

#include "Command.h"


class ContainerTypesCommands
{
private:
	std::vector<Command*> commands_;

public:
	explicit ContainerTypesCommands(const std::vector<Command*>& commands);

	std::vector<Command*> GetCommands() const;

	void SetCommands(const std::vector<Command*>& commands);

	void Add(Command* command);

	Command* CreateCommand(const std::string& name) const;

	Command* CreateCommand(const std::string& name, const Task& task) const;
};
