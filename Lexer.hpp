#ifndef PARSER_HPP
#define PARSER_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>

#include "IOperand.hpp"

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
	const unsigned bufferSize = 128;
	std::ifstream readFile;

	Instruction instruction;

	std::string instructionInStringForm;
	unsigned int lineNumber;

	LexerMessage internalMessage;

public:
	Lexer(void);
	Lexer(std::string&);
	~Lexer(void);

	LexerMessage  findInstruction(void);
	LexerMessage  findInstruction(std::string&);
	Instruction	  getInstruction(void);
	unsigned int  getLine(void) const;
	std::string   translateMessage();
	LexerMessage  openFile(std::string const &);

private:
	void getFilename(std::string&);
	void readLine(void);
	void parse(void);
	InstructionType instructionToString(std::string const &) const;
	eOperandType operandToString(std::string const &);
};


#endif