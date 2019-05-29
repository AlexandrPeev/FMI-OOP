#include <iostream>
#include <fstream>
#include "fmibook.h"

int main()
{
	fmibook example("Alexander", 21);
	example.AddUser("Alexander", "Pete", 31, 'm');
	example.AddPost("Pete", "FMI", "REEEE", 'l');
	example.RemovePost("Pete", 1);
	example.ViewAllPosts("Pete");
	return 0;
}