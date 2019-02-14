#ifndef PROGRAM1
#define PROGRAM1

#include "Planet.h"


class Node{
public:
	Planet* planet;
	Node* next;
	Node* previous; 
}

class List{
public:
	Node* headPtr;
	Node* tailPtr;

	List();
	~List();
	void insert(int, Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
}


#endif
