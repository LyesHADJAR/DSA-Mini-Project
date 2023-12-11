#ifndef DISTRICT_H
#define DISTRICT_H
#include <string>

class District {
private:
    std::string districtName;
    unsigned int districtID;

    // Private helper function for hashing
    static int district_hash(const std::string&);

public:
    // Constructors
    explicit District(const std::string&);

    // Destructor
    ~District();

    // Copy constructor
    District(const District&);

    // Move constructor
    District(District&&) noexcept ;

    // Copy assignment operator
    District& operator=(const District&);

    // Move assignment operator
    District& operator=(District&&) noexcept ;
};

#endif

