#pragma once
#include "Publication.h"
#include <fstream>
class Link_Publication : public Publication
{
private:
	char* description;
public:
	Link_Publication(const unsigned int& num, const User* usr, const char* cont, const char* descr);
	Link_Publication(const Link_Publication &);
	const char* GetDescription() const;
	Link_Publication& operator=(const Link_Publication&);
	virtual void Visualize(std::ofstream& ofs);
	~Link_Publication();
};

