//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_ADDRESSTYPE_H
#define MIDTERM_PROJECT_ADDRESSTYPE_H


#include <string>

class addressType {
private:
    std::string streetAddress;
    std::string city;
    std::string state;
    int ZIPCode;
public:
    addressType(const std::string &streetAddress = "", const std::string &city = "", const std::string &state = "", int zipCode = 0);

    void setAddress(const std::string &streetAddress = "", const std::string &city = "", const std::string &state = "", int zipCode = 0);

    const std::string &getStreetAddress() const;

    const std::string &getCity() const;

    const std::string &getState() const;

    int getZipCode() const;

    void printAddress() const;

    //
    //Relational Operators
    //
    bool operator<(const addressType &rhs) const;

    bool operator>(const addressType &rhs) const;

    bool operator<=(const addressType &rhs) const;

    bool operator>=(const addressType &rhs) const;
};


#endif //MIDTERM_PROJECT_ADDRESSTYPE_H
