#pragma once
#include "Publication.h"
class Text_Publication : public Publication
{
public:
	Text_Publication(const unsigned int& num, const User* usr, const char* cont);
	virtual void Visualize(std::ofstream& ofs);
	virtual ~Text_Publication();
};

