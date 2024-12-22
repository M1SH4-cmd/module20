#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayATMState(int money[1000], int bills[5]) {
    int totalAmount = 0;
    std::cout << "Current ATM state:\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << "Banknotes " << money[i] << " rubles: " << money[i] << "\n";
        totalAmount += money[i] * bills[i];
    }
    std::cout << "Current sum: " << totalAmount << " rubles\n";
}

int main()
{
    int bills[5] = {100, 200, 500, 1000, 5000};
    int money[1000];

    cout << "Operation:";
    string op;
    cin >> op;

    ifstream file_in("..\\money.bin");
    if (file_in.is_open()) {
        file_in.read((char*) money, sizeof(money));
        file_in.close();
    } else {
        for (int i = 0; i < 1000; ++i) {
            money[i] = 0;
        }
    }

    if (op == "+") {
        for (int i = 0; i < 1000; ++i) {
            if(money[i] == 0) {
                money[i] = bills[rand() % 5];
            }
        }
        ofstream file_out("..\\money.bin");
        file_out.write((char*) money, sizeof(money));
        file_out.close();
        displayATMState(money, bills);
        return 0;
    } else if(op == "-") {
        cout << "Ammount: ";
        int amount;
        cin >> amount;
        if((amount % 100) != 0) {
            cout << "Invalid amount: " << amount << endl;
            return 1;
        }

        int amountToCollect = amount;
        for (int i = 4; i >= 0; --i) {
            int bill = bills[i];
            for (int j = 0; j < 1000; ++j) {
                if (money[j] == bill) {
                    if (amountToCollect >= bill) {
                        money[j] = 0;
                        amountToCollect -= bill;
                        if (amountToCollect == 0) {
                            cout << "Amount taken: " << amount << endl;
                            ofstream file_out("..\\money.bin");
                            file_out.write((char*) money, sizeof(money));
                            file_out.close();
                            displayATMState(money, bills);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Not enough compatible bills!" << endl;
    displayATMState(money, bills);
    return 1;
}