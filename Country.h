#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <unordered_map>
#include "Region.h"

class Country {
private:
    std::string countryName;
    long long int countryID = country_hash(countryName) * 1000000000000;
    std::unordered_map < long long int, Region > regionsOfCountry;

    // Private helper function for hashing
    static int country_hash(const std::string&);

public:
    // Constructors
    explicit Country(const std::string&);

    // Destructor
    ~Country();

    // Copy constructor
    Country(const Country&);

    // Move constructor
    Country(Country&&) noexcept ;

    // Copy assignment operator
    Country& operator=(const Country&);

    // Move assignment operator
    Country& operator=(Country&&) noexcept ;

    // Get Country ID
    long long int getCountryID() const;

};

#endif
