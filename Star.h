#ifndef Star_JR
#define Star_JR
#include "Planet.h"
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
#endif
