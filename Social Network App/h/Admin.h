#pragma once
#include "Moderator.h"
#include "fmibook.h"
class Admin : public Moderator
{
public:
	Admin(const char* nick, const unsigned int &agge, fmibook* bok);
	virtual const char Authorisation() const;
	~Admin();
private:
	fmibook* book;
};

