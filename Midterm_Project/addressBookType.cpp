//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#include <iostream>
#include "addressBookType.h"

bool compareEntries(const extPersonType &a, const extPersonType &b){
    return a > b;
}

addressBookType::addressBookType(array<extPersonType, 500> entries) : entries(std::move(entries)) {}

void addressBookType::sortAddressBook()  {
    std::sort(entries.begin(), entries.end(), compareEntries);
}

extPersonType addressBookType::getByLastName(const std::string & lastName) const {
    for (extPersonType person : entries){
        if (person.getName().getLastName() == lastName){
            return person;
        }
    }
    throw PersonNotFound("Person with last name " + lastName + " not found in address book");
}

void addressBookType::printPerson(extPersonType& person) const {
    person.getAddress().printAddress();
    std::cout << "Phone number: " << person.getPhoneNumber();
    person.getDate().printDate();
};


void addressBookType::printBirthDayByMonth(int birthMonth) const{
    for (const extPersonType &person : entries) {
        if (person.getDate().getMonth() == birthMonth) {
            person.print();
        }
    }
}


void addressBookType::printBetweenNames(const std::string &lastOne, const std::string &lastTwo) {
    sortAddressBook();
    //Flag to indicate reached first lastname
    bool printName = false;

    for (const extPersonType &person : entries){
        if (person.getName().getLastName() == lastOne)
            printName = true;

        //If last name reached, print everyone
        if (printName)
            person.print();

        //When lastName > lastTwo, gone outside lastname range
        if (person.getName().getLastName() > lastTwo)
            return;
    }
}


void addressBookType::printByRelation(const std::string &relation) const {
    for (const extPersonType &person : entries){
        if (person.getRelation() == relation)
            person.getName().print();
    }
}

