#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

//Create struct (good)
struct HydroCarbon {
    int C;
    int H;
    vector<string> HC_names;
};

//prototypes

void open_file(fstream& HCStream);
void fill_HC(vector<HydroCarbon>& Hydrocarb, fstream& HC);
int find(vector<HydroCarbon>& Hydrocarbs, int C, int H);
void display_vector(vector<HydroCarbon>& Hydrocarbs);
void insert_hydrocarbon(vector<HydroCarbon>& Hydrocarbs, string name, int C, int H);
void print_single_hydrocarbon(const HydroCarbon& HC);

//main
int main() {
    fstream HC("");
    vector<HydroCarbon> myHydroCarbs;

    open_file(HC);
    fill_HC(myHydroCarbs, HC);
    display_vector(myHydroCarbs);

}

//open the stream (good)
void open_file(fstream& HCStream) {
    while (!HCStream) {
        cout << "enter filename:";
        string fileName;
        cin >> fileName;
        HCStream.open(fileName);
    }
}


//fill vector from the stream(good)
void fill_HC(vector<HydroCarbon>& Hydrocarb, fstream& HC){
    int H;
    int C;
    char skip;
    string name;
    string formula;

    HC >> name >> skip >> C >> skip >> H;
    insert_hydrocarbon(Hydrocarb, name, C, H);
}



//find location(index) of a formula object (good)
int find(vector<HydroCarbon>& Hydrocarbs, int C, int H) {
    for (size_t i = 0; i < Hydrocarbs.size(); i++) {
        if (C == Hydrocarbs[i].C && H == Hydrocarbs[i].H) {
            return i;  
        }
    }
    return Hydrocarbs.size();  
}

//display vector (good)
void display_vector(vector<HydroCarbon>& Hydrocarbs){
    for(const HydroCarbon& HC : Hydrocarbs){
        print_single_hydrocarbon(HC);
    }
}


//sort the vector


//insert information for name, carbon and hydrogen count (good)
void insert_hydrocarbon(vector<HydroCarbon>& Hydrocarbs, string name, int C, int H) {
    int idx = find(Hydrocarbs, C, H); 
    if (idx == Hydrocarbs.size()) {
        HydroCarbon new_HC;
        new_HC.C = C;
        new_HC.H = H;
        new_HC.HC_names.push_back(name);
        Hydrocarbs.push_back(new_HC);
    } else {
       Hydrocarbs[idx].HC_names.push_back(name);
    }
}


//print out a single formula object (good)
void print_single_hydrocarbon(const HydroCarbon& HC) {
    cout << "C" << HC.C << "H" << HC.H << " ";
     for (string name: HC.HC_names){
        cout << name;
     }

}
