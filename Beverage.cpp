#include "Beverage.h"
#include <iostream>
#include <vector>

using namespace std;

//Stores item information from a vector in a variable
Beverage :: Beverage(vector<string> itemInfo) {
    type = itemInfo[0];
    name = itemInfo[1];
    price = itemInfo[2];
    calories = itemInfo[3];
    volume = itemInfo[6];
    abv = itemInfo[7];
}

//Returns item information in correct format to be printed in the menu
string Beverage ::toString() {

    //Detects if an item contains alcohol
    if (abv != "0" ) {
        return (name + ": £" + price + ", " + calories + " cal, " + volume + "ml, " + abv);
    }
    else {
        return (name + ": £" + price + ", " + calories + " cal" + volume);
    }
}