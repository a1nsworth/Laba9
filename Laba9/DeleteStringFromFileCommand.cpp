#include "DeleteStringFromFileCommand.h"

int DeleteStringFromFileCommand::GetIndexStr() const
{
	std::ifstream f(task_.GetPathFile());

	int i = 0;
	std::string line;
	while (f >> line)
	{
		if (line == task_.GetOptions())
		{
			f.close();
			return i;
		}
		i++;
	}

	f.close();
	return -1;
}

int DeleteStringFromFileCommand::GetCountLines() const
{
	std::ifstream f(task_.GetPathFile());

	int i = 0;
	std::string s;
	while (std::getline(f, s))
		i++;

	f.close();
	return i;
}

void DeleteStringFromFileCommand::WriteToFile(const std::vector<std::string>& lines) const
{
	std::ofstream f(task_.GetPathFile());

	for (const auto& line : lines)
	{
		f << line << '\n';
	}

	f.close();
}

DeleteStringFromFileCommand::DeleteStringFromFileCommand(const Task& instruction): Command(instruction)
{
}

DeleteStringFromFileCommand::DeleteStringFromFileCommand() = default;

std::string DeleteStringFromFileCommand::GetName() const noexcept
{
	return name_;
}

void DeleteStringFromFileCommand::Execute() const
{
	int i = GetIndexStr();

	if (i != -1)
	{
		std::fstream f(task_.GetPathFile());

		int n = GetCountLines() - 1;

		std::vector<std::string> lines;
		std::string s;
		for (int j = 0; j < n; ++j)
		{
			f >> s;
			if (j != i)
				lines.push_back(s);
		}

		WriteToFile(lines);

		f.close();
	}
}

bool DeleteStringFromFileCommand::IsCorrectName(const std::string& name) const noexcept
{
	return name_ == name;
}

Command* DeleteStringFromFileCommand::Create(const Task& task)
{
	return new DeleteStringFromFileCommand(task);
}
