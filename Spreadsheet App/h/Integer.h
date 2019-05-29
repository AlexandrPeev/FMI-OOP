#pragma once
#include "Data.h"
#include <fstream>

class Integer : public Data
{
private:
	int num;
	char sign; 
	int len;
// With space we denote that the number has no additionally appointed sign
// We use + when it's explicitly stated that a positive number has to have a + sign
// We leave blank space again if the number is <= 0, since the sign is contained in the integer
public:
	Integer();
	Integer(const int&);
	Integer(const Integer&);
	Integer& operator=(const Integer&);
	Integer::Integer(const int&, const char&);
	virtual void Visualise(std::ostream&) const;
	virtual double DoubleValue() const;
	virtual Data* Clone();
	virtual int GetLen();
	virtual ~Integer();
};

