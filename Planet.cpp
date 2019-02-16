#include "Planet.h"
#include <iostream>
#include <cstdlib>

Planet::Planet(int distance){
	this->id = (long int) this;
	this->distance = distance;
    	this->pos = rand() % 359;
	char const * types = "hrg";
	this->type = types[(rand() % 3)];
}

int Planet::orbit(){
	
	if(this->pos == 359){
		this->pos = 0;
	}
	else{
		this->pos = this->pos +1;
	}
	
	return this->pos;
}
