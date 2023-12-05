#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <vector>
#include <string>

class DATE{
    private:
    int year;
    int month;
    int day;
    std::string weather;
    float maxTemp;
    float minTemp;
    int sunnyHour;

    public:
    //constructor   
    DATE(int y, int m, int d, std::string w, float maxtemp, float mintemp, int sh){ 
        setYear(y);
        setMonth(m);
        setDay(d);
        setWeather(w);
        setMaxTemp(maxtemp);
        setMinTemp(mintemp);
        setSunnyHours(sh);
        }
        //Getters
        void getYear(){return this->year;}
        void getMonth(){return this->month;}
        void getDay(){return this->day;}
        void getWeather(){return this->weather;}
        void getMaxTemp(){return this->maxTemp;}
        void getMinTemp(){return this->minTemp;}
        void getSunnyHours(){return this->sunnyHour;}
        Date* getDate(){std::cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<"/n";}
        //Setters
        
        void setYear(int y){
            if (y > 0) {this->year=y;} else {std::cout << "Invalid Year! \n";}}
        
        void setMonth(int m){
            if ((m >=1 && m <=12)) {this->month=m;} else {std::cout << "Invalid Month! \
            Please enter a number between 1 and 12. \n";}}
        
        void setDay(int d){
            if((d>=1 && d<=31)){this->day=d;}else{std::cout << "Invalid Day! \
            Please enter a number between 1 and 31. \n";}}
        
        void setWeather(std::string w){
            if(!w.empty()) {this->weather=w;} else {std::cout << "Please enter valid weather.\n";}}
        
        void setMaxTemp(float maxtemp){
            if(maxtemp<=-20 && maxtemp>=60){this->maxTemp=maxtemp;} else {std::cout
            << "Invalid Maximum Temperature!\n";}}

        void setMinTemp(float mintemp){
            if(mintemp<-70 && mintemp>=50){this->minTemp=mintemp;} else {std::cout
            << "Invalid Minimum Temperature!\n";}}

        void setSunnyHours(int sh){
            if(sh>=0){this->sunnyHour=sh;} else {std::cout << "Invalid Sunny Hours!\n
            ";}}

    void DisplayPerDAY(DATE& date) {
        std::cout << "<-----------------"<<date<<"----------------->"<<'\n';
        std::cout << "The Year is :"<<date.getYear()<<'\n';
        std::cout << "The Month is :"<<date.getMonth()<<'\n';
        std::cout << "The Day is :"<<date.getDay()<<'\n';
        std::cout << "The Weather is :"<<date.getWeather()<<" !"<<'\n';
        std::cout << "The Maximum Temperature is :"<<date.getMaxTemp()<<" Celsuis"<<'\n';
        std::cout << "The Minimum Temperature is :"<<date.getMinTemp()<<" Celsius"<<'\n';
        std::cout << "The Sunny Hours are :"<<date.getSunnyHours()<<" hours"<<'\n';
    };
    
};
#endif