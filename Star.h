#ifndef Star_JR
#define Star_JR
#include "Planet.h"
#include "Vector.h"
class Star{
	private:
		int current_planets;
	public:
		Planet** planets;
		Star();
		~Star();
		int addPlanet();
		Planet * getPlanet(long int);
		bool removePlanet(int);
		Planet getFurthest();
		void orbit();
		void printStarInfo();
		int getCurrentNumPlanets(){return current_planets;}
        //you may add any additional methodas you may need.
};
/* 

    Starvector()
        Initialize memory
    ~Starvector()
        deallocate all memory when the Star is deleted.
    long addPlanet()
        return the ID of the newly created Planet
    bool removePlanet(int)
        Takes a Planet’s ID as a parameter, and removes the Planet from the Star.
        You must return true upon successful deletion and false on failure if the ID isn't found.
    Planet * getPlanet(int)
        Takes a Planet’s ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL.
    void orbit()
        Iterate through your planets and alter their orbit position by +1
    void printStarInfo()
        Prints the Star information.
    unsigned int getCurrentNumPlanets()
        returns the current number of planets stored (the size of the vector)


*/
class Starvector{

private:
	unsigned int current_planets;
	Vector * vect;

public:
	Starvector();
	~Starvector();
	long addPlanet();
    	bool removePlanet(int);
    	Planet * getPlanet(int);
   	void orbit();
    	void printStarInfo();
    	unsigned int getCurrentNumPlanets(){return current_planets;};
};
#endif
