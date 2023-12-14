#ifndef ELECTRICITYDATA_H
#define ELECTRICITYDATA_H

#include <iostream>
#include <map>
#include "Date.h"
#include<vector>
class Electricity_Data {
private:
    map<Date, pair<double, double>> consumption_production_data;

public:
    Electricity_Data() : consumption_production_data{}{}
    // Add consumption and production data for a specific date
    void add_data(const Date& date, double consumption, double production);

    // Get consumption and production data for a specific date
    pair<double, double> get_data(const Date& date) const;

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

    double yearlyProduction(int year) const;
    double yearlyConsumption(int year) const;

    void delete_data(const Date& date);
    void update_data(const Date& date, double new_consumption, double new_production);

    bool search_date(const Date& date) const;

    vector<pair<Date, pair<double, double>>> get_data_in_range(const Date& start_date, const Date& end_date) const;

    // Retrieve consumption data for a specific month
    vector<pair<Date, double>> get_consumption_in_month(int year, int month) const;

    // Retrieve production data for a specific month
    vector<pair<Date, double>> get_production_in_month(int year, int month) const;

    // Retrieve consumption data for a specific year
    vector<pair<Date, double>> get_consumption_in_year(int year) const;

    // Retrieve production data for a specific year
    vector<pair<Date, double>> get_production_in_year(int year) const;

};



#endif