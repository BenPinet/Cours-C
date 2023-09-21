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
	int index{-99};
	Building* street[10];
	for (int i=0; i<10 ; ++i)
	{
		street[i]=nullptr;
	}
	std::cin >> index;
	int counter{0};
	while(index != -99 && counter< 10)
	{
		street[counter]= new Building(index);
		std::cin >> index; 
		counter++;
	}
	for (int i=0; i<10 ; ++i)
	{
		if(street[i] != nullptr)
		{
			street[i]->print(std::cout);
		}
	}
	for (int i=0; i<10 ; ++i)
	{
		delete street[i];
	}
	std::cout << "Done"<<std::endl;
	return 0;
}