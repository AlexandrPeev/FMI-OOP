#include "Text_Publication.h"



Text_Publication::Text_Publication(const unsigned int &num, const User* usr, const char* cont) : Publication(num, usr, cont)
{

}

void Text_Publication::Visualize(std::ofstream& ofs)
{
	ofs << content;
}

Text_Publication::~Text_Publication()
{
}
