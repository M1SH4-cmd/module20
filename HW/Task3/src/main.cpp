#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void strToLower(string& str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}


int main()
{
    ifstream fishFile("..\\river.txt");
    ofstream basketFile("..\\basket.txt", ios::app);
    
    cout << "Input fish you're catching right now:\t";
    string buffer1;
    cin >> buffer1;
    strToLower(buffer1);

    while (!fishFile.eof()) {
        string buffer2;
        fishFile >> buffer2;
        if (buffer1 == buffer2) {
            basketFile << buffer1 << endl;
            cout << "Fish added to the basket!" << endl;
            break;
        }
    }

    

    fishFile.close();
    basketFile.close();
    return 0;
}