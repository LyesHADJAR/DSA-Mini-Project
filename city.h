#include <iostream>
#include<string>
#include "district.h"
#include"Departement.h"
#include"BinarySearchTree.h"
using namespace std;

class City {
    private:
        string City_Name;
        BinarySearchTree<District> Citydistricts;
        Department Department_Of_This_City;
    public:
        City(string NewCity=""):City_Name{NewCity}{
            Department_Of_This_City.setDepartmentName(NewCity);
            
        }
        void setCityName(string City)
        {
            City_Name=City;
        }
        string getCityName()const {
            return City_Name;
        }
        void addDistrict(const District & NewDistrict) {
            Citydistricts.insert(NewDistrict);
        }
        District* findDistrict(const District & DistrictValue) {
    return Citydistricts.findNode(DistrictValue);
}
};
