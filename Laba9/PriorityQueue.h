#pragma once

#include <mutex>
#include <queue>
#include <vector>
#include "Command.h"

inline bool compare(const std::pair<unsigned long long, Command*> p1, std::pair<unsigned long long, Command*> p2)
{
	return p1.first < p2.first;
}

class PriorityQueue
{
private:
	std::priority_queue<std::pair<unsigned long long, Command*>, std::vector<std::pair<unsigned long long, Command*>>,
	                    decltype(&compare)> queue_{compare};

public:
	PriorityQueue();

	PriorityQueue(const PriorityQueue& other);

	PriorityQueue& operator=(const PriorityQueue& other);

	PriorityQueue& operator=(PriorityQueue&& other) noexcept;

	void Add(unsigned long long time, Command* command);

	void Pop();

	std::pair<unsigned long long, Command*> Top() const;

	bool Empty() const;

	void PerformTask(std::mutex& m);

	std::priority_queue<std::pair<unsigned long long, Command*>, std::vector<std::pair<unsigned long long, Command*>>,
	                    decltype(&compare)> GetPriorityQueue() const;

	void Merge(const PriorityQueue& priority_queue);
};
