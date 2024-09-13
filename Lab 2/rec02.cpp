#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

//Create struct (good)
struct HydroCarbon {
    int Carbon;
    int Hydrogen;
    vector<string> HC_names;
};

//prototypes

void open_file(fstream& HCStream);
void fill_HC(vector<HydroCarbon>& Hydrocarbs, fstream& HC_file);
int find(vector<HydroCarbon>& Hydrocarbs, int Carbon, int Hydrogen);
void display_vector(vector<HydroCarbon>& Hydrocarbs);
void insert_hydrocarbon(vector<HydroCarbon>& Hydrocarbs, string name, int Carbon, int Hydrogen);
void print_single_hydrocarbon(const HydroCarbon& individual_HC);
void sort_Hydrocarbs(vector<HydroCarbon>& Hydrocarbs);
void swap_HC(vector<HydroCarbon>& Hydrocarbs, int pos1, int pos2);

//main
int main() {
    fstream HC_file("");
    vector<HydroCarbon> myHydroCarbs;

    open_file(HC_file);
    fill_HC(myHydroCarbs, HC_file);
    cout << "Unsorted:" << endl;
    display_vector(myHydroCarbs);
    cout << "\n" << endl;
    cout << "Sorted:" << endl;
    sort_Hydrocarbs(myHydroCarbs);
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
void fill_HC(vector<HydroCarbon>& Hydrocarb, fstream& HC_file){
    while(HC_file){
    int Hydrogen;
    int Carbon;
    char skip;
    string name;
    string formula;

    HC_file >> name >> skip >> Carbon >> skip >> Hydrogen;
    insert_hydrocarbon(Hydrocarb, name, Carbon, Hydrogen);

    }
}


//find location(index) of a formula object (good)
int find(vector<HydroCarbon>& Hydrocarbs, int Carbon, int Hydrogen) {
    for (size_t i = 0; i < Hydrocarbs.size(); i++) {
        if (Carbon == Hydrocarbs[i].Carbon && Hydrogen == Hydrocarbs[i].Hydrogen) {
            return i;  
        }
    }
    return Hydrocarbs.size();  
}

//display vector (good)
void display_vector(vector<HydroCarbon>& Hydrocarbs){
    for(const HydroCarbon& individual_HC : Hydrocarbs){
        print_single_hydrocarbon(individual_HC);
    }
}


//sort the vector
void sort_Hydrocarbs(vector<HydroCarbon>& Hydrocarbs) {
    size_t n = Hydrocarbs.size();
    bool swapped;
    
    //Bubble Sort 
    for (size_t i = 0; i < n - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (Hydrocarbs[j].Carbon > Hydrocarbs[j + 1].Carbon || 
               (Hydrocarbs[j].Carbon == Hydrocarbs[j + 1].Carbon && Hydrocarbs[j].Hydrogen > Hydrocarbs[j + 1].Hydrogen)) {
                swap_HC(Hydrocarbs, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) break;  // No swaps means the array is already sorted
    }
}


//Helper function for sorting
//Swaps two HydroCarbon objects
void swap_HC(vector<HydroCarbon>& Hydrocarbs, int pos1, int pos2) {
    HydroCarbon temp = Hydrocarbs[pos1];
    Hydrocarbs[pos1] = Hydrocarbs[pos2];
    Hydrocarbs[pos2] = temp;
}


//insert information for name, carbon and hydrogen count (good)
void insert_hydrocarbon(vector<HydroCarbon>& Hydrocarbs, string name, int Carbon, int Hydrogen) {
    int idx = find(Hydrocarbs, Carbon, Hydrogen); 
    if (idx == Hydrocarbs.size()) {
        HydroCarbon new_HC;
        new_HC.Carbon = Carbon;
        new_HC.Hydrogen = Hydrogen;
        new_HC.HC_names.push_back(name);
        Hydrocarbs.push_back(new_HC);
    } else {
       Hydrocarbs[idx].HC_names.push_back(name);
    }
}


//print out a single formula object (good)
void print_single_hydrocarbon(const HydroCarbon& individual_HC) {
    cout << "C" << individual_HC.Carbon << "H" << individual_HC.Hydrogen << " ";
     for (string name: individual_HC.HC_names){
        cout << name << " ";
     }
     cout << "\n";
}
