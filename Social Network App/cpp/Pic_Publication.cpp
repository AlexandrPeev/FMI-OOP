#include "Pic_Publication.h"



Pic_Publication::Pic_Publication(const unsigned int &num, const User* usr, const char* cont) : Publication(num, usr, cont)
{
	
}

void Pic_Publication::Visualize(std::ofstream& ofs)
{
	ofs << "<img src = \"" << content << "\">";
}

Pic_Publication::~Pic_Publication()
{
}
