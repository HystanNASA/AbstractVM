#include "Lexer.hpp"

Lexer::Lexer(void) : lineNumber(0), internalMessage(LexerMessage::noError)
{
	instructionInStringForm.reserve(bufferSize);
}


Lexer::Lexer(std::string& filename) : Lexer()
{
	readFile.open(filename);
}


Lexer::~Lexer(void) {}


void Lexer::getFilename(std::string& filename)
{
	readFile.open(filename);

	if (!readFile.is_open())
		internalMessage = LexerMessage::badFile;
}


unsigned int Lexer::getLine(void) const { return lineNumber; }


Instruction Lexer::getInstruction(void)
{
	return instruction;
}


void Lexer::readLine(void)
{
	if (!readFile.is_open())
	{
		internalMessage = LexerMessage::badFile;
		return;
	}

	for(; !readFile.eof(); ++lineNumber)
	{
		std::getline(readFile, instructionInStringForm);

		if (instructionInStringForm == ";;" || instructionInStringForm[0] != ';' && instructionInStringForm != "")
			break;
	}

	if (readFile.eof())
		internalMessage = LexerMessage::eof;
}


InstructionType Lexer::instructionToString(std::string const & instr) const
{
	if (instr == "push")
		return InstructionType::push;
	else if (instr == "pop")
		return InstructionType::pop;
	else if (instr == "dump")
		return InstructionType::dump;
	else if (instr == "assert")
		return InstructionType::assert;
	else if (instr == "add")
		return InstructionType::add;
	else if (instr == "sub")
		return InstructionType::sub;
	else if (instr == "mul")
		return InstructionType::mul;
	else if (instr == "div")
		return InstructionType::div;
	else if (instr == "mod")
		return InstructionType::mod;
	else if (instr == "print")
		return InstructionType::print;
	else if (instr == "exit")
		return InstructionType::exit;
	else
		return InstructionType::error;
}


eOperandType Lexer::operandToString(std::string const & operand)
{
	if (operand == "int8")
		return eOperandType::Int8;
	else if (operand == "int16")
		return eOperandType::Int16;
	else if (operand == "int32")
		return eOperandType::Int32;
	else if (operand == "float")
		return eOperandType::Float;
	else if (operand == "double")
		return eOperandType::Double;
	else
	{
		internalMessage = LexerMessage::NAI;
		return eOperandType::Double;
	}
}


void Lexer::parse(void)
{
	const std::regex commandsWithoutArgs("^(pop|dump|add|sub|mul|div|mod|print|exit|;;|;)$");
	const std::regex commandsWithArgsInt("^(push|assert) (int8|int16|int32)\\(([\\-]?[0-9]+)\\)$");
	const std::regex commandsWithArgsFloatDouble("^(push|assert) (float|double)\\(([\\-]?[0-9]+\\.[0-9]+)\\)$");
	const std::regex emptyLine("^\\s*$");
	std::smatch		 result;

	if (std::regex_match(instructionInStringForm, result, commandsWithoutArgs))
	{
		instruction.instructionType = instructionToString(result[1]);
	}
	else if (std::regex_match(instructionInStringForm, result, commandsWithArgsInt))
	{
		instruction.instructionType = instructionToString(result[1]);
		instruction.operandType = operandToString(result[2]);
		instruction.value = result[3].str();
	}
	else if (std::regex_match(instructionInStringForm, result, commandsWithArgsFloatDouble))
	{
		instruction.instructionType = instructionToString(result[1]);
		instruction.operandType = operandToString(result[2]);
		instruction.value = result[3].str();
	}
	else if (std::regex_match(instructionInStringForm, result, emptyLine))
	{
		instruction.instructionType = instructionToString(result[0]);
	}
	else
		internalMessage = LexerMessage::NAI;
}


LexerMessage Lexer::findInstruction(void)
{
	readLine();

	if (internalMessage != LexerMessage::noError)
		return internalMessage;

	parse();

	return internalMessage;
}


LexerMessage Lexer::findInstruction(std::string& command)
{
	instructionInStringForm = command;

	parse();

	return internalMessage;
}


std::string Lexer::translateMessage()
{
	if (internalMessage == LexerMessage::noError)
		return std::string("No Error");
	else if (internalMessage == LexerMessage::badFile)
		return std::string("Bad File");
	else if (internalMessage == LexerMessage::eof)
		return std::string("End Of File");
	else if (internalMessage == LexerMessage::NAI)
		return std::string("Not An Instruction");
	else
		return std::string("Unknown Error");
}


LexerMessage Lexer::openFile(std::string const & filename)
{
	readFile.open(filename);

	if (!readFile.is_open())
	{
		internalMessage = LexerMessage::badFile;
		return internalMessage;
	}
		return LexerMessage::noError;
}