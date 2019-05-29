#pragma once
#include "User.h"
class User_Vector
{
private:
	User** arr;
	unsigned int size;
	unsigned int capacity;
public:
	User_Vector();
	void Add_User(User*);
	void Remove_User(const char* nick);
	void Resize();
	unsigned int GetSize() const;
	User* operator[](const unsigned int &num);
	~User_Vector();
};

