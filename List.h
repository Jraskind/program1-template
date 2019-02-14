#ifndef PROGRAM1
#define PROGRAM1

#include "Planet.h"

class List{
public:
	List();
	~List();
	void insert(int, Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
}

class Node{
public:
	
}

#endif
