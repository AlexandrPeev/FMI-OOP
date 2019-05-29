#pragma once
#include "Data.h"
class String :	public Data
{
private:
	char* arr;
	int len;
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	char* NormalString() const; // Returns the string without \\ and \"
	virtual void Visualise(std::ostream&) const;
	virtual double DoubleValue() const;
	virtual Data* Clone();
	virtual int GetLen();
	virtual ~String();
};

