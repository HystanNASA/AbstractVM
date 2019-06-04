#include "CPU.hpp"

CPU::CPU(void)
{
	stack.reserve(SIZE_OF_STACK);
}


CPU::CPU(std::string filename) : CPU()
{
	if (lexer.openFile(filename) != LexerMessage::noError)
	{
		PRINT_ERROR_MESSAGE("Lexer Error: " + lexer.translateMessage())
		std::exit(1);
	}
}


CPU::~CPU(void) {}


void CPU::run(void)
{
	Instruction instruction;
	LexerMessage lexerMessage;

	unsigned indexOfCommand = 0;

	while (true)
	{
		if(commands.size() == 0)
			lexerMessage = lexer.findInstruction();
		else
		{
			if (indexOfCommand == commands.size())
				std::exit(0);

			lexerMessage = lexer.findInstruction(commands[indexOfCommand]);
			++indexOfCommand;
		}

		if (lexerMessage == LexerMessage::eof)
			return;
		else if (lexerMessage != LexerMessage::noError)
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
	if (instruction.instructionType == InstructionType::push)
		push(instruction.operandType, instruction.value, line);
	else if (instruction.instructionType == InstructionType::pop)
		pop(line);
	else if (instruction.instructionType == InstructionType::dump)
		dump(line);
	else if (instruction.instructionType == InstructionType::assert)
		assert(instruction.operandType, instruction.value, line);
	else if (instruction.instructionType == InstructionType::add)
		add(line);
	else if (instruction.instructionType == InstructionType::sub)
		sub(line);
	else if (instruction.instructionType == InstructionType::mul)
		mul(line);
	else if (instruction.instructionType == InstructionType::div)
		div(line);
	else if (instruction.instructionType == InstructionType::mod)
		mod(line);
	else if (instruction.instructionType == InstructionType::print)
		print(line);
	else if (instruction.instructionType == InstructionType::exit)
		exit();
	else
		return false;

	return true;
}


void CPU::push(eOperandType oType, std::string const & value, const unsigned line)
{
	if (stack.size() + 1 >= SIZE_OF_STACK)
	{
		PRINT_ERROR_MESSAGE("Error: Stack overflow.\nLine: " + lexer.getLine())
		std::exit(1);
	}

	stack.push_back(factory.createOperand(oType, value));
}


void CPU::pop(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
		std::exit(1);
	}

	stack.pop_back();
}


void CPU::dump(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
		std::exit(1);
	}

	for (auto it : stack)
		std::cout << it->getStringValue() << std::endl;
}


void CPU::assert(eOperandType oType, std::string const & value, const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
		std::exit(1);
	}

	if (!(stack[stack.size() - 1]->getType() == oType && stack[stack.size() - 1]->getStringValue() == value))
	{
		PRINT_ERROR_MESSAGE("Error: Assert isn't true!\nLine: " + line)
		std::exit(1);
	}
	else
		std::cout << "true" << std::endl;
}


void CPU::add(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
		std::exit(1);
	} 
	else if(stack.size() < 2)
	{
		PRINT_ERROR_MESSAGE("Error: The stack is going to get underflowed!\nLine: " + line)
		std::exit(1);
	}

	IOperand const * a = stack[stack.size() - 1];
	IOperand const * b = stack[stack.size() - 2];
	
	stack.pop_back();
	stack.pop_back();

	stack.push_back(*a + *b);

	delete b;
	delete a;
}


void CPU::sub(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
			std::exit(1);
	}
	else if (stack.size() < 2)
	{
		PRINT_ERROR_MESSAGE("Error: The stack is going to get underflowed!\nLine: " + line)
			std::exit(1);
	}

	IOperand const * a = stack[stack.size() - 1];
	IOperand const * b = stack[stack.size() - 2];

	stack.pop_back();
	stack.pop_back();

	stack.push_back(*a - *b);
}


void CPU::mul(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
			std::exit(1);
	}
	else if (stack.size() < 2)
	{
		PRINT_ERROR_MESSAGE("Error: The stack is going to get underflowed!\nLine: " + line)
			std::exit(1);
	}

	IOperand const * a = stack[stack.size() - 1];
	IOperand const * b = stack[stack.size() - 2];

	stack.pop_back();
	stack.pop_back();

	stack.push_back(*a * *b);
}


void CPU::div(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
			std::exit(1);
	}
	else if (stack.size() < 2)
	{
		PRINT_ERROR_MESSAGE("Error: The stack is going to get underflowed!\nLine: " + line)
			std::exit(1);
	}

	IOperand const * a = stack[stack.size() - 1];
	IOperand const * b = stack[stack.size() - 2];

	stack.pop_back();
	stack.pop_back();

	stack.push_back(*a / *b);
}


void CPU::mod(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
			std::exit(1);
	}
	else if (stack.size() < 2)
	{
		PRINT_ERROR_MESSAGE("Error: The stack is going to get underflowed!\nLine: " + line)
			std::exit(1);
	}

	IOperand const * a = stack[stack.size() - 1];
	IOperand const * b = stack[stack.size() - 2];

	stack.pop_back();
	stack.pop_back();

	stack.push_back(*a % *b);
}


void CPU::print(const unsigned line)
{
	if (stack.empty())
	{
		PRINT_ERROR_MESSAGE("Error: The stack is empty!\nLine: " + line)
		std::exit(1);
	}

	std::cout << stack[stack.size() - 1]->getStringValue() << std::endl;
}


void CPU::readInput(void)
{
	bool		continueInput = true;
	std::string input;

	while (continueInput)
	{
		std::getline(std::cin, input);

		if(input == ";;")
			continueInput = false;
		else
			commands.push_back(input);
	}
}


void CPU::exit(void) const
{
	system("pause");
	std::exit(0);
}