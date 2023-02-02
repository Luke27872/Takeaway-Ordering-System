/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string userCommand;
    vector <string> parameters;

    // Create a menu object from a CSV file
    Menu menu = Menu("menu.csv");

    // Create an order object
    Order order = Order();

    cout << "[menu] [add] [remove] [checkout] [help] [exit]" << endl;
    cout << "Please enter a command:" << endl;


    while (userCommand != "exit")
    {
        getline(cin, userCommand);
        char* cstr = new char[userCommand.length() + 1];
        strcpy(cstr, userCommand.c_str());

        char* token;
        token = strtok(cstr, " ");

        while (token != NULL)
        {
            parameters.push_back(token);
            token = strtok(NULL, " ");
        }

        string command = parameters[0];

        if (command.compare("menu") == 0) {
            menu.toString();
        }
        else if (command.compare("add") == 0)
        {
            int userChoice;
            for (int i = 1; i < parameters.size(); i++) {
                userChoice = stoi(parameters[i]);
                if (userChoice > 0 && userChoice < menu.itemStore.size()+1) {
                    order.add(menu.itemStore[userChoice-1]);
                }
                else {
                    cout << "Please enter a valid item number from the menu:" << endl;
                }
            }
            //Item* choice; // you need to instantiate this using the menu object!
            //order.add(choice);

            // You may also wish to implement the ability to add multiple items at once!
            // e.g. add 1 5 9
        }
        else if (command.compare("remove") == 0)
        {
            int userChoice;
            userChoice = stoi(parameters[1]);
            order.remove(menu.itemStore[userChoice-1]);
        }
        else if (command.compare("checkout") == 0)
        {
            order.toString();
        }
        else if (command.compare("help") == 0)
        {
            cout << "menu           -> display the menu of food and drinks available for purchase" << endl;
            cout << "add [index]    -> add an item from the menu to your basket" << endl;
            cout << "remove [index] -> remove an item from your basket" << endl;
            cout << "checkout       -> display your basket ready for pruchase" << endl;
            cout << "exit           -> exit the program" << endl;
        }

        parameters.clear();

    }

    cout << "Press any key to quit...";
    std::getchar();

}
