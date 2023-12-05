#include <iostream>
#include <vector>
#include <algorithm>
#include "city.h"
using namespace std;

class Region {
    public:
    Region(const string&);
    void addCity(const City&);
    string getRegionName() const ;
    void setRegionName(string);
    //void sortDepartmentsByBudget() ;
    City* findCity(const City &) ;
    private:
    string RegionName;
    BinarySearchTree<City> RegionCities;
};

Region::Region(const string& name){
    RegionName = name;
}

void Region:: addCity(const City & NewCity) {
    RegionCities.insert(NewCity);
    //sortDepartmentsByBudget();
}

string Region::getRegionName()const {
    return RegionName; 
}
void Region::setRegionName(string Region){
    RegionName=Region;
}

City* Region::findCity(const City& CitytName) {
    
    return RegionCities.findNode(CitytName);
        
}

/*void Region::sortDepartmentsByBudget() {
        sort(regionDepartments.begin(), regionDepartments.end(), [](const Department& a, const Department& b) {
            return a.getBudget() < b.getBudget();
        });
}*/