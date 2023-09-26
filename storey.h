#ifndef sim_town_storey_h
#define sim_town_storey_h
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
#endif 
