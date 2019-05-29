#pragma once
#include <fstream>

class Data
{
public:
	Data();
	virtual void Visualise(std::ostream& ofs) const = 0;
	virtual double DoubleValue() const = 0; // We use double value since we compare everything in numbers
	// and double is contains more information than int
	virtual Data* Clone() = 0;
	virtual int GetLen() = 0;
	virtual ~Data();
};

