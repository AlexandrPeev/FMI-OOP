#include "Date.h"
#include <cstring>


Date::Date()
{
	arr[0] = '0';
	arr[1] = '1';
	arr[2] = '.';
	arr[3] = '0';
	arr[4] = '1';
	arr[5] = '.';
	arr[6] = '1';
	arr[7] = '9';
	arr[8] = '7';
	arr[9] = '0';
}

Date::Date(const char* str)
{
	strcpy(arr, str);
}

Date::Date(const Date& obj)
{
	strcpy(arr, obj.arr);
}

Date& Date::operator=(const Date& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 10; i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}
	return *this;
}



void Date::Visualise(std::ostream& ofs) const
{
	ofs << arr;
}

double Date::DoubleValue() const
{
	char db[2];
	char year[4];
	int days, months, years;
	if (arr[1] == '.' || arr[2] == '.') // case for dd.mm.yyyy format 02.3.2015 || 2.3.2016
	{
		db[0] = arr[0];
		db[1] = arr[1];
		days = atoi(db);
		db[0] = arr[3];
		db[1] = arr[4];
		months = atoi(db);
		year[0] = arr[6];
		year[1] = arr[7];
		year[2] = arr[8];
		year[3] = arr[9];
		years = atoi(year);
	}
	else
	{
		db[0] = arr[9];
		db[1] = arr[8];
		days = atoi(db);
		db[0] = arr[6];
		db[1] = arr[5];
		months = atoi(db);
		year[0] = arr[0];
		year[1] = arr[1];
		year[2] = arr[2];
		year[3] = arr[3];
		years = atoi(year);
	}
	unsigned long long int result = 0; // counter for the days
	for (int i = 1970; i < years; ++i)
	{
		if (i % 4 == 0 && i % 100 != 0)
		{
			result += 366;
		}
		else
		{
			result += 365;
		}
	}
	switch (months)
	{
	case 1: result += 31;
	case 2: result += 31;
	case 3: if (years % 4 == 0 && years % 100 != 0)
			{result += 29;}
			else 
			{result += 28;}
	case 4: result += 30;
	case 5: result += 31;
	case 6: result += 30; 
	case 7: result += 31;
	case 8: result += 31;
	case 9: result += 30;
	case 10: result += 31;
	case 11: result += 30;
	case 12: result += 31;
	}
	result += days;
	return (double)result;
}


int Date::GetLen()
{
	return 10;
}

Data* Date::Clone()
{
	return new Date(*this);
}

Date::~Date()
{
}
