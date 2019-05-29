#pragma once
#include "Data.h"
class Date :
	public Data
{
private:
	char arr[10];
public:
	Date();
	Date(const char*);
	Date(const Date&);
	Date& operator=(const Date&);
	virtual void Visualise(std::ostream&) const;
	virtual double DoubleValue() const;
	virtual Data* Clone();
	virtual int GetLen();
	virtual ~Date();
};

