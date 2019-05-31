#ifndef FACTORY_HPP
#define FACTORY_HPP


#include <iostream>
#include <inttypes.h>
#include <stdexcept>
#include <vector>
#include <cfloat>

#include "eOperand.hpp"
#include "IOperand.hpp"

class Factory
{
private:
	std::vector<IOperand const *(Factory::*)(std::string const &) const> functions;

public:
	Factory(void);
	Factory(Factory const &src);
	~Factory(void);

	Factory &operator=(Factory const &rhs);

	IOperand const * createOperand(eOperandType, std::string const &) const;

private:
	IOperand const * createInt8(std::string const &) const;
	IOperand const * createInt16(std::string const &) const;
	IOperand const * createInt32(std::string const &) const;
	IOperand const * createFloat(std::string const &) const;
	IOperand const * createDouble(std::string const &) const;
};


#endif