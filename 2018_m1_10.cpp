#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Thing {
    vector<int> stuff;
};



void fill(ifstream& ifs, vector<Thing>& vect){
    string count;
    Thing athing;

    ifs >> count;
    if(count == "one"){
        int num;
        ifs >> num;

        athing.stuff.push_back(num);

        vect.push_back(athing);
    }
    else {
        int num1, num2, num3;
        ifs >> num1 >> num2 >> num3;
        athing.stuff.push_back(num1);
        athing.stuff.push_back(num2);
        athing.stuff.push_back(num3);

        vect.push_back(athing);
    }
}

int totalStuff(const vector<Thing>& vect){
    int total = 0;

    for(size_t i = 0; i < vect.size(); i++){
        
        for(size_t j = 0; j < vect[i].stuff.size(); j++){
            total += vect[i].stuff[j];
        }
    }

    return total;
}



int main() {
    ifstream ifs("stuff.txt");
    vector<Thing> things; // Note: not Thing pointers

    fill(ifs, things); // Implement this function
    ifs.close();

    cout << "Total stuff: " << totalStuff(things) // Implement this function
         << endl;

    return 0;
}

