#include"../Headers/Weather.h"



string Weather::conditionToString(Weather_Conditions condition) const {
        switch (condition) {
            case RAINY:
                return "RAINY";
            case SUNNY:
                return "SUNNY";
            case CLOUDY:
                return "CLOUDY";
            case SNOWY:
                return "SNOWY";
            default:
                return "UNKNOWN";
        }
    }
    bool Weather::isValidWeatherCondition(const Weather_Conditions &condition) const {
        return condition >= RAINY && condition <= SNOWY;
    }
Weather::Weather(Weather_Conditions Condition, double Max_Temp, double Min_Temp, double SUNNY_H) {
    setWeatherConditions(Condition);
    setMaxTemperature(Max_Temp);
    setMinTemperature(Min_Temp);
    setSunnyHours(SUNNY_H);
}

Weather::Weather() {
    setWeatherConditions(Weather_Conditions::SUNNY);
    setMaxTemperature(0);
    setMinTemperature(0);
    setSunnyHours(0);
    }


    
void Weather::setWeatherConditions(const Weather_Conditions &condition ){
    
            if (!isValidWeatherCondition(condition)) {
                throw std::invalid_argument("Invalid weather condition.");
            }

            CurrentCondition = condition;
            std::cout << "Weather condition set to: " << conditionToString(CurrentCondition) << std::endl;
        
}
    void Weather::setMaxTemperatureHelper(const double & Value){
        
            if(Value>=60 || Value <=-90)
            {
                throw std::invalid_argument("Invalid temperature value.");
                
            }
            MaxTemperature = Value;

        
    }
    
    void Weather::setMinTemperatureHelper(const double & Value){
        
            if(Value>=60 || Value <=-90)
            {
                throw std::invalid_argument("Invalid temperature value.");
                
            }
            MinTemperature = Value;

        
    }
    void Weather::setSunnyHoursHelper(const double & Value){
        
            if(Value >=15 || Value <0)
            {
                throw std::invalid_argument("Invalid sunny hours value.");
                }
                SunnyHours = Value;
    }


    void Weather::setMaxTemperature(const double & Value) {
        setMaxTemperatureHelper(Value);
    }
    void Weather::setMinTemperature(const double &Value) {
        setMinTemperatureHelper(Value);
    }
    void Weather::setSunnyHours(const double & Value) {
        setSunnyHoursHelper(Value);
    }
    Weather_Conditions Weather::getWeatherConditions() const {
        return CurrentCondition;
    }
    double Weather::getMaxTemperature() const {
        return MaxTemperature;
    }
    double Weather::getMinTemperature() const  {
        return MinTemperature;
    }

    double Weather::getSunnyHours() const {
        return SunnyHours ;
    }