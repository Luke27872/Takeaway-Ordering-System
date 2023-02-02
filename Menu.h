#pragma once
#include <iostream>
#include <vector>
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include "ItemList.h"
#include "Item.h"

using namespace std;

class Menu: public ItemList {
public:
    //Stores a line from the menu file
    string fileLine;
    vector<string> temp;
    Menu(string menu);

    //Constructor for line split function;
    void lineSplit(string vectorSplit);

    //Constructor for printing out the menu
    void toString();
};
