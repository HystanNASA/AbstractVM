#include "eOperand.hpp"

template<typename T>
eOperand<T>::eOperand(void) {}


template<typename T>
eOperand<T>::eOperand(T value)
{
	this.value = value;
}


template<typename T>
eOperand<T>::~eOperand(void) {}

template<typename T>
IOperand const & eOperand<T>::operator=(eOperand const & rhs) const
{
	if (this != &rhs)
		this->value = rhs.value;

	return *this;
}

template<typename T>
IOperand const * eOperand<T>::operator+(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		type = rhs.getType();

	if (eType > Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) + std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) + std::stoll(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator-(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		type = rhs.getType();

	if (eType > Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) - std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) - std::stoll(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator*(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		type = rhs.getType();

	if (eType > Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) * std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) * std::stoll(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator/(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		type = rhs.getType();

	if (eType > Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) / std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) / std::stoll(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator%(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		type = rhs.getType();

	if (eType > Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) % std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) % std::stoll(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}
