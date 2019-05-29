#pragma once
#include "User.h"
class Moderator :
	public User
{
public:
	Moderator(const char* nick, const unsigned int &agge, const bool &mutestate);
	Moderator(const Moderator &);
	virtual void ChangeMuteState(const bool &state, User* obj);
	virtual const char Authorisation() const;
	~Moderator();
};

