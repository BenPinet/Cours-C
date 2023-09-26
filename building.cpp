#include <building.h> 
#include <storey.h> 
#include<iostream>

Building::Building(int identifier,int nb_floors) : id_(identifier), storeys_(nullptr), nb_storeys_(nb_floors) {
	storeys_=new Storey[nb_floors];
	std::cout<< "Building::Building (" << identifier << ") at "<< this <<std::endl;
}

Building::~Building() {
	delete[] storeys_;
	std::cout<< "~Building"  << id_<<std::endl;
}

void Building::print(std::ostream& out){
	out<<"Building "<<id_<<" at "<<this << std::endl;
	
}
Building::Building(const Building& rhs) : id_(rhs.id_) ,storeys_(nullptr), nb_storeys_(rhs.nb_storeys_)
{
	
	storeys_=new Storey[rhs.nb_storeys_];
	clone_storeys(storeys_,rhs.storeys_);
	std::cout << "Copie de Building" <<  "dans le building" << id_ << std::endl;
}
Building& Building::operator=(const Building& rhs){
	if(this != &rhs ) 
	{
	id_=rhs.id_;
	nb_storeys_=rhs.nb_storeys_;
	delete[] storeys_;
	storeys_=new Storey[nb_storeys_];
	clone_storeys(storeys_,rhs.storeys_);
	}
	return *this;
}

void Building::clone_storeys(Storey* to , Storey* from){
	for (int is=0; is<nb_storeys_ ; ++is)
	{
		to[is]=from[is];
		
	}
}
Storey* Building::create_and_add_storey(){
	Storey* new_storeys = new Storey[nb_storeys_+1];
	clone_storeys(new_storeys,storeys_);
	delete[] storeys_;
	storeys_= new_storeys;
	nb_storeys_++;
	return &storeys_[nb_storeys_-1];
}
	