#pragma once
#include <vector>
#include "Item.h"

using namespace std;

class ItemList {
public:

    //Vector to store pointers of items
    vector<Item*> itemStore;

    //Returns a string
    virtual void toString() = 0;
    ItemList();
};
