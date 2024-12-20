#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int number;
    cin >> number;

    ofstream file("..\\number.bin", ios::binary);
    file.write((char*)&number, sizeof(number));
    file.close();


    int number2;
    ifstream file2("..\\number.bin", ios::binary);
    file2.read((char*)&number, sizeof(number));
    file2.close();
    return 0;
}