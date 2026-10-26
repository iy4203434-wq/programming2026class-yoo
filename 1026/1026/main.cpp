#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

//get a positive number
double inputpositive(const char* message) {
	double value;

	while (true) {
		cout << message;
		cin >> value;

		if (cin && value > 0)
			return value;

		cout << "value must be positive. try again.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

// calculate valtage
double calculatevoltage(double I, double R) {
	return I * R;
}

// calculate current
double calculatecurrent(double V, double R) {
	return V / R;
}

// calculate resistance
double calculateresistance(double V, double I) {
	return V / I;
}

//print calculation results
void printresult(double V, double I, double R) {
	double P = V * I;

	cout << fixed << setprecision(3);
	cout << "V = " << V << " V\n";
	cout << "I = " << I << " A\n";
	cout << "R = " << R << " ohm\n";
	cout << "P = " << P << " W\n";
}

// voltage mode
void voltagemode() {
	double I = inputpositive("current (A): ");
	double R = inputpositive("resistance (ohm): ");

	double V = calculatevoltage(I, R);
	printresult(V, I, R);
}

// current mode
void currentmode() {
	double V = inputpositive("voltage (V): ");
	double R = inputpositive("resistance (ohm): ");

	double I = calculatecurrent(V, R);
	printresult(V, I, R);
}

// resistance mode
void resistancemode() {
	double V = inputpositive("voltage (V): ");
	double I = inputpositive("current (A): ");
	double R = calculateresistance(V, I);
	printresult(V, I, R);
}

// display sweep table
void sweeptable() {
	double V = inputpositive("voltage (V): ");
	double R = inputpositive("resistance (ohm): ");

	cout << "V (V)\tI (A)\tR (ohm)\tP (W)\n";

		for (int i = 1; i <= 5; i++) {
			double voltage = V * i;
			double current = calculatecurrent(voltage, R);
			double power = voltage * current;

			cout << voltage << "\t"
				<< current << "\t"
				<< R << "\t"
				<< power << "\n";
		}
}

// display menu
void showmenu() {
	cout << "\n===== ohm's law calculator =====\n";
	cout << "1. Voltage 2. Current 3. Resistance"
	 	 << " 4. Sweep table 0. Exit\n";
	cout << "Select: ";
}

int main() {
	int choice;
	while (true) {
		showmenu();
		cin >> choice;
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid selection.\n";
			continue;
		}

		switch (choice) {
		case 1:
			voltagemode();
			break;

		case 2:
			currentmode();
			break;

		case 3:
			resistancemode();
			break;

		case 4:
			sweeptable();
			break;

		case 0:
			cout << "Exiting the program...\n";
			return 0;

		default:
			cout << "Invalid selection.\n";
		}
	}
}