#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_BILLS = 1000;
const vector<int> DENOMINATIONS = {5000, 2000, 1000, 500, 200, 100};

int bills[6] = {0};
int totalAmount = 0;

void loadATM() {
    ifstream infile("atm_state.bin", ios::binary);
    if (infile) {
        for (int i = 0; i < 6; ++i) {
            infile.read((char*) &bills[i], sizeof(bills[i]));
        }
        infile.read((char*) &totalAmount, sizeof(totalAmount));
        infile.close();
    } else {
        cout << "ATM is empty." << endl;
    }
}

void saveATM() {
    ofstream outfile("atm_state.bin", ios::binary);
    for (int i = 0; i < 6; ++i) {
        outfile.write((char*) &bills[i], sizeof(bills[i]));
    }
    outfile.write((char*) &totalAmount, sizeof(totalAmount));
    outfile.close();
}

void fillATM() {
    srand(time(0));
    for (int i = 0; i < 6; ++i) {
        int randomBills = rand() % (MAX_BILLS - totalAmount / DENOMINATIONS[i]) + 1;
        bills[i] += randomBills;
        totalAmount += randomBills * DENOMINATIONS[i];
    }
    cout << "ATM is filled." << endl;
}

bool withdraw(int amount) {
    if (amount > totalAmount) {
        cout << "Not enough money in the ATM." << endl;
        return false;
    }

    for (int i = 0; i < 6; ++i) {
        while (amount >= DENOMINATIONS[i] && bills[i] > 0) {
            amount -= DENOMINATIONS[i];
            bills[i]--;
            totalAmount -= DENOMINATIONS[i];
        }
    }

    if (amount > 0) {
        cout << "Unable to withdrawal this exact amount." << endl;
        return false;
    }

    return true;
}

void printATMState() {
    cout << "Current ATM state:" << endl;
    for (int i = 0; i < 6; ++i) {
        cout << DENOMINATIONS[i] << " rubles: " << bills[i] << endl;
    }
    cout << "Current sum: " << totalAmount << " rubles." << endl;
}

int main() {
    loadATM();
    printATMState();

    string command;
    while (true) {
        cout << "Enter command (+ to input money, - for withdrawal, q to exit): ";
        cin >> command;

        if (command == "+") {
            fillATM();
            printATMState();
        } else if (command == "-") {
            int amount;
            cout << "Enter sum for withdrawal: ";
            cin >> amount;
            if (withdraw(amount)) {
                printATMState();
            }
        } else if (command == "q") {
            saveATM();
            break;
        } else {
            cout << "Incorrect command." << endl;
        }
    }

    return 0;
}