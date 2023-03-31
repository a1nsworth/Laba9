#include <iostream>

#include "InputProcessing.h"

#include "Command.h"
#include "AddStringToFileCommand.h"

int main()
{
	const auto app = new InputProcessing();

	app->Run();

	return 0;
}
