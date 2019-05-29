#ifndef PARSER_HPP
#define PARSER_HPP


#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>

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

struct Instruction
{
	InstructionType instructionType;
	eOperandType operandType;
	std::string value;
};

class Lexer
{
private:
	const std::streamsize bufferSize = 128;
	std::ifstream readFile;

	Instruction instruction;

	std::string lineFromFile;
	unsigned int lineNumber;

	LexerMessage internalMessage;

public:
	Lexer(void);
	Lexer(std::string&);
	~Lexer(void);

	LexerMessage  findInstruction(void);
	Instruction	  getInstruction(void);
	unsigned int  getLine(void);
	std::string translateMessage();

private:
	void getFilename(std::string&);
	void readLine(void);
	void parse(void);
	InstructionType instructionToString(std::string const &) const;
	eOperandType operandToString(std::string const &);
};


#endif