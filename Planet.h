#ifndef PLANET_JR
#define PLANET_JR
class Planet{
	private:
		long int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(int);
    int orbit();
		long int getID(){return this->id;};
		int getDistance(){return this->distance;};
		int getPos(){return this->pos;};
		char getType(){ return this->type;};
	//you may add any additional methods you may need.
		void setDistance(int);
		void setID(int);
};
#endif
