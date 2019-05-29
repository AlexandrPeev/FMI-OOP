#include "Double.h"
#include <iostream>


Double::Double()
{
	num = 0;
	sign = ' ';
	len = 0;
}

Double::Double(const double& number, const char* str)
{
	this->num = number;
	this->sign = ' ';
	this->len = strlen(str);
}

Double::Double(const Double& obj)
{
	this->num = obj.num;
	this->sign = obj.sign;
	this->len = obj.len;
}

Double& Double::operator=(const Double& obj)
{
	if (this != &obj)
	{
		this->num = obj.num;
		this->sign = obj.sign;
		this->len = obj.len;
	}
	return *this;
}

Double::Double(const double& number, const char& sym, const char* str)
{
	this->num = number;
	if (sym == '-')
	{
		if (number < 0)
		{
			sign = ' ';
		}
		else
		{
			sign = sym;
		}
	}
	else if (sym == '+')
	{
		if (number < 0)
		{
			std::cout << "Integer constructor received invalid sign";
		}
		else
		{
			sign = sym;
		}
	}
	else
	{
		std::cout << "Integer constructor received invalid sign";
	}
	len = strlen(str);
}

void Double::Visualise(std::ostream& ofs) const
{
	if (sign == ' ')
		ofs << num;
	else
	{
		ofs << sign << num;
	}
}

Data* Double::Clone()
{
	return new Double(*this);
}

double Double::DoubleValue() const
{
	return num;
}

int Double::GetLen()
{
	return len;
}

Double::~Double()
{
}
