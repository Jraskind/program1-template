#include "Vector.h"
#include "Planet.h"
#include <cstdlib>
#include<iostream>
using namespace std;
Vector::Vector(){

	capacity = 0;
	vectorArr = NULL;
}

Vector::~Vector(){
	for(int i = 0; i < capacity; i++){
		if(vectorArr[i] == NULL){
		}
		else{
			delete vectorArr[i];
			vectorArr[i] = NULL;
		}
	
	}
	delete[] vectorArr;
	vectorArr = NULL;
}


unsigned Vector::size(){
	if(vectorArr == NULL) return 0;
	return capacity;
}

void Vector::insert(int index, Planet * p){

	//Upping capacity if index OOB
	if(index < 0 || index > capacity ){
		
		Planet ** temp = new Planet * [index + 1];
		for(int i =0; i < capacity; i++){
			temp[i] = vectorArr[i];
					
		}
		for(int i=capacity; i < index+1; i++){
			temp[i] = NULL;
		}
		temp[index] = p;
		
		delete[] vectorArr;
		vectorArr = temp;
		capacity = index + 1;
		return;
	} 
	//Insertion
	else{   
		Planet ** temp = new Planet *[capacity + 1];


		for(int i = 0; i < index; i++){
			temp[i] = vectorArr[i];
		}
		temp[index] = p;
		for(int i = index+1; i < capacity+1; i++){

			temp[i] = vectorArr[i-1];
		}
	
		delete[] vectorArr;
		vectorArr = temp;
		capacity++;

		return;
	}


	return;
}

Planet* Vector::read(int index){
	if(index < 0 || index > capacity) return NULL;
	
	return vectorArr[index];
}
	

bool Vector::remove(int index){

	if(index < 0 || index >= capacity) return false;
	
	Planet ** temp = new Planet*[capacity - 1];
	for(int i = 0; i < index; i++){
		temp[i] = vectorArr[i];

	}


	if(vectorArr[index] != NULL){ 
		delete vectorArr[index];
		vectorArr[index] = NULL;

	}

	for(int i = index+1; i < capacity; i++){
		temp[i - 1] = vectorArr[i];
	}
	capacity--;
	delete[] vectorArr;
	vectorArr = temp;
	return true;
}

