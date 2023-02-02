#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Item {
public:
    Item();

    //Constructor for storing item information into variables
    Item(vector<string> itemInfo);

    //Variables ready to store item information
    string type;
    string name;
    string price;
    string calories;
    virtual string toString();

    //Constructors for returning display type not memory address
    string getType();
    //Constructors for returning display name not memory address
    string getName();
    //Constructors for returning display price not memory address
    float getPrice();
};