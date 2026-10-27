#include <iostream>
using namespace std;

int main() {
    int birthdate;
    int number, sum;

    // Enter the 8-digit birthdate
    cout << "Enter your 8-digit birthdate (YYYYMMDD): ";
    cin >> birthdate;

    cout << "Calculating..." << endl;

    number = birthdate;

    // Repeat until the number becomes a single digit
    while (number >= 10) {
        sum = 0;

        // Calculate the sum of each digit
        while (number > 0) {
            sum += number % 10;  // Add the last digit
            number /= 10;        // Remove the last digit
        }

        // Display the sum of digits
        cout << "Sum of digits: " << sum << endl;

        number = sum;
    }

    // Display the final destiny number
    cout << "\nYour Destiny Number is "
         << number << "!" << endl;

    cout << "\n[Destiny Message]" << endl;

    // Display the message using a switch statement
    switch (number) {
        case 1:
            cout << "You are a natural leader!";
            break;
        case 2:
            cout << "You are kind and caring!";
            break;
        case 3:
            cout << "You are creative and cheerful!";
            break;
        case 4:
            cout << "You are honest and hardworking!";
            break;
        case 5:
            cout << "You love freedom and adventure!";
            break;
        case 6:
            cout << "You are responsible and loving!";
            break;
        case 7:
            cout << "You are an analytical thinker!";
            break;
        case 8:
            cout << "You are confident and ambitious!";
            break;
        case 9:
            cout << "You are generous and wise!";
            break;
        default:
            cout << "Invalid destiny number!";
    }

    cout << endl;

    return 0;
}