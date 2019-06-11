//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_PERSONTYPE_H
#define MIDTERM_PROJECT_PERSONTYPE_H

#include <string>

class PersonType {
protected:
    std::string firstName;
    std::string lastName;
public:

    PersonType(std::string = "", std::string = "");

    void setName(std::string, std::string);

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    void print() const;


    //
    //Relational Operators
    //
    bool operator<(const PersonType &rhs) const;

    bool operator>(const PersonType &rhs) const;

    bool operator<=(const PersonType &rhs) const;

    bool operator>=(const PersonType &rhs) const;


};


#endif //MIDTERM_PROJECT_PERSONTYPE_H
