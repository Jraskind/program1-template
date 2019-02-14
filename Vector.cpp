Vector::Vector(){

	capacity = 0;
	currentItems = 0;
	
}

Vector::~Vector(){
	for(int i = 0; i < capacity; i++){
		if(vectorArr[i] == NULL){
		}
		else{
			delete vectorArr[i];
		}
	
	}
	delete[] vectorArr;
}


unsigned Vector::size(){

	return capacity;
}

void insert(int index, Planet * p){
	//Upping capacity if index OOB
	if(index < 0 || index == capacity || index > capacity ){
		
		Planet ** temp = new Planet * [capacity + 1];
		for(int i =0; i < capacity; i++){
			temp[i] = vectorArr[i];
					
		}
		temp[capacity] = NULL;
		delete[] vectorArr;
		vectorArr = temp;
		capacity++;
	} 
	//Insertion
	if(index < capacity)	{
		Planet ** temp = new Planet *[capacity + 1];
	

		for(int i = 0; i < index; i++){
			temp[i] = vectorArr[i];
		}
		temp[index] = p;
		for(int i = index+1; i < capacity; i++){

			temp[i] = vectorArr[i-1];
		}
	
		delete[] vectorArr;
		vectorArr = temp;
		capacity++;
		currentItems++;
	}


	return;
}

Planet* read(int index){
	if(index < 0 || index == capacity || index > capacity) return NULL;
	
	return vectorArr[index];
}
	

bool remove(int index){

	if(index < 0 || index == capacity || index > capacity) return FALSE;

	Planet ** temp = new Planet*[capacity - 1];
	for(int i = 0; i < index; i++){
		temp[i] = vectorArr[i];

	}

	if(vectorArr[index] != NULL) delete vectorArr[index];

	for(int i = index+1; i < capacity; i++){
		temp[i - 1] = vectorArr[i];
	}
	
	delete[] vectorArr;
	vectorArr = temp;
	return TRUE;
}

