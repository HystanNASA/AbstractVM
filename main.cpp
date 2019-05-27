#include <cassert>

#include "CPU.hpp"

int main(int argc, char* argv[])
{
	assert(argc > 2 && argv[1] == "-f");

	CPU cpu(argv[2]);
	cpu.run();

	return 0;
}