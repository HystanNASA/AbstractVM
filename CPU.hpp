#ifndef CPU_HPP
#define CPU_HPP

#include <array>

#include "IOperand.hpp"
#include "eOperand.hpp"
#include "Factory.hpp"
#include "Lexer.hpp"

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
	void doInstruction(void);

	void push(eOperandType, std::string const &, const int line);
	void pop(const int line);
	void dump(const int line);
	void assert(eOperandType, std::string const &, const int line);
	void add(const int line);
	void sub(const int line);
	void mul(const int line);
	void div(const int line);
	void mod(const int line);
	void print(const int line);
	void exit(void) const;
};


#endif