#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const double g = 9.81;

// Get a positive number
double inputPositive(const char* message) {
    double value;

    while (true) {
        cout << message;
        cin >> value;

        if (cin && value > 0)
            return value;

        cout << "Value must be positive. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Calculate kinetic energy
double kineticEnergy(double m, double v) {
    return 0.5 * m * v * v;
}

// Calculate potential energy
double potentialEnergy(double m, double h) {
    return m * g * h;
}

// Print energy result
void printEnergy(double energy) {
    cout << fixed << setprecision(3);
    cout << "Energy = " << energy << " J";

    if (energy >= 1000) {
        cout << " (" << energy / 1000 << " kJ)";
    }

    cout << "\n";
}

// Kinetic energy mode
void kineticMode() {
    double m = inputPositive("Mass (kg): ");
    double v = inputPositive("Speed (m/s): ");

    double energy = kineticEnergy(m, v);
    printEnergy(energy);
}

// Potential energy mode
void potentialMode() {
    double m = inputPositive("Mass (kg): ");
    double h = inputPositive("Height (m): ");

    double energy = potentialEnergy(m, h);
    printEnergy(energy);
}

// Display free-fall energy table
void freeFallTable() {
    double m = inputPositive("Mass (kg): ");
    double h = inputPositive("Start height (m): ");

    double total = potentialEnergy(m, h);
    double step = h / 5.0;

    cout << fixed << setprecision(3);
    cout << "h(m)\tPE(J)\tKE(J)\tTotal(J)\n";

    for (int i = 0; i <= 5; i++) {
        double height = h - step * i;
        double PE = potentialEnergy(m, height);
        double KE = total - PE;

        cout << height << "\t"
             << PE << "\t"
             << KE << "\t"
             << total << "\n";
    }
}

// Display menu
void showMenu() {
    cout << "\n===== Mechanical Energy Calculator =====\n";
    cout << "1. Kinetic energy  2. Potential energy"
         << "  3. Free-fall table  0. Exit\n";
    cout << "Select: ";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid selection.\n";
            continue;
        }

        switch (choice) {
        case 1:
            kineticMode();
            break;

        case 2:
            potentialMode();
            break;

        case 3:
            freeFallTable();
            break;

        case 0:
            cout << "Exiting the program...\n";
            return 0;

        default:
            cout << "Invalid selection.\n";
        }
    }
}