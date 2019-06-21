//Charles Dodge
//CIST 2362 CRN 63228
//Lab 10 Inventory Bin

#ifndef LAB_10_INVENTORY_H
#define LAB_10_INVENTORY_H

#include <string>

class Inventory {
private:
    int serialNum;
    std::string manufactDate;
    int lotNum;
public:
    //Constructors
    Inventory(); //Empty
    Inventory(int, const std::string&, int); //Full
    Inventory(const Inventory &); //Copy

    void setSerialNum(int serialNum_){
        this->serialNum = serialNum_;
    }
    int getSerialNum() {
        return serialNum;
    }

    void setManufactDate(const std::string &manufactDate_) {
        this->manufactDate = manufactDate_;
    }
    std::string getManufactDate() {
        return manufactDate;
    }

    void setLotNum(int lotNum_) {
        this->lotNum = lotNum_;
    }
    int getLotNum() {
        return lotNum;
    }
    void print();
};


#endif //LAB_10_INVENTORY_H
