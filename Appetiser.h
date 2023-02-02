#pragma once
#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

class Appetiser : public Item {
private:

    //Variables ready to store item information
    string shareable;
    string twoForOne;
public:
    //Constructor for storing item information into variables
    Appetiser(vector<string> itemInfo);

    //Returns item information in correct format to be printed in the menu
    string toString();
};