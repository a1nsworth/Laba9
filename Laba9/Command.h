#pragma once

#include <string>

#include "Task.h"

class Command
{
protected:
	Task task_;
	explicit Command(const Task& task);
	Command();

public:
	virtual ~Command();

	virtual void Execute() const = 0;

	virtual bool IsCorrectName(const std::string& name) const noexcept = 0;

	virtual Command* Create(const Task& task) = 0;

	virtual std::string GetName() const noexcept = 0;
};
