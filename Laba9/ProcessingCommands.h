#pragma once

#include <map>
#include <thread>

#include "ContainerPriorityQueues.h"

class ProcessingCommands
{
private:
	// first - contain vector able command, second priority queue
	ContainerPriorityQueues* container_priority_queues_;

public:
	explicit ProcessingCommands(const ContainerTypesCommands& container_types_commands);

	void Merge(size_t a, size_t b) const;

	void Add(unsigned long long time, const std::string& name, const Task& task) const;

	void Process(std::mutex& m) const;
};
