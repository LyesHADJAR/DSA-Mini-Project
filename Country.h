#ifndef COUNTRY_H   
#define COUNTRY_H

#include <iostream>
#include <string>
#include <list>
#include "City"
using namespace std;


class Country{
    private:
    unsigned countryID;
    std::string countryName;
    list<City> CiyList;
    public:
    Country(unsigned id, string name);
    Country(const Country& c);
    ~Country();
    unsigned getID();
    string getName();
    list<City> getCities();
    void addCity(City c);
    void removeCity(City c);
    void print();
};


Country::Country(unsigned id, string name){
    countryID = id;
    countryName = name;
};

Country::Country(const Country& c){
    countryID = c.countryID;
    countryName = c.countryName;
    CiyList = c.CiyList;
};

Country::~Country(){
    CiyList.clear();
    cout<<setw(10)<<"Thank you for visiting "<<countryName<<" !"<<endl;
};

void setcountryName(string countryN){
    countryName = countryN; 
};

unsigned Country::getID(){
    return countryID;
};

string Country::getName(){
    return countryName;
};

list<City> Country::getCities(){
    return CiyList;
};

void Country::addCity(City c){
    CiyList.push_back(c);
};

void Country::removeCity(City c){
    CiyList.remove(c);
};

void Country::print(){
    cout << setw( 15 ) << "Country ID: " << countryID << setw( 15 ) << " Country Name: "<< countryName << endl;
    list<City>::iterator it;
    for(it = CiyList.begin(); it != CiyList.end(); it++){
        cout << setw( 15 ) << "City ID: " << it->getID() << setw( 15 ) << " CityName: "<< it->getName() << endl;
    }
    cout <<"\n";
};
