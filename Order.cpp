#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"
#include <iomanip>

using namespace std;

Order :: Order() {}

//Calculates total price of the order
float Order ::calculateTotal(float itemPrice) {

    //Adds each item in the order together
    totalPrice = totalPrice + itemPrice;
}

//Writes order details to a text file
void Order ::printReceipt() {

    //Opens the file ready to write too
    ofstream receipt;
    receipt.open("receipt.txt");
    receipt << "Your order:" << endl;

    //Writes the ordered items and total price to the file
    for (int i = 0; i < orderedItems.size(); i++) {

        receipt << orderedItems[i]->getName() + ": £";
        receipt << orderedItems[i]->getPrice() << endl;
    }
    receipt << setprecision(3) << "Total: £" + to_string(totalPrice) << endl;
    receipt << "Thank you for ordering with us!" << endl;
    receipt.close();
    cout << "Receipt printed, thank you for your order!" << endl;
    exit(0);
}

//Prints all the items the user added to the order
void Order :: toString() {
    string confirmOrder;
    cout << "===============Checkout===============" << endl;
    for (int i = 0; i < orderedItems.size(); i++) {

        cout << orderedItems[i]->getName() + ": £";
        cout << orderedItems[i]->getPrice() << endl;
        calculateTotal(orderedItems[i]->getPrice());
    }

    //Prints the total price of all the items added to the order
    cout << "Total: £" + to_string(totalPrice) << endl;
    cout << "Do you want to place your order?" << endl;
    cout << "Type 'y' to confirm, or 'n' to go back and modify it." << endl;
    cin >> confirmOrder;
    if (confirmOrder == "y") {
        printReceipt();
    }
    else if (confirmOrder == "n") {
        return;
    }
}
void Order :: add(Item* addedItem) {

    //Places the user selected item into a vector of ordered items
    orderedItems.push_back(addedItem);
    cout << (addedItem -> getName() + " was added to your basket!") << endl;
}

//Removes an item from the items ordered vector
void Order :: remove(Item* removedItem) {
    for (int i = 0; i < orderedItems.size(); i++) {
        if (removedItem->getName() == orderedItems[i]->getName()){
            orderedItems.erase(orderedItems.begin() + i);
            cout << (removedItem -> getName() + " was removed from your basket!") << endl;
        }
        else {
            cout << "This item is not in your basket" << endl;
        }
    }

}