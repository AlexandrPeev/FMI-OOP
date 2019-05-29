#pragma once
#include "Publication.h"

// The idea is that when we delete a publication we delete the object and set the pointer to nullptr
// so that when we search we simply get our answer, wether the post is deleted with a simple check.
// That is why I have 2 separate vectors for User and Publications. User behaives like the normal structure.

class Publication_Vector
{
private:
	Publication** arr;
	unsigned int size;
	unsigned int capacity;
public:
	Publication_Vector();
	void Resize();
	void Delete_Publication(const unsigned int &num);
	void Add_Publication(Publication* onj);
	void Clean();
	unsigned int GetSize() const;
	Publication* operator[](const unsigned int &);
	~Publication_Vector();
};

