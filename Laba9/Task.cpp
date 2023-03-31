#include "Task.h"

Task::Task(const std::string& path_file, const std::string& options): path_file_(path_file), options_(options)
{
}

Task::Task(const Task& other): path_file_(other.path_file_), options_(other.options_)
{
}

Task::Task() = default;

std::string Task::GetOptions() const
{
	return options_;
}

void Task::SetOptions(const std::string& options)
{
	options_ = options;
}

std::string Task::GetPathFile() const
{
	return path_file_;
}

void Task::SetPathFile(const std::string& path_file)
{
	path_file_ = path_file;
}

bool Task::IsCorrectPathFile(const std::string& path_file) const
{
	std::fstream f(path_file);
	const auto is_open = f.is_open();
	f.close();

	return is_open;
}