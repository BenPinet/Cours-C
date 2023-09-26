#include <storey.h>
#include<iostream>


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