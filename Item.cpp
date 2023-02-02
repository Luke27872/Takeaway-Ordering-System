#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

Item :: Item() {}

//Stores item information from a vector in a variable
Item :: Item(vector<string> itemInfo) {
    type = itemInfo[0];
    name = itemInfo[1];
    price = itemInfo[2];
    calories = itemInfo[3];
}

//Returns item information in correct format to be printed in the menu
string Item :: toString() {
    return (name + ": £" + price + ", " + calories + " cal");
}

//Returns items type to display instead of memory address
string Item :: getType() {
    return type;
}

//Returns items name to display instead of memory address
string Item :: getName() {
    return name;
}

//Returns items price to display instead of memory address
float Item ::getPrice() {
    return stof(price);
}
