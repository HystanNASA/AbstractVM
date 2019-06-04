#ifndef CPU_HPP
#define CPU_HPP


#include <iostream>
#include <cstdlib>

#include "IOperand.hpp"
#include "eOperand.hpp"
#include "Lexer.hpp"
#include "Factory.hpp"


#define PRINT_ERROR_MESSAGE(str) std::cout << str << std::endl;

const unsigned SIZE_OF_STACK = 15;


enum class ProgramMode
{
	FromStandardInputMode = 0,
	FromFileMode
};


class CPU
{
private:
	std::vector<IOperand const *> stack;
	std::vector<std::string>	  commands;

	Factory factory;
	Lexer lexer;

public:
	CPU(void);
	CPU(std::string);
	~CPU(void);

	void run(void);
	void readInput(void);

private:
	bool doInstruction(Instruction const &, const unsigned);

	void push(eOperandType, std::string const &, const unsigned);
	void pop(const unsigned);
	void dump(const unsigned);
	void assert(eOperandType, std::string const &, const unsigned);
	void add(const unsigned);
	void sub(const unsigned);
	void mul(const unsigned);
	void div(const unsigned);
	void mod(const unsigned);
	void print(const unsigned);
	void exit(void) const;

};


#endif