#pragma once
#include "Publication.h"

class Pic_Publication : public Publication
{
private:
	Pic_Publication();
public:
	Pic_Publication(const unsigned int& num, const User* usr, const char* cont);
	virtual void Pic_Publication::Visualize(std::ofstream& ofs);
	~Pic_Publication();
};

