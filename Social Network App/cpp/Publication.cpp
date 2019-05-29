#include "Publication.h"
#include <cstring>

void Publication::CopyFrom(const unsigned int& num, const User* usr, const char* cont)
{
	number = num;
	user = usr;
	content = new char[strlen(cont) + 1];
	strcpy(content, cont);
}
Publication::Publication(const unsigned int& num, const User* usr, const char* cont)
{
	CopyFrom(num, usr, cont);
}

Publication& Publication::operator=(const Publication &obj)
{
	if (this != &obj)
	{
		CopyFrom(obj.GetNumber(), obj.GetUser(), obj.GetContent());
	}
		return *this;
}

const User* Publication::GetUser() const
{
	return user;
}
const char* Publication::GetContent() const
{
	return content;
}
const int Publication::GetNumber() const
{
	return number;
}

Publication::Publication(const Publication &obj)
{
	CopyFrom(obj.GetNumber(), obj.GetUser(), obj.GetContent());
}

void Publication::Clean()
{
	delete[] content;
	user = nullptr;
	content = nullptr;
}
Publication::~Publication()
{
	Clean();
}
