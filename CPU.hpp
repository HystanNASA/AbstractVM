#ifndef CPU_HPP
#define CPU_HPP

#include <array>

#include "IOperand.hpp"
#include "eOperand.hpp"
#include "Factory.hpp"

const unsigned SIZE_OF_STACK = 15;

class CPU
{
private:
	std::vector<IOperand> stack;
	unsigned short	stackPointer;
	size_t			programPointer;

	Factory factory;

public:
	CPU();
	~CPU();

	void run(void);

	void push(eOperandType, std::string const &, const short line);
	void pop(const short line);
	void dump(const short line);
	void assert(eOperandType, std::string const &, const short line);
	void add(const short line);
	void sub(const short line);
	void mul(const short line);
	void div(const short line);
	void mod(const short line);
	void print(const short line);
	void exit(void) const;
};


#endif