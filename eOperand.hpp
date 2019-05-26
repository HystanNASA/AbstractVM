#ifndef EOPERAND_HPP
#define EOPERAND_HPP


#include "IOperand.hpp"
#include "Factory.hpp"

enum eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

template <typename T>
class eOperand : IOperand
{
private:
	T value;

public:
	eOperand(void);
	eOperand(T value);
	
	~eOperand(void);

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