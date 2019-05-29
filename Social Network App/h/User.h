#pragma once

class User
{
	friend class fmibook;
	friend class Moderator;
private:
	User();
protected:
	char* nickname;
	unsigned int age;
	bool muted;
public:
	User(const char* nick, const unsigned int &agge , const bool &mutesate);
	User(const User &);
	void ChangeNickName(const char* other);
	const char* GetNickname() const;
	bool GetMuteState() const;
	unsigned int GetAge() const;
	virtual const char Authorisation() const;
	virtual ~User();
};

