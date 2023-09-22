#include <iostream>
#include<iostream>
class Storey{
public:
	Storey() : source_(serial_number_),uid_(serial_number_){
		std::cout<<"Storey::Storey ("<<uid_<<") at " <<this <<std::endl;
	};
	Storey(const Storey& rhs);
	~Storey() {};
	Storey& operator=(const Storey& rhs);
	friend std::ostream& operator<< (std::ostream& out , const Storey& rhs);
	
private:
	int uid_;
	int source_;
	static int serial_number_; 
};
 int Storey::serial_number_=1;
 
 
 
 Storey::Storey ( const Storey& rhs) : source_(rhs.source_), uid_(serial_number_++)
 {
	 std::cout << "Storey::Storey(rhs = id = " << rhs.uid_ << "), uid= " << uid_<< "at" << this << std::endl;
 }
 
 Storey& Storey::operator=(const Storey& rhs){
	 if (this != &rhs){
		 source_=rhs.source_;
		 uid_=serial_number_++;	 
	 }
	 return *this;
 }
 
 std::ostream& operator<<(std::ostream& out, const Storey& storey){
		out << "--Storey" << &storey << " : id=" << storey.uid_<<", NFT="<< storey.source_;
		return out;
 }
 
class Building
{
public: 
	Building() : id_(-1),storeys_(nullptr), nb_storeys_(0){};
	Building(int identifier, int nb_floors);
	~Building();
	void print(std::ostream& ou);
	Building (const Building& rhs);
	Building& operator=(const Building& rhs);
private:
	int id_;
	Storey* storeys_;
	int nb_storeys_;
};

Building::Building(int identifier,int nb_floors=1) : id_(identifier), storeys_(nullptr), nb_storeys_(nb_floors) {
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
	for (int is=0; is<rhs.nb_storeys_ ; ++is)
	{
		storeys_[is]=rhs.storeys_[is];
	}
	std::cout << "Copie de Building" <<  "dans le building" << id_ << std::endl;
}
Building& Building::operator=(const Building& rhs){
	if(this != &rhs ) 
	{
	id_=rhs.id_;
	nb_storeys_=rhs.nb_storeys_;
	delete[] storeys_;
	storeys_=new Storey[nb_storeys_];
	for (int is=0; is<rhs.nb_storeys_ ; ++is)
	{
		storeys_[is]=rhs.storeys_[is];
	}
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