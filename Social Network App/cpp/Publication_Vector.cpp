#include "Publication_Vector.h"
#include <iostream>


Publication_Vector::Publication_Vector()
{
	arr = new Publication*[2];
	size = 0;
	capacity = 2;
}

void Publication_Vector::Resize()
{
	Publication** newarr = new Publication*[capacity * 2];
	for (unsigned int i = 0; i < size; ++i)
	{
		newarr[i] = arr[i];
	}
	capacity *= 2;
	for (int unsigned i = 0; i < size; ++i)
	{
		delete arr[i];
	}
	delete[] arr;
	arr = newarr;
}

void Publication_Vector::Add_Publication(Publication* obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	arr[size] = obj;
	size++;
}

void Publication_Vector::Delete_Publication(const unsigned int &num)
{
	if(num - 1 >= size || arr[num-1] == nullptr)
	{
		std::cout << "Post does not exist";
	}
	else
	{
		delete arr[num - 1];
		arr[num - 1] = nullptr;
	}
	size;
}


unsigned int Publication_Vector::GetSize() const
{
	return size;
}

void Publication_Vector::Clean()
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (arr[i] != nullptr)
		{
			delete arr[i];
		}
	}
	delete[] arr;
	arr = nullptr;
	size = 0;
}

Publication* Publication_Vector::operator[](const unsigned int &num)
{
	return arr[num];
}
Publication_Vector::~Publication_Vector()
{
	Clean();
}
