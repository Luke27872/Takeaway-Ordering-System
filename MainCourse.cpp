#include "MainCourse.h"
#include <iostream>
#include <vector>

using namespace std;

//Stores item information from a vector in a variable
MainCourse ::MainCourse(vector<string> itemInfo) {
    type = itemInfo[0];
    name = itemInfo[1];
    price = itemInfo[2];
    calories = itemInfo[3];
}

//Returns item information in correct format to be printed in the menu
string MainCourse ::toString() {
    return (name + ": £" + price + ", " + calories + " cal");
}