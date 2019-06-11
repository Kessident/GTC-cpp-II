//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_ADDRESSBOOKTYPE_H
#define MIDTERM_PROJECT_ADDRESSBOOKTYPE_H


#include "extPersonType.h"
#include <array>

class addressBookType {
private:
    std::array<extPersonType, 500> entries;
public:
    addressBookType(array<extPersonType, 500> entries);

    void sortAddressBook();
    extPersonType getByLastName(const std::string &) const;

    void printPerson(extPersonType&) const;

    void printBirthDayByMonth(int) const;

    void printBetweenNames(const std::string &, const std::string &);

    void printByRelation(const std::string &) const;




    class PersonNotFound : std::exception{
    private:
        std::string msg;
    public:
        PersonNotFound(std::string msg) : msg(std::move(msg)){};

        std::string getMsg(){
            return msg;
        };
    };
};


#endif //MIDTERM_PROJECT_ADDRESSBOOKTYPE_H
