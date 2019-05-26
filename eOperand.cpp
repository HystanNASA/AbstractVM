#include "eOperand.hpp"

template<typename T>
eOperand<T>::eOperand(void) {}


template<typename T>
eOperand<T>::eOperand(T value) : value(value)
{
	if (typeid(value) == typeid(int8_t) || typeid(value) == typeid(int16_t) || typeid(value) == typeid(int32_t))
		valueInString = std::to_string(value);
	else if (typeid(value) == typeid(float))
	{
		std::stringstream set(std::stringstream::out);
		set << std::setprecision(8) << value;
		valueInString = set.str();
	}
	else if (typeid(value) == typeid(double))
	{
		std::stringstream set(std::stringstream::out);
		set << std::setprecision(14) << value;
		valueInString = set.str();
	}
}


template<typename T>
eOperand<T>::~eOperand(void) {}

template<typename T>
IOperand const & eOperand<T>::operator=(eOperand const & rhs) const
{
	if (this != &rhs)
	{
		this->value = rhs.value;
		this->valueInString = rhs.valueInString;
	}

	return *this;
}

template<typename T>
IOperand const * eOperand<T>::operator+(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) + std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) + std::stold(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator-(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) - std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) - std::stold(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator*(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) * std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) * std::stold(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator/(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) / std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) / std::stold(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
IOperand const * eOperand<T>::operator%(IOperand const & rhs) const
{
	eOperandType eType = this->getType;
	std::string  newValue;

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		newValue = std::to_string(static_cast<int64_t>(this->value)) % std::stoll(rhs.toString());
	else
		newValue = std::to_string(static_cast<long double>(this->value)) % std::stold(rhs.toString());

	return (Factory().createOperand(eType, newValue));
}


template<typename T>
bool eOperand<T>::operator==(IOperand const & rhs) const
{
	eOperandType eType = this->getType();

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		return (std::to_stirng(static_cast<int32_t>(this->value)) == std::stoi(rhs.toString()));
	else if(eType == Float)
		return (std::to_stirng(static_cast<float>(this->value)) == std::stoi(rhs.toString()));
	else
		return (std::to_stirng(static_cast<int32_t>(this->value)) == std::stoi(rhs.toString()));
}


template<typename T>
bool eOperand<T>::operator>=(IOperand const & rhs) const
{
	eOperandType eType = this->getType();

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		return (std::to_stirng(static_cast<int32_t>(this->value)) >= std::stoi(rhs.toString()));
	else if (eType == Float)
		return (std::to_stirng(static_cast<float>(this->value)) >= std::stoi(rhs.toString()));
	else
		return (std::to_stirng(static_cast<int32_t>(this->value)) >= std::stoi(rhs.toString()));
}


template<typename T>
bool eOperand<T>::operator<=(IOperand const & rhs) const
{
	eOperandType eType = this->getType();

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		return (std::to_stirng(static_cast<int32_t>(this->value)) <= std::stoi(rhs.toString()));
	else if (eType == Float)
		return (std::to_stirng(static_cast<float>(this->value)) <= std::stoi(rhs.toString()));
	else
		return (std::to_stirng(static_cast<int32_t>(this->value)) <= std::stoi(rhs.toString()));
}


template<typename T>
bool eOperand<T>::operator!=(IOperand const & rhs) const
{
	eOperandType eType = this->getType();

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		return (std::to_stirng(static_cast<int32_t>(this->value)) != std::stoi(rhs.toString()));
	else if (eType == Float)
		return (std::to_stirng(static_cast<float>(this->value)) != std::stoi(rhs.toString()));
	else
		return (std::to_stirng(static_cast<int32_t>(this->value)) != std::stoi(rhs.toString()));
}


template<typename T>
bool eOperand<T>::operator>(IOperand const & rhs) const
{
	eOperandType eType = this->getType();

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		return (std::to_stirng(static_cast<int32_t>(this->value)) > std::stoi(rhs.toString()));
	else if (eType == Float)
		return (std::to_stirng(static_cast<float>(this->value)) > std::stoi(rhs.toString()));
	else
		return (std::to_stirng(static_cast<int32_t>(this->value)) > std::stoi(rhs.toString()));
}


template<typename T>
bool eOperand<T>::operator<(IOperand const & rhs) const
{
	eOperandType eType = this->getType();

	if (this->getType() < rhs.getType())
		eType = rhs.getType();

	if (eType < Float)
		return (std::to_stirng(static_cast<int32_t>(this->value)) < std::stoi(rhs.toString()));
	else if (eType == Float)
		return (std::to_stirng(static_cast<float>(this->value)) < std::stoi(rhs.toString()));
	else
		return (std::to_stirng(static_cast<int32_t>(this->value)) < std::stoi(rhs.toString()));
}


template<typename T>
int eOperand<T>::getPrecision(void) const
{
	if		(typeid(value) == typeid(int8_t))  return 0;
	else if (typeid(value) == typeid(int16_t)) return 0;
	else if (typeid(value) == typeid(int32_t)) return 0;
	else if (typeid(value) == typeid(float))   return 7;
	else if (typeid(value) == typeid(double))  return 14;
	else									   return 0;
}


template<typename T>
eOperandType eOperand<T>::getType(void) const
{
	if (typeid(value) == typeid(int8_t))	   return Int8;
	else if (typeid(value) == typeid(int16_t)) return Int16;
	else if (typeid(value) == typeid(int32_t)) return Int32;
	else if (typeid(value) == typeid(float))   return Float;
	else if (typeid(value) == typeid(double))  return Double;
	else									   return 0;
}


template<typename T>
std::string const & eOperand<T>::toString(void) const
{

}