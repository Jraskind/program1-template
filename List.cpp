#include "List.h"

List::List(){
	this->headPtr = NULL;
	this->tailPtr = NULL;
}

List::~List(){
	//delete nodes of linkedlist
}

void List::insert(int index, Planet* p){
	//Reference the currentNode being traversed
	//Create a new node to be inserted and set its planet ptr to the parameter
	Node* currentNode = this->headPtr;
	Node* newNode = new Node();
	(*newNode).planet = p;

	//No headPtr means start of list, set newNode to headPtr
	if (headPtr == NULL){
		headPtr = newNode;
		
	}

	tailPtr = newNode;

	//Verify the index input is valid
	if (index > size()){
		tailPtr.next = newNode;
		newNode.previous = tailPtr;
		tailPtr = newNode;
	};

	for(int i = 0; i < index - 1; i++){
		currentNode = currentNode.next;
	}
	
	currentNode.next.previous = newNode;
	(*newNode).next = currentNode.next.previous;

	currentNode.next = newNode;
	(*newNode).previous = currentNode;


	//Increase list size by 1
	size()
}

Planet* List::read(int index){
	if (index > size()) return NULL;

	Node* currentNode = this->headPtr;
	for(int i = 0; i < index; i++){
		currentNode = currentNode.next;
	}
	return currentNode.planet; 
}

bool List::remove(int index){

}

unsigned List::size(){

}
