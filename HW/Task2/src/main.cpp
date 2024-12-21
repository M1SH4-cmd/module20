#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    std::srand(std::time(nullptr));
    int WIDTH;
    int HEIGHT;

    cout << "Enter the width and height of the square matrix: ";
    cin >> WIDTH >> HEIGHT;

    ofstream painting("..\\painting.txt");



    for (int i = 0; i < HEIGHT; ++i) {
        string buffer1 = "";    
        for (int j = 0; j < WIDTH; ++j) {
            int random = rand() % 2;
            painting << random << " ";
        }
        painting << endl;
    }


}