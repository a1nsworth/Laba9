#pragma once

#include <fstream>
#include <string>

class Task
{
private:
	std::string path_file_;
	std::string options_;

public:
	explicit Task(const std::string& path_file, const std::string& options);

	explicit Task(const Task& other);

	Task();

	std::string GetOptions() const;

	void SetOptions(const std::string& options);

	std::string GetPathFile() const;

	void SetPathFile(const std::string& path_file);

	bool IsCorrectPathFile(const std::string& path_file) const;
};
