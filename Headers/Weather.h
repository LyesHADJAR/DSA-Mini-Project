#ifndef WEATHER_H
#define WEATHER_H
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;


enum Weather_Conditions {
    RAINY = 1,
    SUNNY,
    CLOUDY,
    SNOWY
    };

class Weather {
    private:
    Weather_Conditions CurrentCondition;
    double MaxTemperature ;
    double MinTemperature;
    double SunnyHours ;

    bool isValidWeatherCondition(const Weather_Conditions &) const ;
    void setMaxTemperatureHelper(const double &);
    void setMinTemperatureHelper(const double &);
    void setSunnyHoursHelper(const double &);
    string conditionToString(Weather_Conditions ) const ;

    public: 
    Weather(Weather_Conditions, double , double , double );
    Weather();
    void setWeatherConditions(const Weather_Conditions &);
    void setMaxTemperature(const double &);
    void setMinTemperature(const double &);
    void setSunnyHours(const double &);
    Weather_Conditions getWeatherConditions() const;
    double getMaxTemperature() const;
    double getMinTemperature() const;
    double getSunnyHours() const;


     bool operator==(const Weather& other) const {
        return CurrentCondition == other.CurrentCondition &&
               MaxTemperature == other.MaxTemperature &&
               MinTemperature == other.MinTemperature &&
               SunnyHours == other.SunnyHours;
    }

    bool operator!=(const Weather& other) const {
        return !(*this == other);
    }

    // Adding a hash function for unordered_map
    struct HashFunction {
        std::size_t operator()(const Weather& weather) const {
            return std::hash<int>()(static_cast<int>(weather.getWeatherConditions())) ^
                   std::hash<double>()(weather.getMaxTemperature()) ^
                   std::hash<double>()(weather.getMinTemperature()) ^
                   std::hash<double>()(weather.getSunnyHours());
        }
    };

    
};


#endif