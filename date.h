#ifndef Date_H
#define Date_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Date {
    private:
    int year;
    int month;
    int day;
    string weather;
    float maxTemp;
    float minTemp;
    int sunnyHour;

    public:
    //constructor   
    Date(int y, int m, int d, string w, float maxtemp, float mintemp, int sh){ 
        setYear(y);
        setMonth(m);
        setDay(d);
        setWeather(w);
        setMaxTemp(maxtemp);
        setMinTemp(mintemp);
        setSunnyHours(sh);
        }
        //Getters
        int getYear(){return this->year;}
        int getMonth(){return this->month;}
        int getDay(){return this->day;}
        string getWeather(){return this->weather;}
        float getMaxTemp(){return this->maxTemp;}
        float getMinTemp(){return this->minTemp;}
        int getSunnyHours(){return this->sunnyHour;}
        void getDate(){cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<"/n";}
        //Setters
        
        void setYear(int y){
            if (y > 0) {this->year=y;} else {cout << "Invalid Year! \n";}}
        
        void setMonth(int m){
            if ((m >=1 && m <=12)) {this->month=m;} else {cout << "Invalid Month! \
            Please enter a number between 1 and 12. \n";}}
        
        void setDay(int d){
            if((d>=1 && d<=31)){this->day=d;}else{cout << "Invalid Day! \
            Please enter a number between 1 and 31. \n";}}
        
        void setWeather(string w){
            if(!w.empty()) {this->weather=w;} else {cout << "Please enter valid weather.\n";}}
        
        void setMaxTemp(float maxtemp){
            if(maxtemp<=-20 && maxtemp>=60){this->maxTemp=maxtemp;} else {cout
            << "Invalid Maximum Temperature!\n";}}

        void setMinTemp(float mintemp){
            if(mintemp<-70 && mintemp>=50){this->minTemp=mintemp;} else {cout
            << "Invalid Minimum Temperature!\n";}}

        void setSunnyHours(int sh){
            if(sh>=0){this->sunnyHour=sh;} else {cout << "Invalid Sunny Hours!\n";}}

    void DisplayPerDAY(Date& Date) {
        cout << "The Year is :"<<Date.getYear()<<'\n';
        cout << "The Month is :"<<Date.getMonth()<<'\n';
        cout << "The Day is :"<<Date.getDay()<<'\n';
        cout << "The Weather is :"<<Date.getWeather()<<" !"<<'\n';
        cout << "The Maximum Temperature is :"<<Date.getMaxTemp()<<" Celsuis"<<'\n';
        cout << "The Minimum Temperature is :"<<Date.getMinTemp()<<" Celsius"<<'\n';
        cout << "The Sunny Hours are :"<<Date.getSunnyHours()<<" hours"<<'\n';
    };
       bool operator<(const Date& date)const {
          if(year < date.year) return true;
          else if(month < date.month) return true;
          else if(day < date.day) return true;
          else return false;
       }
    
};

#endif