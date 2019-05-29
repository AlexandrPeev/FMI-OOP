#pragma once
#include <fstream>
#include "User.h"

class Publication
{
protected :
	const User* user;
	char* content;
	unsigned int number;
private:
	Publication(); // Disabled for safety
public:
	Publication(const unsigned int& num, const User* usr, const char* cont); // The number will only be assigned from the Network class
	Publication(const Publication&);
	Publication& operator=(const Publication&);
	void CopyFrom(const unsigned int& num, const User* usr, const char* cont);
	const User* GetUser() const;
	const char* GetContent() const;
	const int GetNumber() const;
	virtual void Visualize(std::ofstream& ofs) = 0;
	void Clean();
	virtual ~Publication();
};

