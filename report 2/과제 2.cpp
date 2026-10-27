#include <iostream>
using namespace std;

int main() {
    long long energy;
    long long maxAltitude;
    int steps = 0;

    // Enter the initial energy
    cout << "Enter initial energy: ";
    cin >> energy;

    // Check if the energy is positive
    if (energy <= 0) {
        cout << "Invalid energy!" << endl;
        return 0;
    }

    // Initialize the maximum energy
    maxAltitude = energy;

    cout << "\nEnergy Pattern: " << energy;

    // Repeat until the energy reaches 1
    while (energy != 1) {

        // Divide by 2 if the energy is even
        if (energy % 2 == 0) {
            energy = energy / 2;
        }

        // Multiply by 3 and add 1 if the energy is odd
        else {
            energy = energy * 3 + 1;
        }

        // Increase the step count
        steps++;

        // Update the maximum energy
        if (energy > maxAltitude) {
            maxAltitude = energy;
        }

        // Display the current energy
        cout << " -> " << energy;
    }

    // Display the final results
    cout << "\n\nEscape Successful!" << endl;
    cout << "Total Steps: " << steps << endl;
    cout << "Max Altitude: " << maxAltitude << endl;

    return 0;
}