#include "User.h"
#include <cstring>


User::User(const char* nick, const unsigned int &agge, const bool &mutestate)
{
	nickname = new char[strlen(nick) + 1];
	strcpy(nickname, nick);
	age = agge;
	muted = mutestate;
}

User::User(const User &obj)
{
	delete[] nickname;
	nickname = new char[strlen(obj.GetNickname()) + 1];
	age = obj.GetAge();
	muted = obj.GetMuteState();
}

void User::ChangeNickName(const char* other)
{
	delete[] nickname;
	nickname = new char[strlen(other) + 1];
	strcpy(nickname, other);
}

const char* User::GetNickname() const
{
	return nickname;
}
unsigned int User::GetAge() const
{
	return age;
}

bool User::GetMuteState() const
{
	return muted;
}

const char User::Authorisation() const
{
	char s = 'u';
	return s;
}

User::~User()
{
	delete[] nickname;
	nickname = nullptr;
}
