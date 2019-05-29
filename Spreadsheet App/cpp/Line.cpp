#include "Line.h"
#include <iostream>


Line::Line()
{
	arr = new Data*[2];
	size = 0;
	capacity = 2;
}

void Line::AddElement(Data* obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	if (obj == nullptr)
	{
		arr[size] = nullptr; // indicates that the cell is empty
		size++;
	}
	else
	{
		arr[size] = obj->Clone();
		size++;
	}
}

void Line::AddElement(const Integer& obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	arr[size] = new Integer(obj);
	size++;
}

void Line::AddElement(const Double& obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	arr[size] = new Double(obj);
	size++;
}

void Line::AddElement(const Date& obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	arr[size] = new Date(obj);
	size++;
}

void Line::AddElement(const String& obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	arr[size] = new String(obj);
	size++;
}


Line& Line::operator=(const Line& obj)
{
	if (this != &obj)
	{
		Clean();
		arr = new Data*[obj.size];
		for (int i = 0; i < obj.size; ++i)
		{
			if (obj[i] != nullptr)
			{
				AddElement(obj[i]->Clone());
			}
			else
			{
				AddElement(nullptr);
			}
		}
	}
	return *this;
}

void Line::Resize()
{
	try
	{
		Data** newarr = new Data*[capacity * 2];
		for (int i = 0; i < size; ++i)
		{
			newarr[i] = arr[i];
		}
		arr = newarr;
		capacity *= 2;
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "Line allocation failed: " << e.what() << '\n';
	}
}

void Line::Clean()
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != nullptr)
		{
			delete arr[i];
		}
	}
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 2;
}

Data* Line::operator[](const int& num)
{
	return arr[num];
}

Data* Line::operator[](const int& num) const
{
	return arr[num];
}


int Line::GetSize() const
{
	return size;
}
Line::~Line()

{
	Clean();
}
