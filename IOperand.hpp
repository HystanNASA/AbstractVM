#ifndef IOPERAND_HPP
#define IOPERAND_HPP


#include <string>
#include <inttypes.h>
#include <vector>
#include <functional>

#include "eOperand.hpp"

class IOperand;

typedef IOperand const * (IOperand::*func)(std::string const &) const;

class IOperand
{
private:
	// Foo obj;
	// (obj.*fptr)("str");

public:
	virtual ~IOperand(void) {}

	virtual int			 getPrecision(void) const = 0;
	virtual eOperand getType(void) const = 0;

	virtual IOperand const * operator+(IOperand const &) const = 0;
	virtual IOperand const * operator-(IOperand const &) const = 0;
	virtual IOperand const * operator*(IOperand const &) const = 0;
	virtual IOperand const * operator/(IOperand const &) const = 0;
	virtual IOperand const * operator%(IOperand const &) const = 0;
	
	virtual std::string const & toString(void) const = 0;
};


#endif 