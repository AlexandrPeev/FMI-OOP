#include "Moderator.h"
#include <iostream>


Moderator::Moderator(const char* nick, const unsigned int &agge, const bool &mutestate) : User(nick, agge, mutestate)
{

}

void Moderator::ChangeMuteState(const bool &state, User* obj)
{
	if (!obj)
	{
		std::cout << "Null pointer passed to ChangeMuteState";
	}
	else
	{
		obj->muted = state;
	}
}

Moderator::Moderator(const Moderator &obj) : User(obj)
{

}

const char Moderator::Authorisation() const
{
	char s = 'm';
	return s;
}

Moderator::~Moderator()
{
}
