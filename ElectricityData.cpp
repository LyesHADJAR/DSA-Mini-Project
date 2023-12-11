#include"ElectricityData.h"



void Electricity_Data::add_data(const Date& date, double consumption, double production) {
        consumption_production_data[date] = std::make_pair(consumption, production);
    }

    // Get consumption and production data for a specific date
    std::pair<double, double> Electricity_Data::get_data(const Date& date) const {
        auto it = consumption_production_data.find(date);
        if (it != consumption_production_data.end()) {
            return it->second;
        } else {
            // Handle the case where data for the specified date is not found
            throw std::out_of_range("Data not found for the specified date.");
        }
    }

    // Get consumption for a specific date
    double Electricity_Data::get_consumption(const Date& date) const {
        return get_data(date).first;
    }

    // Get production for a specific date
    double Electricity_Data::get_production(const Date& date) const {
        return get_data(date).second;
    }

    // Calculate the average consumption over all dates
    double Electricity_Data::get_average_consumption() const {
        double sum = 0;
        for (const auto& data : consumption_production_data) {
            sum += data.second.first;
        }

        return (consumption_production_data.size() > 0) ? sum / consumption_production_data.size() : 0.0;
    }

    // Calculate the average production over all dates
    double Electricity_Data::get_average_production() const {
        double sum = 0;
        for (const auto& data : consumption_production_data) {
            sum += data.second.second;
        }

        return (consumption_production_data.size() > 0) ? sum / consumption_production_data.size() : 0.0;
    }

    // Calculate the average of the sum of consumption and production over all dates
    double Electricity_Data::get_average_consumption_production() const {
        double sum = 0;
        for (const auto& data : consumption_production_data) {
            sum += data.second.first + data.second.second;
        }

        return (consumption_production_data.size() > 0) ? sum / (2 * consumption_production_data.size()) : 0.0;
    }

    // Get the total consumption for all dates
    double Electricity_Data::get_total_consumption() const {
        double total_consumption = 0;
        for (const auto& data : consumption_production_data) {
            total_consumption += data.second.first;
        }
        return total_consumption;
    }

    // Get the total production for all dates
    double Electricity_Data::get_total_production() const {
        double total_production = 0;
        for (const auto& data : consumption_production_data) {
            total_production += data.second.second;
        }
        return total_production;
    }

    // Get the difference between total production and total consumption
    double Electricity_Data::get_production_consumption_difference() const {
        return get_total_production() - get_total_consumption();
    }