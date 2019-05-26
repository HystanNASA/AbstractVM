#ifndef EOPERAND_HPP
#define EOPERAND_HPP


#include <string>
#include <sstream>
#include <iomanip>

#include "IOperand.hpp"
#include "Factory.hpp"

template <typename T>
class eOperand : public IOperand
{
private:
	T value;
	std::string valueInString;

public:
	eOperand(void);
	eOperand(T value);
	
	~eOperand(void);

	int			 getPrecision(void) const;
	eOperandType getType() const;

	std::string const & toString(void) const;

	IOperand const & operator= (eOperand const &rhs) const;
	IOperand const * operator+ (IOperand const &rhs) const;
	IOperand const * operator- (IOperand const &rhs) const;
	IOperand const * operator* (IOperand const &rhs) const;
	IOperand const * operator/ (IOperand const &rhs) const;
	IOperand const * operator% (IOperand const &rhs) const;
	bool			 operator==(IOperand const &rhs) const;
	bool			 operator>=(IOperand const &rhs) const;
	bool			 operator<=(IOperand const &rhs) const;
	bool			 operator!=(IOperand const &rhs) const;
	bool			 operator>(IOperand const &rhs) const;
	bool			 operator<(IOperand const &rhs) const;
};


#endif