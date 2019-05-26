#include "Factory.hpp"

Factory::Factory(void)
{
	functions.push_back(&Factory::createInt8);
	functions.push_back(&Factory::createInt16);
	functions.push_back(&Factory::createInt32);
	functions.push_back(&Factory::createFloat);
	functions.push_back(&Factory::createDouble);
}


Factory::~Factory(void) {}


IOperand const * Factory::createOperand(eOperand type, std::string const & value) const
{
	return ((*this.*functions.at(type))(value));
}


IOperand const * Factory::createInt8(std::string const & value) const
{
	try
	{
		int64_t num = std::stoll(value);

		if (num > std::numeric_limits<int8_t>::max())
			throw std::overflow_error("Overflow");
		else if (num < std::numeric_limits<int8_t>::min())
			throw std::underflow_error("Underflow");
	
		return (new eOperand<>);
	}
	catch (const std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}