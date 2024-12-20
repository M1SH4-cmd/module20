#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream file("..\\file.txt");
    
    file.setf(ios::showpos);
    file.setf(ios::showpoint);
    file.setf(ios::fixed);
    file.precision(1);

    double temps[] = {10.1, 8.5, 0, -1.1, -15.7};
    char* conditions[] = {"sunny", "cloudy", "windy", "snowy", "stormy"};

    for(int i = 0; i < 5; ++i){
        file.width(5);
        file << temps[i];
        file.width(10);
        file << conditions[i] << endl;
    }

    file.close();
}