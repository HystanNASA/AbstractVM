#include "Factory.hpp"

Factory::Factory(void)
{
	functions.push_back(&Factory::createInt8);
	functions.push_back(&Factory::createInt16);
	functions.push_back(&Factory::createInt32);
	functions.push_back(&Factory::createFloat);
	functions.push_back(&Factory::createDouble);
}


Factory::Factory(Factory const &src)
{
	*this = src;
}


Factory::~Factory(void) {}


Factory & Factory::operator=(Factory const &rhs)
{
	if (this != &rhs)
		this->functions = rhs.functions;

	return *this;
}


IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const
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
	
		return (new eOperand<int8_t>(static_cast<int8_t>(num)));
	}
	catch (const std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}


IOperand const * Factory::createInt16(std::string const & value) const
{
	try
	{
		int64_t num = std::stoll(value);

		if (num > std::numeric_limits<int16_t>::max())
			throw std::overflow_error("Overflow");
		else if (num < std::numeric_limits<int16_t>::min())
			throw std::underflow_error("Underflow");

		return (new eOperand<int16_t>(static_cast<int16_t>(num)));
	}
	catch (const std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}


IOperand const * Factory::createInt32(std::string const & value) const
{
	try
	{
		int64_t num = std::stoll(value);

		if (num > INT32_MAX)
			throw std::overflow_error("Overflow");
		else if (num < -INT32_MAX)
			throw std::underflow_error("Underflow");

		return (new eOperand<int32_t>(static_cast<int32_t>(num)));
	}
	catch (const std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}


IOperand const * Factory::createFloat(std::string const & value) const
{
	try
	{
		float num = std::stof(value);

		if (num > FLT_MAX)
			throw std::overflow_error("Overflow");
		else if (num < -FLT_MAX)
			throw std::underflow_error("Underflow");

		return (new eOperand<float>(static_cast<float>(num)));
	}
	catch (const std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}


IOperand const * Factory::createDouble(std::string const & value) const
{
	try
	{
		double num = std::stod(value);

		if (num > DBL_MAX)
			throw std::overflow_error("Overflow");
		else if (num < -DBL_MAX)
			throw std::underflow_error("Underflow");

		return (new eOperand<double>(static_cast<double>(num)));
	}
	catch (const std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 0;
	}
}