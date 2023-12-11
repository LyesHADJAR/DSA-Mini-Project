#ifndef DATE_H
#define DATE_H
#include<iostream>
#include <ctime>
#include <stdexcept>
#include"../Headers/Weather.h"
using namespace std; 
class Date;

namespace std {
    template <>
    struct hash<Date>;

    template <>
    struct equal_to<Date>;
}

class Date {
    private:
        int Day;
        int Month;
        int Year;
        bool isLeapYear(int );
        void CurrentDay();
        Weather Day_Weather ;
    public:
    Date(int,int,int,const Weather &);
    Date();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    void setCurrentDate();
    Weather getWeatherInfo()const ;
    
    bool operator==(const Date& other) const {
        return Day == other.Day && Month == other.Month && Year == other.Year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // Adding a hash function for unordered_map
    struct HashFunction {
        std::size_t operator()(const Date& date) const {
            return std::hash<int>()(date.getDay()) ^ std::hash<int>()(date.getMonth()) ^ std::hash<int>()(date.getYear());
        }
    };

    friend struct std::hash<Date>;
    friend struct std::equal_to<Date>;
        
};



#endif