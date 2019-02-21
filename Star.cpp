#include "Star.h"
#include "Planet.h"
#include "Vector.h"
#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Putting in Starvector

Starvector::Starvector(){
	vect = new Vector();
	current_planets = 0;
}

Starvector::~Starvector(){
	delete vect;
}

long Starvector::addPlanet(){
	Planet * p = new Planet((rand() % 3000 + 1));
	vect->insert(0, p);
	current_planets++;
	return p->getID();
}

bool Starvector::removePlanet(int id){
	Planet * tempPlanet = NULL;

	for(int i = 0; i < current_planets; i++){
		tempPlanet = vect->read(i);
		
		if(tempPlanet->getID() == id){
			current_planets--;
			return vect->remove(i);
		}

	}


	return false;
}


Planet * Starvector::getPlanet(int id){
	Planet * tempPlanet = NULL;
	for(int i = 0; i < current_planets; i++){
		tempPlanet = vect->read(i);
		if(tempPlanet->getID() == id) return tempPlanet;
	}

	return NULL;

}

void Starvector::orbit(){
	Planet * tempPlanet = NULL;
	for(int i = 0; i < current_planets; i++){
		tempPlanet = vect->read(i);
		tempPlanet->orbit();
	}

	return;
}
void Starvector::printStarInfo(){
	Planet * tempPlanet = NULL;

	cout << "The star has " << current_planets << " planets." << endl;
	cout << "Planets:" << endl;
	for(int i =0; i < current_planets; i++){
	tempPlanet = vect->read(i);
	cout << "Planet " << tempPlanet->getType() << tempPlanet->getID() << " is " << tempPlanet->getDistance() << " miles away at position " << tempPlanet->getPos() << " around the star." << endl;
}



Starlist::Starlist(){
	list = new List();
	this->current_planets = 0;
}

Starlist::~Starlist(){
	delete list;
}

long Starlist::addPlanet(){
	Planet * p = new Planet((rand() % 3000 + 1));
	list->insert(0, p);
	current_planets++;
	return p->getID();	
}

bool Starlist::removePlanet(int index){
	Planet * tempPlanet = NULL;

	for(int i = 0; i < current_planets; i++){
		tempPlanet = list->read(i);
		
		if(tempPlanet->getID() == id){
			current_planets--;
			return list->remove(i);
		}

	}


	return false;
}

Planet* Starlist::getPlanet(int){
	Planet * tempPlanet = NULL;
	for(int i = 0; i < current_planets; i++){
		tempPlanet = list->read(i);
		if(tempPlanet->getID() == id) return tempPlanet;
	}

	return NULL;
}

void Starlist::orbit(){
	Planet * tempPlanet = NULL;
	for(int i = 0; i < current_planets; i++){
		tempPlanet = list->read(i);
		tempPlanet->orbit();
	}

	return;
}

void Starlist::printStarInfo(){
	Planet * tempPlanet = NULL;

	cout << "The star has " << current_planets << " planets." << endl;
	cout << "Planets:" << endl;
	for(int i =0; i < current_planets; i++){
	tempPlanet = list->read(i);
	cout << "Planet " << tempPlanet->getType() << tempPlanet->getID() << " is " << tempPlanet->getDistance() << " miles away at position " << tempPlanet->getPos() << " around the star." << endl;
}

}

