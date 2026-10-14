#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int choice, price, money, coin, change;
	int count = 0;
	int totalsales = 0;

	while (true) {
		cout << "\n***** vending machine *****" << endl;
		cout << "1. cola(1200won) 2. cider(1100won) "
			<< "3. coffee(800won) 0. exit" << endl;

			cout << "select: ";
		cin >> choice;

		if (choice == 0) {
			break;
		}

		if (choice == 1) {
			price = 1200;
		}
		else if (choice == 2) {
			price = 1100;
		}
		else if (choice == 3) {
			price = 800;
		}
		else {
			cout << "invalid selection" << endl;
			continue;
		}

		money = 0;

		while (money < price) {
			cout << "insert (current " << money
				<< "won / required " << price << "won): ";
			cin >> coin;

			if (coin == 100 || coin == 500 || coin == 1000) {
				money += coin;
			}
			else {
				cout << " -> cannot use " << coin << "won" << endl;
			}
		}

		change = money - price;

		cout << "drink dispensed! change:"
			<< change << "won" << endl;

		if (change == 0) {
			cout << "no change" << endl;
		}
		else {
			int coin500 = change / 500;
			int coin100 = (change % 500) / 100;

			cout << "500won: " << setfill('0')
				<< setw(2) << coin500 << endl;
			cout << "100won: " << setfill('0')
				<< setw(2) << coin100 << endl;

			cout << setfill(' ');
		}

		count++;
		totalsales += price;
	}

	cout << "total sold:" << count
		<< ", sales: " << totalsales << "won" << endl;

	return 0;

}