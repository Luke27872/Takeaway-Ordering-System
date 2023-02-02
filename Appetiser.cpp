#include "Appetiser.h"
#include <iostream>
#include <vector>

using namespace std;

//Stores item information from a vector in a variable
Appetiser :: Appetiser(vector<string> itemInfo) {
    type = itemInfo[0];
    name = itemInfo[1];
    price = itemInfo[2];
    calories = itemInfo[3];
    shareable = itemInfo[4];
    twoForOne = itemInfo[5];
}
//Returns item information in correct format to be printed in the menu
string Appetiser :: toString() {

    //Detects if an item qualifies to be shareable or two for one
    if (shareable == "y" && twoForOne == "n") {
        return (name + ": £" + price + ", " + calories + " cal " + "(Shareable)");
    }
    else if (shareable == "n" && twoForOne == "y") {
        return (name + ": £" + price + ", " + calories + " cal " + "(2-4-1)");
    }
    else if (shareable == "n" && twoForOne == "n") {
        return (name + ": £" + price + ", " + calories + " cal ");
    }
    else {
        return (name + ": £" + price + ", " + calories + " cal " + "(Shareable)" + "(2-4-1)");
    }
}
