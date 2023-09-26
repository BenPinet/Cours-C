#ifndef sim_town_building_h
#define sim_town_building_h
#include <storey.h>

class Building
{
public: 
	Building() : id_(-1),storeys_(nullptr), nb_storeys_(0){};
	Building(int identifier, int nb_floors=1);
	~Building();
	void print(std::ostream& ou);
	Building (const Building& rhs);
	Building& operator=(const Building& rhs);
	Storey* create_and_add_storey();
	
private:
	int id_;
	Storey* storeys_;
	int nb_storeys_;
	void clone_storeys(Storey* to , Storey* from); 
};

#endif