#ifndef PARSER_HPP
#define PARSER_HPP


#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "IOperand.hpp"
#include "CPU.hpp"

enum class InstructionType
{
	error = 0,
	push,
	pop,
	dump,
	assert,
	add,
	sub,
	mul,
	div,
	mod,
	print,
	exit
};

enum class LexerMessage
{
	noError = 0,
	NAI, // not an instruction
	badFile,
	eof
};

class Lexer
{
private:
	struct Instruction
	{
		InstructionType instructionType;
		eOperandType operandType;
		std::string value;
	};

	const std::streamsize bufferSize = 128;
	std::ifstream readFile;

	std::vector<std::string> tokens;

	Instruction instruction;

	std::string lineFromFile;
	unsigned int lineNumber;

	LexerMessage internalMessage;

public:
	Lexer(void);
	Lexer(std::string&);
	~Lexer(void);

	LexerMessage  tokenize(void);
	Instruction	  getInstruction(void);
	unsigned int  getLine(void);

private:
	void getFilename(std::string&);
	void readLine(void);
	void parse(void);
};


#endif