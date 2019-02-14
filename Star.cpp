#include "Star.h"
#include "Planet.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Star::Star(){
	this->planets = NULL;
	this->current_planets = 0;

}

int Star::addPlanet(){
/*

    allocate a new array of size 1 + the current number of Planets
    copy all the pointers over to the new array
    Create a new Planet object
    Put the resulting Planet object pointer in the new array
    update the current number of Planets
    free the old array
    Point the planet array to the new array

*/
		
	Planet** newPlanets = new Planet*[this->current_planets + 1];

	for(int i = 0; i < this->current_planets; i++){
		newPlanets[i] = planets[i];
	}
	Planet * p = new Planet((rand() % 3000 + 1));
	newPlanets[current_planets] = p;
	
	this->current_planets++;

	
	delete[] planets;
	
	planets = newPlanets;	
	

	


	return p->getID();
}

bool Star::removePlanet(int id){
/*


    allocate a new array of size 1 - the current number of Planets
    copy all the pointers over to the new array except the pointer with the ID that matches the Planet to be deleted.
    delete the Planet object with the matching ID
    update the current number of Planets
    free the old array
    Point the planet array to the new array


*/	
	if(!getPlanet(id)){return false;}
	Planet** newPlanets = new Planet*[this->current_planets - 1];
	

	int add_planet_index = 0;
	for(int i =0; i < current_planets; i++){
		if(planets[i]->getID() == id){
			delete planets[i];	
			planets[i] = NULL;

		}
		else{	
			newPlanets[add_planet_index] = planets[i];
			add_planet_index++;
		}
	}

	delete[] planets;
	planets = newPlanets;
	this->current_planets--;	
	return true;
}

Planet Star::getFurthest(){
	Planet greatestDistancePlanet = *planets[0];
	int i;
	for(i = 0; i < current_planets; i++){
		if(planets[i]->getDistance() > greatestDistancePlanet.getDistance()){
			greatestDistancePlanet = *planets[i];
		}
	}

	return greatestDistancePlanet;
}

void Star::orbit(){
	int i;
	for(i = 0; i < current_planets; i++){

		planets[i]->orbit();
	}
}

void Star::printStarInfo(){
	std::cout << "The star has " << current_planets << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i =0; i < current_planets; i++){
	std::cout << "Planet " << planets[i]->getType() << planets[i]->getID() << " is " << planets[i]->getDistance() << " miles away at position " << planets[i]->getPos() << " around the star." << std::endl;

	}

}

Planet * Star::getPlanet(long int id){
	for(int i = 0; i < current_planets; i++){
		
		if(planets[i]->getID() == id){
			return planets[i];
		}

	}

	return NULL;
}

Star::~Star(){

	for(int i = 0; i < current_planets; i++){
		delete planets[i];
		planets[i] = NULL;
	}
	delete[] planets;
	planets = NULL;
}
