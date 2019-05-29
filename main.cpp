#include "CPU.hpp"

int main(int argc, char* argv[])
{
	if (argc != 3 && argv[1] != "-f") exit(0);

	CPU cpu(argv[2]);
	cpu.run();

	return 0;
}