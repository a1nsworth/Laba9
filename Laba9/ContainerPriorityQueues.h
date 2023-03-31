#pragma once

#include <string>
#include <vector>

#include "PriorityQueue.h"
#include "ContainerTypesCommands.h"

class ContainerPriorityQueues
{
private:
	std::vector<std::pair<std::vector<std::string>, PriorityQueue*>> priority_queues_;
	ContainerTypesCommands types_commands_;

public:
	ContainerPriorityQueues(const ContainerTypesCommands& container_types_commands);

	std::vector<std::pair<std::vector<std::string>, PriorityQueue*>> GetPriorityQueues() const;

	std::pair<std::vector<std::string>, PriorityQueue*>& GetPair(size_t position);

	void AddPair(const std::pair<std::vector<std::string>, PriorityQueue*>& pair);

	void AddToPriorityQueue(const unsigned long long time, const std::string& name, const Task& task);

	void Remove(size_t i);

	void Merge(size_t a, size_t b);
};
