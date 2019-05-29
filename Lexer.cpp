#include "Lexer.hpp"

Lexer::Lexer(void) : lineNumber(0), internalMessage(LexerMessage::noError)
{
	lineFromFile.reserve(bufferSize);
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


unsigned int Lexer::getLine(void) { return lineNumber; }


Lexer::Instruction Lexer::getInstruction(void)
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
		readFile.getline(&lineFromFile[0], bufferSize);

		if (lineFromFile[0] != ';')
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
	if (operand == "int8()")
		return eOperandType::Int8;
	else if (operand == "int16()")
		return eOperandType::Int16;
	else if (operand == "int32()")
		return eOperandType::Int32;
	else if (operand == "float()")
		return eOperandType::Float;
	else if (operand == "double()")
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

	if (std::regex_match(lineFromFile, result, commandsWithoutArgs) || std::regex_match(lineFromFile, result, emptyLine))
	{
		instruction.instructionType = instructionToString(result[0]);
	}
	else if (std::regex_match(lineFromFile, result, commandsWithArgsInt))
	{
		instruction.instructionType = instructionToString(result[0]);
		instruction.operandType = operandToString(result[1]);
		instruction.value = result[2].str();
	}
	else if (std::regex_match(lineFromFile, result, commandsWithArgsFloatDouble))
	{
		instruction.instructionType = instructionToString(result[0]);
		instruction.operandType = operandToString(result[1]);
		instruction.value = result[2].str();
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

	if (internalMessage != LexerMessage::noError)
		return internalMessage;

	return internalMessage;
}