#include <iostream>
#include <fstream>
using namespace std;


bool checkTime (string time)
{
    if ((time[2] != ':' || time[5] != ':') || (time.length() != 10)) return false;
    int day = stoi(time.substr(0, 2));
    int month = stoi(time.substr(3, 2));
    int year = stoi(time.substr(6, 4));
    if (day < 0 || day > 31) return false;
    if (month < 1 || month > 12) return false;
}

int main()
{
    ofstream file("..\\cash.txt", ios::app);
    string lineToAdd = "";
    string buffer;
    cout << "Type EXIT to exit" << endl;

    while(true) {
    cout << "\nEnter your employees first and second names:\t";
    getline(cin, buffer);
    if (buffer == "EXIT") return 0;
    lineToAdd += buffer;
    cout << "\nEnter cash ammount:\t";
    getline(cin, buffer);
    if (buffer == "EXIT") return 0;
    lineToAdd += buffer;
    cout << "\nEnter time of payment (DD:MM:YYYY):\t";
    getline(cin, buffer);
    if (!checkTime(buffer)) {
        cout << "Invalid time" << endl;
        continue;
        }
    if (buffer == "EXIT") return 0;
    lineToAdd += buffer;
    file << lineToAdd << endl;
    }
    return 0;
}