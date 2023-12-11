#include "Country.h"

// Private helper function for hashing
int Country::country_hash(const std::string& country_name) {
    int hashValue = 0;

    for (char ch : country_name) {
        hashValue += static_cast<int>(ch);
    }

    hashValue = hashValue % 1000;
    hashValue = (hashValue == 0) ? 1 : hashValue;

    return hashValue;
}

// Constructor
Country::Country(const std::string& name) : countryName(name), countryID(country_hash(name)) {}

// Destructor
Country::~Country() = default;

// Copy constructor
Country::Country(const Country& other) = default;

// Move constructor
Country::Country(Country&& other) noexcept : countryName(std::move(other.countryName)), countryID(other.countryID) {}

// Copy assignment operator
Country& Country::operator=(const Country& other) {
    if (this != &other) {
        countryName = other.countryName;
        countryID = other.countryID;
    }
    return *this;
}

// Move assignment operator
Country& Country::operator=(Country&& other) noexcept {
    if (this != &other) {
        countryName = std::move(other.countryName);
        countryID = other.countryID;
    }
    return *this;
}

// Get country ID
long long int Country::getCountryID() const {
    return countryID;
}
