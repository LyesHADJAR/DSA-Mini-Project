#ifndef REGION_H
#define REGION_H
#include <string>
#include "Country.h"

class Region {
private:
    std::string regionName;
    Country country;
    long long int CountryId = country.get
    long long int regionID = country. region_hash(regionName) * 1000000000;

    // Private helper function for hashing
    static int region_hash(const std::string&);

public:
    // Constructors
    explicit Region(const std::string&);

    // Destructor
    ~Region();

    // Copy constructor
    Region(const Region&);

    // Move constructor
    Region(Region&&) noexcept ;

    // Copy assignment operator
    Region& operator=(const Region&);

    // Move assignment operator
    Region& operator=(Region&&) noexcept;
};

#endif
