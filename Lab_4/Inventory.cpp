#include "Inventory.h"

Inventory::Inventory() {
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int itemNumber, int quantity, double cost){
    this->itemNumber = itemNumber;
    this->quantity = quantity;
    this->cost = cost;
    setTotalCost();
}

void Inventory::setItemNumber(int itemNumber_){
    itemNumber = itemNumber_;
}

void Inventory::setQuantity(int quantity_){
    quantity = quantity_;
    setTotalCost();
};
void Inventory::setCost(double cost_){
    cost = cost_;
    setTotalCost();
};


void Inventory::setTotalCost() {
    totalCost = quantity * cost;
}
