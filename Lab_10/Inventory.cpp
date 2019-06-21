//Charles Dodge
//CIST 2362 CRN 63228
//Lab 10 Inventory Bin

#include <iostream>
#include "Inventory.h"

Inventory::Inventory() {
    serialNum = -1;
    manufactDate = "January 1, 1970";
    lotNum = -1;
}

Inventory::Inventory(int serialNum_, const std::string &manufactDate_ , int lotNum_) {
    this->serialNum = serialNum_;
    this->manufactDate = manufactDate_;
    this->lotNum = lotNum_;
}

Inventory::Inventory(const Inventory & obj) {
    this->serialNum = obj.serialNum;
    this->manufactDate = obj.manufactDate;
    this->lotNum = obj.lotNum;
}

void Inventory::print() {
    std::cout << "Serial Number: " << serialNum << std::endl;
    std::cout << "Manufacture Date: " << manufactDate << std::endl;
    std::cout << "Lot Number: " << lotNum << std::endl;
}