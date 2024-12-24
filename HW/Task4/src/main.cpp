#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int bills[5] = {100, 200, 500, 1000, 5000};
    int money[1000] = {0};

    cout << "Operation: ";
    string op;
    cin >> op;

    ifstream file_in("..\\money.bin", ios::binary);
    if (!file_in.is_open()) {
        cerr << "Couldn't open the file" << endl;
        return 1;
    }
    
    file_in.read((char*)money, sizeof(money));
    file_in.close();

    int count[5] = {0};
    int totalAmount = 0;

    for (int i = 0; i < 1000; ++i) {
        if (money[i] != 0) {
            for (int j = 0; j < 5; ++j) {
                if (money[i] == bills[j]) {
                    count[j]++;
                    totalAmount += money[i];
                }
            }
        }
    }

    cout << "Current bills count:" << endl;
    for (int j = 0; j < 5; ++j) {
        cout << bills[j] << ": " << count[j] << endl;
    }
    cout << "Total amount: " << totalAmount << endl;

    if (op == "+") {
        for (int i = 0; i < 1000; ++i) {
            if (money[i] == 0) {
                money[i] = bills[rand() % 5];
                for (int j = 0; j < 5; ++j) {
                    if (money[i] == bills[j]) {
                        count[j]++;
                        totalAmount += money[i];
                    }
                }
            }
        }
        ofstream file_out("..\\money.bin", ios::binary);
        file_out.write((char*)money, sizeof(money));
        file_out.close();

        cout << "ATM status after deposit:" << endl;
        for (int j = 0; j < 5; ++j) {
            cout << bills[j] << ": " << count[j] << endl;
        }
        cout << "Total amount: " << totalAmount << endl;

        return 0;
    } else if (op == "-") {
        cout << "Amount: ";
        int amount;
        cin >> amount;
        if ((amount % 100) != 0) {
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
                        count[i]--;
                        if (amountToCollect == 0) {
                            cout << "Amount taken: " << amount << endl;
                            ofstream file_out("..\\money.bin", ios::binary);
                            file_out.write((char*)money, sizeof(money));
                            file_out.close();
                            
                            cout << "ATM status after withdrawal:" << endl;
                            for (int j = 0; j < 5; ++j) {
                                cout << bills[j] << ": " << count[j] << endl;
                            }
                            totalAmount -= amount;
                            cout << "Total amount: " << totalAmount << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Not enough compatible bills!" << endl;
    return 1;
}