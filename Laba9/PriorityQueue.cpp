#include "PriorityQueue.h"

void PriorityQueue::Add(unsigned long long time, Command* command)
{
	queue_.push(std::pair{time, command});
}

void PriorityQueue::Pop()
{
	if (!queue_.empty())
		queue_.pop();
}

std::pair<unsigned long long, Command*> PriorityQueue::Top() const
{
	return queue_.top();
}

bool PriorityQueue::Empty() const
{
	return queue_.empty();
}

void PriorityQueue::Merge(const PriorityQueue& priority_queue)
{
	auto q = priority_queue;
	while (!q.Empty())
	{
		queue_.push(q.Top());
		q.Pop();
	}
}

PriorityQueue::PriorityQueue() = default;

PriorityQueue::PriorityQueue(const PriorityQueue& other): queue_(other.queue_)
{
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other)
{
	if (this == &other)
		return *this;
	queue_ = other.queue_;
	return *this;
}

PriorityQueue& PriorityQueue::operator=(PriorityQueue&& other) noexcept
{
	if (this == &other)
		return *this;
	queue_ = std::move(other.queue_);
	return *this;
}

void PriorityQueue::PerformTask(std::mutex& m)
{
	m.lock();
	if (!queue_.empty())
	{
		queue_.top().second->Execute();
			Pop();
	}
	m.unlock();
}

std::priority_queue<std::pair<unsigned long long, Command*>, std::vector<std::pair<unsigned long long, Command*>>,
                    decltype(&compare)> PriorityQueue::GetPriorityQueue() const
{
	return queue_;
}
