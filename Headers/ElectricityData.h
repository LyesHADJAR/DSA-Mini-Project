#ifndef ELECTRICITYDATA_H
#define ELECTRICITYDATA_H

#include <iostream>
#include <unordered_map>
#include "Date.h"
class Electricity_Data {
private:
    std::unordered_map<Date, std::pair<double, double>> consumption_production_data;

public:
    Electricity_Data();
    // Add consumption and production data for a specific date
    void add_data(const Date& date, double consumption, double production);

    // Get consumption and production data for a specific date
    std::pair<double, double> get_data(const Date& date) const;

    // Get consumption for a specific date
    double get_consumption(const Date& date) const ;

    // Get production for a specific date
    double get_production(const Date& date) const ;

    // Calculate the average consumption over all dates
    double get_average_consumption() const ;

    // Calculate the average production over all dates
    double get_average_production() const ;

    // Calculate the average of the sum of consumption and production over all dates
    double get_average_consumption_production() const ;

    // Get the total consumption for all dates
    double get_total_consumption() const ;

    // Get the total production for all dateas
    double get_total_production() const ;

    // Get the difference between total production and total consumption
    double get_production_consumption_difference() const ;

    double monthlyProduction(int year, int month) const;

    double monthlyConsumption(int year, int month) const;

};



#endif