#include "Admin.h"



Admin::Admin(const char* nick, const unsigned int &agge, fmibook* bok) : Moderator(nick, agge, 0)
{
	book = bok;
}

const char Admin::Authorisation() const
{
	char s = 'a';
	return s;
}

Admin::~Admin()
{
}
