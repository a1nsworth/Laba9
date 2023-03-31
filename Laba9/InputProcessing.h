#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <thread>

#include <boost/algorithm/string.hpp>

#include "ProcessingCommands.h"
#include "CreateFileCommand.h"
#include "AddStringToFileCommand.h"
#include "RenameFileCommand.h"
#include "DeleteFileCommand.h"
#include "ShowToConsoleFileCommand.h"
#include "DeleteStringFromFileCommand.h"

class InputProcessing
{
private:
	ProcessingCommands* processing_commands_;

public:
	InputProcessing()
	{
		processing_commands_ = new ProcessingCommands(ContainerTypesCommands(std::vector<Command*>{
			new CreateFileCommand(),
			new AddStringToFileCommand(),
			new RenameFileCommand(),
			new DeleteFileCommand(),
			new DeleteStringFromFileCommand(),
			new ShowToConsoleFileCommand()
		}));
	}

	void PrintInfo()
	{
		std::cout << "Instruction for print command : NameCommand PathFile Options" << '\n';
		std::cout << "If your command don`t contain: NameCommand or PathFile or Options, replace this on \'_\' " <<
			"\n\n";
	}

	void Run()
	{
		std::mutex m;

		PrintInfo();

		std::string s;
		std::vector<std::string> split_s;

		const auto start = clock();
		while (true)
		{
			std::getline(std::cin, s);
			split(split_s, s, boost::is_any_of(" "));
			std::string command = split_s[0];

			if (command == "EXIT")
			{
				return;
			}
			if (command == "MERGE")
			{
				processing_commands_->Merge(std::stoi(split_s[2]), std::stoi(split_s[3]));
			}
			else
			{
				processing_commands_->Add(clock() - start, command, Task(split_s[1], split_s[2]));
				processing_commands_->Process(std::ref(m));
			}
		}
	}
};
