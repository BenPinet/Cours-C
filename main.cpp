#include <iostream>
#include<iostream>

class Building
{
public: 
	Building() : id_(-1) {};
	Building(int identifier);
	~Building();
	void print(std::ostream& ou);
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
Building& Building::operator=(const Building& rhs){
	if(this != &rhs ) 
	{
	id_=rhs.id_;
	}
	std::cout<<"Copy Done"<<std::endl;
	return *this;
}


int main(int argc , char** argv)
{
	std::cout << "Welcome to SimTown ! Please enter the street size" << std::endl; 
	int size{0};
	std::cin>>size;
	
	Building** street = new Building*[size];
	for (int ib=0; ib<size ; ++ib)
	{
		street[ib]=new Building(ib)
	}
	
	for (int i=0; i<size ; ++i)
	{
		if(street[i] != nullptr)
		{
			street[i]->print(std::cout);
		}
	}
	for (int i=0; i<size; ++i)
	{
		delete street[i];
	}
	delete[] street;
	std::cout << "Done"<<std::endl;
	return 0;
}