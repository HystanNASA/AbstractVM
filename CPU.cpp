#include "CPU.hpp"

CPU::CPU(void) : stackPointer(0), programPointer(0)
{
	stack.reserve(SIZE_OF_STACK);
}


CPU::CPU(std::string filename) : CPU()
{

}


CPU::~CPU(void) {}


void CPU::run(void)
{
	while ()
	{

	}
}