#ifndef FACTORY_HPP
#define FACTORY_HPP


#include <iostream>
#include <inttypes.h>
#include <stdexcept>

#include "IOperand.hpp"

class Factory
{
private:
	std::vector<IOperand const *(Factory::*)(std::string const &) const> functions;

public:
	Factory(void);
	~Factory(void);

	IOperand const * createOperand(eOperand, std::string const &) const;

private:

	IOperand const * createInt8(std::string const &) const;
	IOperand const * createInt16(std::string const &) const;
	IOperand const * createInt32(std::string const &) const;
	IOperand const * createFloat(std::string const &) const;
	IOperand const * createDouble(std::string const &) const;
};


#endif