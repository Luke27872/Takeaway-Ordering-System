#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Menu ::Menu(string menu) {
    ifstream file;
    file.open(menu);

    //Splits the file line by line
    while (getline(file, fileLine)) {
        temp.clear();
        lineSplit(fileLine);
        if (temp[0] == "a") {

            //Stores a pointer of a new appetiser item
            Appetiser* p = new Appetiser(temp);
            itemStore.push_back(p);
        }
        else if (temp[0] == "m") {

            //Stores a pointer of a new main course item
            MainCourse* p = new MainCourse(temp);
            itemStore.push_back(p);
        }
        else if (temp[0] == "b") {

            //Stores a pointer of a new beverage item
            Beverage* p = new Beverage(temp);
            itemStore.push_back(p);
        }
    }
}

void Menu :: lineSplit(string vectorSplit) {
    string cell;

    //Splits each value in the line by a comma
    for (int i = 0; i <= vectorSplit.length(); i++) {
        if (vectorSplit[i] == ',' || i == vectorSplit.length()) {
            temp.push_back(cell);
            cell = "";
        }
        else {
            cell += vectorSplit[i];
        }
    }
}

//Prints the menu of items
void Menu ::toString() {
    cout << "---------------Appetisers---------------" << endl;
    int itemNo = 0;
    for(int i = 0; i < 3; i++) {

        //Seperates the menu by type and prints in correct format
        if (itemStore[itemNo] -> getType() == "a") {
            string itemNoStr = to_string(itemNo + 1);
            cout << "(" + itemNoStr + ") " + itemStore[itemNo] -> toString() << endl;
            itemNo++;
        }
    }
    cout << "--------------Main Courses--------------" << endl;
    for(int i = 0; i < 4; i++) {
        if (itemStore[itemNo] -> getType() == "m") {
            string itemNoStr = to_string(itemNo + 1);
            cout << "(" + itemNoStr + ") " + itemStore[itemNo] -> toString() << endl;
            itemNo++;
        }
    }
    cout << "---------------Beverages---------------" << endl;
    for(int i = 0; i < 5; i++) {
        if (itemStore[itemNo] -> getType() == "b") {
            string itemNoStr = to_string(itemNo + 1);
            cout << "(" + itemNoStr + ") " + itemStore[itemNo] -> toString() << endl;
            itemNo++;
        }
    }
}
