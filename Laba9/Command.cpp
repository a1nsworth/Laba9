#include "Command.h"

Command::~Command() = default;

Command::Command(const Task& task) : task_(task)
{
}

Command::Command() = default;
