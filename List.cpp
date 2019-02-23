#include "List.h"
#include <iostream>

using namespace std;

List::List(){
	this->headPtr = NULL;
	this->tailPtr = NULL;
}

Node::Node(){
	this->next = NULL;
	this->previous = NULL;
	this->planet = NULL;
}

List::~List(){
	//delete nodes of linkedlist
	Node* temp = headPtr;
	while(headPtr != NULL){
		delete temp->planet;
		temp = headPtr->next;
		delete headPtr;
		headPtr = temp;
	}
}

void List::insert(int index, Planet* p){


	if(index < 0) return;


	Node* newNode = new Node();
	newNode->planet = p;

	//No headPtr means first element into list
	if (this->headPtr == NULL){
		this->headPtr = newNode;
		this->tailPtr = newNode;
		return;
	}

	//Keep track of ahead and behind nodes
	Node* nodeBehind = this->headPtr;
	Node* nodeAhead = this->tailPtr;

	//Index larger than size of list means push to end
	if (index >= size()){
		nodeAhead->next = newNode;
		tailPtr = newNode;
		newNode->previous = nodeAhead;
		return;
	};

	//If neither of the above cases, traverse the list
	//and input into the correct location
	for(int i = 0; i < index - 1; i++){

		nodeBehind = nodeBehind->next;
	}

	while(nodeAhead->previous != nodeBehind){
		nodeAhead = nodeAhead->previous;
	}

	//Reconfigure the linked list
	nodeBehind->next = newNode;
	nodeAhead->previous = newNode;

	newNode->next = nodeAhead;
	newNode->previous = nodeBehind;
}

Planet* List::read(int index){
	if (index > size() || index < 0) return NULL;

	Node* currentNode = this->headPtr;
	for(int i = 0; i < index; i++){
		currentNode = currentNode->next;
	}
	return currentNode->planet;
}

bool List::remove(int index){
	if (index > size() || index < 0) return false;


	Node* nodeAhead = this->tailPtr;
	Node* nodeBehind = this->headPtr;
	for(int i = 0; i < index - 1; i++){
		nodeBehind = nodeBehind->next;
	}

	while(nodeAhead->previous != nodeBehind->next){
		nodeAhead = nodeAhead->previous;
	}

	delete nodeBehind->next->planet;
	delete nodeBehind->next;

	nodeBehind->next = nodeAhead;
	nodeAhead->previous = nodeBehind;
	return true;
}

unsigned List::size(){
	unsigned retVal = 0;
	Node* temp = headPtr;
	while(temp != NULL){
		temp = temp->next;
		retVal++;
	}
	return retVal;
}
