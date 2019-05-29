#include "Link_Publication.h"
#include <fstream>

Link_Publication::Link_Publication(const unsigned int &num, const User* usr, const char* cont, const char* descr) : Publication(num, usr, cont)
{
	description = new char[strlen(descr) + 1];
	strcpy(description, descr);
}
const char* Link_Publication::GetDescription() const
{
	return description;
}

Link_Publication::Link_Publication(const Link_Publication &obj) : Publication(obj)
{
	description = new char[strlen(obj.GetDescription()) + 1];
	strcpy(description, obj.GetDescription());
}
Link_Publication& Link_Publication::operator=(const Link_Publication&obj)
{
	Publication::operator=(obj);
	if (this != &obj)
	{
		description = new char[strlen(obj.GetDescription()) + 1];
		strcpy(description, obj.GetDescription());
	}
	return *this;
}

void Link_Publication::Visualize(std::ofstream& ofs)
{
	ofs << "<a href=\"" << content << "\">" << description << "</a>";
}

Link_Publication::~Link_Publication()
{
	delete[] description;
}
