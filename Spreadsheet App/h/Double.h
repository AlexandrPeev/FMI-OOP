#pragma once
#include "Data.h"
#include <fstream>

class Double : public Data
{
private:
	double num;
	char sign;
	int len;
	// With space we denote that the number has no additionally appointed sign
	// We use + when it's explicitly stated that a positive number has to have a + sign
	// We leave blank space again if the number is <= 0, since the sign is contained in the integer
public:
	Double();
	Double(const Double&);
	Double& operator=(const Double&);
	Double(const double&, const char*);
	Double(const double&, const char&,const char*);
	virtual void Visualise(std::ostream&) const;
	virtual double DoubleValue() const;
	Data* Clone();
	virtual int GetLen();
	virtual ~Double();
};

