#include <iostream>
#include <string>

using namespace std;

class InventoryItem {
private:
    string itemName;
    double cost;
    int onHand;

public:
    InventoryItem(string name, double c, int oh) {
        itemName = name;
        cost = c;
        onHand = oh;
    }

    string getItemName() {
        return itemName;
    }

    double getCost() {
        return cost;
    }

    int getOnHand() {
        return onHand;
    }

    void setOnHand(int oh) {
        onHand = oh;
    }
};


class CashRegister {
private:
    InventoryItem item;
    int quantity;

public:
    CashRegister(InventoryItem i, int q) : item(i) {
        quantity = q;
    }

    double calculateSubtotal() {
        double unitPrice = item.getCost() * 1.30;
        return unitPrice * quantity;
    }

    double calculateTax(double subtotal) {
        return subtotal * 0.06;
    }

    void displayPurchase() {
        double subtotal = calculateSubtotal();
        double tax = calculateTax(subtotal);
        double total = subtotal + tax;

        cout << "\nPurchase Details:" << endl;
        cout << "-----------------" << endl;
        cout << "Item Name: " << item.getItemName() << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Purchase Subtotal: $" << subtotal << endl;
        cout << "Sales Tax (6%): $" << tax << endl;
        cout << "Total: $" << total << endl;

        int updatedOnHand = item.getOnHand() - quantity;
        item.setOnHand(updatedOnHand);
    }
};

int main() {
    InventoryItem laptop("Laptop", 800.0, 10);
    InventoryItem smartphone("Smartphone", 600.0, 15);
    InventoryItem headphones("Headphones", 100.0, 20);
    InventoryItem tablet("Tablet", 400.0, 5);

    cout << "Available Items:" << endl;
    cout << "1. Laptop - $800.00" << endl;
    cout << "2. Smartphone - $500.00" << endl;
    cout << "3. Headphones - $200.00" << endl;
    cout << "4. Tablet - $600.00" << endl;

    int choice, quantity;

    cout << "\nEnter the item number you want to purchase: ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Enter the quantity being purchased: ";
    cin >> quantity;

    if (quantity < 0) {
        cout << "Quantity cannot be negative." << endl;
        return 1;
    }

    CashRegister* register1;
    switch (choice) {
        case 1:
            register1 = new CashRegister(laptop, quantity);
            break;
        case 2:
            register1 = new CashRegister(smartphone, quantity);
            break;
        case 3:
            register1 = new CashRegister(headphones, quantity);
            break;
        case 4:
            register1 = new CashRegister(tablet, quantity);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    register1->displayPurchase();

    delete register1;
}

