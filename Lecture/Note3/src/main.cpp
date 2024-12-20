#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{
    char* title = "Skillbox";
    ofstream file("..\\title.bin", ios::binary);
    file.write(title, strlen(title));
    file.close();

}
