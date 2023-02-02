#pragma once
#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

class MainCourse : public Item {
public:

    //Constructor for storing item information into variables
    MainCourse(vector<string> itemInfo);

    //Returns item information in correct format to be printed in the menu
    string toString();
};
