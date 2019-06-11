//
// Created by Charles Dodge on 2019-05-22.
//

#ifndef LAB_4_INVENTORY_H
#define LAB_4_INVENTORY_H

class Inventory {
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
public:

    Inventory();
    Inventory(int itemNumber, int quantity, double cost);

    int getItemNumber() const
    { return itemNumber; };
    void setItemNumber(int);

    int getQuantity() const
    { return quantity; };
    void setQuantity(int);

    double getCost() const
    { return cost; };
    void setCost(double);

    double getTotalCost() const
    { return totalCost; };
    void setTotalCost();
};

#endif //LAB_4_INVENTORY_H