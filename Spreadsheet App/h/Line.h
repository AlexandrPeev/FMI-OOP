#pragma once
#include "Data.h"
#include "Integer.h"
#include "Date.h"
#include "String.h"
#include "Double.h"

class Line
{
private:
	Data** arr;
	int size;
	int capacity;
public:
	Line();
	void AddElement(Data* obj);
	void AddElement(const Integer&);
	void AddElement(const Double&);
	void AddElement(const Date&);
	void AddElement(const String&);
	Line& operator=(const Line&);
	Data* operator[](const int&);
	Data* operator[](const int&) const;
	int GetSize() const;
	void Clean();
	void Resize();
	~Line();
};

