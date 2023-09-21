#include <iostream>
#include<iostream>
class Storey{
public:
	Storey();
	Storey(const Storey& rhs);
	~Storey();
	Storey& operator=(const Storey& rhs);
private:
	int uid_;
	static int serial_number_; 
};

class Building
{
public: 
	Building() : id_(-1) {};
	Building(int identifier);
	~Building();
	void print(std::ostream& ou);
	Building (const Building& rhs);
	Building& operator=(const Building& rhs);
private:
	int id_;
};

Building::Building(int identifier) : id_(identifier) {
	std::cout<< "Building::Building (" << identifier << ") at "<< this <<std::endl;
}

Building::~Building() {
	std::cout<< "~Building"  << id_<<std::endl;
}

void Building::print(std::ostream& out){
	out<<"Building "<<id_<<" at "<<this << std::endl;
	
}
Building::Building(const Building& rhs) : id_(rhs.id_) 
{
	std::cout << "Copie de Building" <<  "dans le building" << id_ << std::endl;
}
Building& Building::operator=(const Building& rhs){
	if(this != &rhs ) 
	{
	id_=rhs.id_;
	}
	return *this;
}



int main(int argc , char** argv)
{
	std::cout << "Welcome to SimTown ! Please enter the street size" << std::endl; 
	int size{0};
	std::cin>>size;
	
	Building* street = new Building[size];
	for (int ib=0; ib<size ; ++ib)
	{
		street[ib]= Building(ib);
	}
	//Resize array 
	Building* bigger_street = new Building[size+1];
	for(int i=0; i<size ; ++i) 
		bigger_street[i]= street[i];
	delete[] street; 
	street=bigger_street;
	Building city_hall(1000);
	Building new_city_hall(city_hall); //Test Copy Constructor 
	street[size++]=new_city_hall;
	for (int i=0; i<size ; ++i)
	{

		street[i].print(std::cout);

	}
	delete[] street;
	std::cout << "Done"<<std::endl;
	return 0;
}