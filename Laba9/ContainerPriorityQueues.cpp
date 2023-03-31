#include "ContainerPriorityQueues.h"

ContainerPriorityQueues::ContainerPriorityQueues(
	const ContainerTypesCommands& container_types_commands): types_commands_(container_types_commands)
{
	for (const auto command : container_types_commands.GetCommands())
	{
		priority_queues_.emplace_back(std::vector{command->GetName()}, new PriorityQueue());
	}
}

std::vector<std::pair<std::vector<std::string>, PriorityQueue*>> ContainerPriorityQueues::GetPriorityQueues() const
{
	return priority_queues_;
}

std::pair<std::vector<std::string>, PriorityQueue*>& ContainerPriorityQueues::GetPair(const size_t position)
{
	return priority_queues_.at(position);
}

void ContainerPriorityQueues::AddPair(const std::pair<std::vector<std::string>, PriorityQueue*>& pair)
{
	priority_queues_.push_back(pair);
}

void ContainerPriorityQueues::AddToPriorityQueue(const unsigned long long time,
	const std::string& name,
	const Task& task)
{
	const auto it = std::ranges::find_if(priority_queues_, [&name](const auto& pair)
	{
		return pair.first.end() != std::ranges::find_if(pair.first, [&name](const auto& s)
		{
			return s == name;
		});
	});

	if (it != priority_queues_.end())
	{
		it->second->Add(time, types_commands_.CreateCommand(name, task));
	}
}

void ContainerPriorityQueues::Remove(const size_t i)
{
	priority_queues_.erase(priority_queues_.begin() + i);
}

void ContainerPriorityQueues::Merge(const size_t a, const size_t b)
{
	std::vector<std::string> name_commands = GetPair(a).first;
	for (const auto& name : GetPair(b).first)
		name_commands.push_back(name);

	auto priority_queues = new PriorityQueue(*GetPair(a).second);

	priority_queues->Merge(*GetPair(b).second);

	Remove(a);
	Remove(b);

	AddPair(std::make_pair(name_commands, priority_queues));
}
