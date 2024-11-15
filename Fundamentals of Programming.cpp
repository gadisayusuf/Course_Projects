#include <iostream>
#include <string>
using namespace std;

// Structure to represent a stock item
struct StockItem {
    string itemName;
    int quantity;
    double price;
};

// Function to display stock details
void displayStock(StockItem stock[], int size) {
    cout << "Stock Details:\n";
    cout << "--------------------------------------\n";
    cout << "Item Name\tQuantity\tPrice\n";
    cout << "--------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        cout << stock[i].itemName << "\t\t" << stock[i].quantity << "\t\t$" << stock[i].price << endl;
    }

    cout << "--------------------------------------\n";
}

// Function to update stock quantity
void updateStock(StockItem stock[], int size, string itemName, int newQuantity) {
    for (int i = 0; i < size; ++i) {
        if (stock[i].itemName == itemName) {
            stock[i].quantity = newQuantity;
            cout << "Stock quantity updated successfully.\n";
            return;
        }
    }

    cout << "Item not found in stock.\n";
}

// Function to add a new item to stock
void addItem(StockItem stock[], int& size, string itemName, int quantity, double price) {
    if (size < MAX_STOCK) {
        stock[size] = {itemName, quantity, price};
        size++;
        cout << "Item added to stock successfully.\n";
    } else {
        cout << "Cannot add more items. Stock is full.\n";
    }
}

// Function to update the price of an existing item
void updatePrice(StockItem stock[], int size, string itemName, double newPrice) {
    for (int i = 0; i < size; ++i) {
        if (stock[i].itemName == itemName) {
            stock[i].price = newPrice;
            cout << "Item price updated successfully.\n";
            return;
        }
    }

    cout << "Item not found in stock.\n";
}

int main() {
    const int MAX_STOCK = 10;
    StockItem stock[MAX_STOCK];
    int size = 3; // Initial stock size

    // Initialize stock
    stock[0] = {"Item1", 20, 10.5};
    stock[1] = {"Item2", 15, 8.75};
    stock[2] = {"Item3", 30, 5.25};

    int choice;

    do {
        cout << "\nStock Management System\n";
        cout << "1. Display Stock\n";
        cout << "2. Update Stock Quantity\n";
        cout << "3. Add New Item\n";
        cout << "4. Update Item Price\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayStock(stock, size);
                break;
            case 2:
                {
                    string itemName;
                    int newQuantity;

                    cout << "Enter item name: ";
                    cin >> itemName;
                    cout << "Enter new quantity: ";
                    cin >> newQuantity;

                    updateStock(stock, size, itemName, newQuantity);
                }
                break;
            case 3:
                {
                    string itemName;
                    int quantity;
                    double price;

                    cout << "Enter item name: ";
                    cin >> itemName;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    cout << "Enter price: $";
                    cin >> price;

                    addItem(stock, size, itemName, quantity, price);
                }
                break;
            case 4:
                {
                    string itemName;
                    double newPrice;

                    cout << "Enter item name: ";
                    cin >> itemName;
                    cout << "Enter new price: $";
                    cin >> newPrice;

                    updatePrice(stock, size, itemName, newPrice);
                }
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
