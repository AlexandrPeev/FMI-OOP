#pragma once
#include "Data.h"
#include "Integer.h"
#include "Date.h"
#include "String.h"
#include "Double.h"
#include "Line.h"

class Table
{
private:
	Line* lines;
	int size;
	int capacity;
	int columnrank;
public:
	Table();
	void AddRow();
	void Resize();
	void Print();
	void Sort(const int&);
	void ReadFromFile(const char*);
	int ProcessLine(const char*);
	~Table();
};

