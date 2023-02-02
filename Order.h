#pragma once
#include "ItemList.h"
#include <iostream>
#include <vector>

using namespace std;

class Order : public ItemList {
public:

    //Constructor for adding an item to the order
    void add(Item* addedItem);

    //Contructor for removing an item from the order
    void remove(Item* removedItem);

    //Vector to store user selected items to be added to order
    vector<Item*> orderedItems;
    Order();
    void toString();
    void printReceipt();

    //Stores value for total price of added items
    float totalPrice = 0.00;

    //Contructor for calculating total price of added items
    float calculateTotal(float itemPrice);
};


