#ifndef ELECTRICITYDATA_H
#define ELECTRICITYDATA_H

#include <iostream>
#include <map>
#include "Date.h"
#include<vector>
#include "json.hpp"

using json = nlohmann::json;

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

    // Get the Map of Consumption and Production ** Needed for the in HouseHoldToJson **
    map<Date, pair<double, double>> get_consumption_production_data() const;

    // Calculate the average consumption over all dates
    double get_average_consumption() const ;

    // Calculate the average production over all dates
    double get_average_production() const ;

    // Calculate the average of the sum of consumption and production over all dates
    // double get_average_consumption_production() const ;

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

    vector<pair<Date, pair<double, double>>> get_data_in_range(int,int,int,int,int,int) const;
    vector<pair<Date, pair<double, double>>> getMonthlyData(int,int) const;
    vector<pair<Date, pair<double, double>>> getYearlyData(int) const;
    double getProductionInRange(int,int,int,int,int,int) const;
    double getConsumptionInRange(int,int,int,int, int,int) const;
    nlohmann::json ElectrecityDataToJson() const;
    static Electricity_Data ElecFromJson(const nlohmann::json &);
};

#endif

