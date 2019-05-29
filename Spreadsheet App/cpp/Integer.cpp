#include "Integer.h"
#include <iostream>


Integer::Integer()
{
	num = 0;
	sign = ' ';
	len = 0;
}

Integer::Integer(const int& number)
{
	this->num = number;
	this->sign = ' ';
	char fff[30];
	itoa(number, fff, 10);
	len = strlen(fff);
}


Integer::Integer(const Integer& obj)
{
	this->num = obj.num;
	this->sign = obj.sign;
	this->len = obj.len;
}

Integer& Integer::operator=(const Integer& obj)
{
	if (this != &obj)
	{
		this->num = obj.num;
		this->sign = obj.sign;
		this->len = obj.len;
	}
	return *this;
}

Integer::Integer(const int& number, const char& sym)
{
	this->num = number;
	char fff[30];
	itoa(number, fff, 10);
	len = strlen(fff);
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
	else if(sym == '+')
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
}

void Integer::Visualise(std::ostream& ofs) const
{
	if(sign == ' ')
	ofs << num;
	else
	{
	ofs << sign << num;
	}
}

double Integer::DoubleValue() const
{
	return (double)num;
}

int Integer::GetLen()
{
	return len;
}
Data* Integer::Clone()
{
	return new Integer(*this);
}

Integer::~Integer()
{
}
