#ifndef CPU_HPP
#define CPU_HPP

#include <array>
#include <iostream>
#include <cstdlib>

#include "IOperand.hpp"
#include "eOperand.hpp"
#include "Factory.hpp"
#include "Lexer.hpp"


#define PRINT_ERROR_MESSAGE(str) std::cout << str << std::endl;

const unsigned SIZE_OF_STACK = 15;

class CPU
{
private:
	std::vector<IOperand> stack;
	unsigned short		  stackPointer;
	size_t				  programPointer;

	Factory factory;
	Lexer lexer;

public:
	CPU(void);
	CPU(std::string);
	~CPU(void);

	void run(void);
	bool doInstruction(Instruction const& const, const unsigned line);

	bool push(eOperandType, std::string const &, const unsigned line);
	bool pop(const unsigned line);
	bool dump(const unsigned line);
	bool assert(eOperandType, std::string const &, const unsigned line);
	bool add(const unsigned line);
	bool sub(const unsigned line);
	bool mul(const unsigned line);
	bool div(const unsigned line);
	bool mod(const unsigned line);
	bool print(const unsigned line);
	void exit(void) const;
};


#endif