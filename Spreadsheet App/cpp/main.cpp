#include <iostream>
#include "Data.h"
#include "Integer.h"
#include "Double.h"
#include "String.h"
#include <fstream>
#include "Date.h"
#include "Line.h"
#include "Table.h"

int main()
{
	Table test;
	test.ReadFromFile("test.txt");
	test.Print();
	test.Sort(3);
	test.Print();
	return 0;
}