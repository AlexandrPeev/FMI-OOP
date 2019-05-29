#include "User_Vector.h"
#include <iostream>
#include <cstring>


User_Vector::User_Vector()
{
	arr = new User*[2];
	size = 0;
	capacity = 2;
}


void User_Vector::Add_User(User* obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	for (unsigned int i = 0; i < size; ++i)
	{
		if (strcmp(obj->GetNickname(), arr[i]->GetNickname()) == 0)
		{
			std::cout << "Nickname is already taken";
			return;
		}
	}
	arr[size] = obj;
	size++;
}

void User_Vector::Remove_User(const char* nick)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		if (strcmp(arr[i]->GetNickname(), nick) == 0)
		{
			for (unsigned int j = 0; j < i; ++j)
			{
				User** newarr = new User*[size];
			}
			delete arr[i++];
			for (unsigned int j = i; j < size; ++j)
			{
				User** newarr = new User*[size];
			}
			size--;
			return;
		}
	}
}

void User_Vector::Resize()
{
	User** newarr = new User*[capacity * 2];
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

unsigned int User_Vector::GetSize() const
{
	return size;
}

User* User_Vector::operator[](const unsigned int &num)
{
	return arr[num];
}

User_Vector::~User_Vector()
{
	for (unsigned int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
	arr = nullptr;
	size = 0;
}
