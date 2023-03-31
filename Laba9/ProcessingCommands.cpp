#include "ProcessingCommands.h"

ProcessingCommands::ProcessingCommands(const ContainerTypesCommands& container_types_commands)
{
	container_priority_queues_ = new ContainerPriorityQueues(container_types_commands);
}

void ProcessingCommands::Merge(const size_t a, const size_t b) const
{
	container_priority_queues_->Merge(a, b);
}

void ProcessingCommands::Add(const unsigned long long time, const std::string& name, const Task& task) const
{
	container_priority_queues_->AddToPriorityQueue(time, name, task);
}

void ProcessingCommands::Process(std::mutex& m) const
{
	std::vector<std::thread> threads;

	for (auto& [_, q] : container_priority_queues_->GetPriorityQueues())
	{
		/*threads.emplace_back([&]
		{*/
			q->PerformTask(m);
		/*});*/
	}

	/*for (auto& thread : threads)
	{
		thread.join();
	}*/
}
