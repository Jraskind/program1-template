#ifndef PROGRAM1
#define PROGRAM1

#include "Planet.h"


class Node{
public:
	Node();
	Planet* planet;
	Node* next;
	Node* previous;
};

class List{
private:
	Node* headPtr;
	Node* tailPtr;

public:
	List();
	~List();
	void insert(int, Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
};


#endif
