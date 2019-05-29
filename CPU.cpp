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
	Instruction instruction;
	LexerMessage lexerMessage;

	while (true)
	{
		lexerMessage = lexer.findInstruction();

		if (lexerMessage != LexerMessage::noError)
		{
			PRINT_ERROR_MESSAGE("Lexer Error: " + lexer.translateMessage())
			std::exit(1);
		}

		instruction = lexer.getInstruction();

		if (!doInstruction(instruction, lexer.getLine()))
		{
			PRINT_ERROR_MESSAGE("CPU Error: Cannot do the instruction.\nLine: " + lexer.getLine());
			std::exit(1);
		}
	}
}


bool CPU::doInstruction(Instruction const & instruction, const unsigned line)
{
	bool flag = false;

	if (instruction.instructionType == InstructionType::push)
		flag = push(instruction.operandType, instruction.value, line);
	else if (instruction.instructionType == InstructionType::pop)
		flag = pop(line);
	else if(instruction.instructionType == InstructionType::dump)
		flag = dump(line);
	else if (instruction.instructionType == InstructionType::assert)
		flag = assert(instruction.operandType, instruction.value, line);
	else if (instruction.instructionType == InstructionType::add)
		flag = add(line);
	else if (instruction.instructionType == InstructionType::sub)
		flag = sub(line);
	else if (instruction.instructionType == InstructionType::mul)
		flag = mul(line);
	else if (instruction.instructionType == InstructionType::div)
		flag = div(line);
	else if (instruction.instructionType == InstructionType::mod)
		flag = mod(line);
	else if (instruction.instructionType == InstructionType::print)
		flag = print(line);
	else if (instruction.instructionType == InstructionType::exit)
		exit();
	else
		return false;

	return flag;
}