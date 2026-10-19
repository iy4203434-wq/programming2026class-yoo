# include <iostream>
using namespace std;

int main() {
	int n, type, minutes;
	int fee, discount;
	int total = 0;
	int maxfee = 0;
	int maxcar = 0;

	// Number of cars
	do {
		cout << "Number of cars (1~10): ";
		cin >> n;

		if (n < 1 || n > 10) {
			cout << " -> enter a number between 1 and 10" << endl;
		}
	} while (n < 1 || n > 10);

	for (int i = 1; i <= n; i++) {
		cout << "\n[Car " << i << "]" << endl;

		// vehicle type
		do {
			cout << "type (1: compact 2:regular 3: electric): ";
			cin >> type;

			if (type < 1 || type > 3) {
				cout << " -> invalid type. try again" << endl;
			}
		} while (type < 1 || type > 3);

		// parking time
		do {
			cout << "parking time (min): ";
			cin >> minutes;

			if (minutes < 0) {
				cout << " -> enter 0 or more" << endl;
			}
		} while (minutes < 0);

		//base fee
		if (minutes <= 30) {
			fee = 0;
		} else {
			fee = ((minutes - 30 + 9) / 10) * 500;
		}

		// maximum fee
		if (fee > 20000) {
			fee = 20000;
		}

		// discount
		discount = 0;

		if (type == 1) {
			discount = 50;
		} else if (type == 3) {
			discount = 30;
		}

		// apply discount
		fee = fee * (100 - discount) / 100;

		cout << "fee: " << fee
			<< "won (discount: " << discount << "%)" << endl;

		total += fee;

		// find highest fee
		if (i == 1 || fee > maxfee) {
			maxfee = fee;
			maxcar = i;
		}
	}

	cout << "\nTotal fee: " << total << "won" << endl;
	cout << "Highest fee: Car " << maxcar
		<< " (" << maxfee << " won)" << endl;

	return 0;
}