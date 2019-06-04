#include "CPU.hpp"


ProgramMode programMode;


int main(int argc, char* argv[])
{
	std::unique_ptr<CPU> cpu;

	if (argc == 1)
	{
		cpu = std::make_unique<CPU>();
		cpu->readInput();
	}
	else if (argc == 3 && argv[1] == "-f")
		cpu = std::make_unique<CPU>(argv[2]);
	else
	{
		PRINT_ERROR_MESSAGE("Error: Cannot recognize the program's arguments.")
		return 1;
	}

	cpu->run();
	
	return 0;
}