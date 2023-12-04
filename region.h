#include <iostream>
#include <vector>
#include <algorithm>
#include "department.h"
using namespace std;

class Region {
    public:
    Region(const string&);
    void addDepartment(const Department&);
    string getRegionName() const ;
    Department* findDepartment(const string& departmentName); 
    void sortDepartmentsByBudget() ;

    private:
    string regionName;
    vector<Department> regionDepartments;
};

Region::Region(const string& name){
    regionName = name;
}

void Region:: addDepartment(const Department& dep) {
    regionDepartments.push_back(dep);
    sortDepartmentsByBudget();
}

string Region::getRegionName()const {
    return regionName; 
}

Department* Region::findDepartment(const string& departmentName) {
        auto it = find_if(regionDepartments.begin(), regionDepartments.end(), [&](const Department& dep) {
            return dep.getName() == departmentName;
        });
        if (it != regionDepartments.end()) {
            return &(*it);
        }
        return nullptr;
}

void Region::sortDepartmentsByBudget() {
        sort(regionDepartments.begin(), regionDepartments.end(), [](const Department& a, const Department& b) {
            return a.getBudget() < b.getBudget();
        });
}