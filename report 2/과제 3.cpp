#include <iostream>
using namespace std;

// Define the original prices of items
#define RED_POTION 1000
#define MAGIC_SCROLL 2000
#define ELIXIR 3000

int main() {
    int balance;
    int choice;
    int price;
    int count = 0;
    const char* itemName = "";

    // Enter the initial balance
    cout << "Insert coins (Current Balance): ";
    cin >> balance;

    // Display the vending machine menu once
    cout << "\n--- Goblin's Vending Machine ---" << endl;
    cout << "1. Red Potion (1000 G)" << endl;
    cout << "2. Magic Scroll (2000 G)" << endl;
    cout << "3. Elixir (3000 G)" << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------" << endl;

    // Repeat item selection until the user exits
    while (true) {

        // Select an item
        cout << "\nSelect an item: ";
        cin >> choice;

        // Exit the vending machine
        if (choice == 0) {
            cout << "Returning " << balance
                 << " G. Goodbye!" << endl;
            break;
        }

        // Set the price and name of the selected item
        switch (choice) {
            case 1:
                price = RED_POTION;
                itemName = "Red Potion";
                break;

            case 2:
                price = MAGIC_SCROLL;
                itemName = "Magic Scroll";
                break;

            case 3:
                price = ELIXIR;
                itemName = "Elixir";
                break;

            default:
                cout << "Invalid selection!" << endl;
                continue;
        }

        // Check if the next purchase is a multiple of 3
        bool discount = ((count + 1) % 3 == 0);

        // Apply a 50% discount on every third purchase
        if (discount) {
            price = price / 2;
        }

        // Check if the balance is sufficient
        if (balance < price) {
            cout << "Not enough balance!" << endl;
            continue;
        }

        // Display the discount message
        if (discount) {
            cout << "*** GOBLIN'S BLESSING! "
                 << "50% DISCOUNT! ***" << endl;
        }

        // Deduct the price from the balance
        balance -= price;

        // Increase the successful purchase count
        count++;

        // Display the purchase result
        if (discount) {
            cout << "[Purchased] " << itemName
                 << " for " << price
                 << " G. Balance: " << balance
                 << " G" << endl;
       } 
        else {
            cout << "[Purchased] " << itemName
                 << ". Balance: " << balance
                << " G" << endl;
        }
    }
    return 0;
}