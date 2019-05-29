#include "String.h"
#include <cstring>
#include <iostream>

String::String()
{
	arr = nullptr;
	len = 0;
}

String::String(const char* str)
{
	try
	{
		arr = new char[strlen(str) + 1];
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "String allocation failed: " << e.what() << '\n';
	}
	strcpy(arr, str);
	len = strlen(str) - 2;
}

String::String(const String& obj)
{
	try
	{
		arr = new char[strlen(obj.arr) + 1];	
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "String allocation failed: " << e.what() << '\n';
	}
	strcpy(arr, obj.arr);
	len = strlen(obj.arr) - 2;
}

String& String::operator=(const String& obj)
{
	if (this != &obj)
	{
		try
		{
			arr = new char[strlen(obj.arr) + 1];
		}
		catch (std::bad_alloc& e)
		{
			std::cout << "String allocation failed: " << e.what() << '\n';
		}
		delete[] arr;
		strcpy(arr, obj.arr);
		len = obj.len;
	}
	return *this;
}

char* String::NormalString() const
{
	int len = strlen(arr);
	char* newarr = new char[len + 1];
	int cntr = 0;
	for (int i = 1; i < len-1; ++i) // accounting for the beggining and ending "
	{
		if (arr[i] == '\\' && arr[i + 1] == '\"')
		{
			newarr[cntr] = arr[i + 1];
			++i;
		}
		else if (arr[i] == '\\' && arr[i + 1] == '\\')
		{
			newarr[cntr] = arr[i+1];
			++i;
		}
		else
		{
			newarr[cntr] = arr[i];
		}
		cntr++;
	}
	newarr[cntr] = '\0';
	return newarr;
}

void String::Visualise(std::ostream& ofs) const
{
	ofs << NormalString();
	//ofs << arr;
}

double String::DoubleValue() const
{
	return atof(NormalString());
}

Data* String::Clone()
{
	return new String(*this);
}

int String::GetLen()
{
	return len;
}

String::~String()
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}
