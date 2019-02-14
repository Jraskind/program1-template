/*


    ~Vector()
        A destructor to clean up memory
    void insert(int index, Planet * p)
        inserts an element at index, increasing the Vector size by 1
        if the insert index is out of bounds, you should increase the capacity to the size of the index + 1
    Planet* read(int index)
        returns a pointer to the Planet object at index
        if the index is out of bounds, return NULL
    bool remove(int index)
        remove the Planet object at index, decreasing the size of the Vector by 1.
    unsigned size()
        returns the current size of the Vector (this may not be the same as the number of elements)

*/
#ifndef Vector_JR
#define Vector
#include "Planet.h"

class Vector{

private:
	Planet ** vectorArr;
//Will have capacity and currentItems in order to keep track of both empty spaces as well as how many planets there might be
	int currentItems;
	int capacity;

public:
	Vector();
	~Vector();
	void insert(int, Planet *);
	Planet* read(int);
	bool remove(int);
	unsigned size();

};





#endif
