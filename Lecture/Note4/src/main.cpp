#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;


int main()
{

    int control_sum = 0;
    vector<int> buildings;
    int count = rand() % 901 + 100;
    for (int i = 0; i < count; ++i) {
        buildings.push_back(rand() % 51);
        control_sum += buildings[i];
    }

    cout << "Control sum:\t" << control_sum << endl;

    ofstream file("..\\buildings.txt");
    file << count << endl;
    for (int i = 0; i < count; ++i) {
        file << buildings[i] << endl;
    }
    file << "Jokerville" << endl;
    file.close();

    ifstream in_file("../buildings.txt");
    vector<int> in_buildings;
    int in_count;
    in_file >> in_count;
    for (int i = 0; i < in_count; ++i) {
        int in_people;
        in_file >> in_people;
        in_buildings.push_back(in_people);
    }

    string in_city;
    in_file >> in_city;

    int sum = 0;
    for (int i = 0; i < in_count; ++i) {
        sum += in_buildings[i];
    }

    if (sum == control_sum) {
        cout << in_city << " population: " << sum << endl;
    } else {
        cout << "Invalid control sum." << endl;
    }
}
