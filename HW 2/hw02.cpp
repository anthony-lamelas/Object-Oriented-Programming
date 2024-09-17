/*
hw02
Anthony Lamelas
September 9, 2024
CS2124 24F
Simulates battles determined by strength between warriors
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
using namespace std;

// Warrior struct with name and strength
struct Warrior{
    string name;
    int strength;
};

// WarriorList struct with vector of all warriors
struct WarriorList{
    vector<Warrior> Warriors;
};

// Function Prototypes
void battle(Warrior& Warrior1, Warrior& Warrior2);
void status(const vector<Warrior>& Warriors);
void run_file(fstream& warriors_file);
void add_warrior(fstream& warriors_file, WarriorList& warriorlist);
void execute_battle(fstream& warriors_file, WarriorList& warriorlist);

// Main 
int main(){
    fstream warriors_file;
    run_file(warriors_file);
}

// Battle function that takes in two warriors, runs the battle, returns nothing 
void battle(Warrior& Warrior1, Warrior& Warrior2){
    if (Warrior1.name.empty() || Warrior2.name.empty()){
        cerr << "Error: At least one of the warriors is not initialized." 
        << endl;
    } else {
         cout << Warrior1.name << " battles " << Warrior2.name << endl;
        // Case where Warrior1 exists and Warrior2 does not
        if (Warrior1.strength > 0 && Warrior2.strength == 0){  
            cout << "He's dead, " << Warrior1.name << endl;

        // Case where Warrior2 exists and Warrior1 does not
        } else if (Warrior2.strength > 0 && Warrior1.strength == 0){  
            cout << "He's dead, " << Warrior2.name << endl;

        // Case where both Warriors are dead
        } else if (Warrior1.strength == 0 && Warrior2.strength == 0){ 
            cout << "Oh, NO! They're both dead! Yuck!" << endl;

        // Case if Warrior1 is stronger
        } else if (Warrior1.strength > Warrior2.strength){ 
            cout << Warrior1.name << " defeats " << Warrior2.name << endl;
            Warrior1.strength -= Warrior2.strength;
            Warrior2.strength = 0;

        // Case if Warrior2 is stronger
        } else if (Warrior2.strength > Warrior1.strength){ 
            cout << Warrior2.name << " defeats " << Warrior1.name << endl;
            Warrior2.strength -= Warrior1.strength;
            Warrior1.strength = 0;

        // Case if the strengths are equal
        } else {  
            Warrior1.strength = 0;
            Warrior2.strength = 0;
            cout << "Mutual Annihilation: " << Warrior1.name << " and "
             << Warrior2.name  
                 << " die at each other's hands" << endl;
        }
    }
}
// Status command displays how many warriors and their amount of strength
// Takes in a vector of warriors, returns nothing
void status(const vector<Warrior>& Warriors){
    size_t amount_warriors = Warriors.size();
    cout << "There are: " << amount_warriors << " warriors" << endl;

    for (Warrior warrior : Warriors){
        cout << "Warrior: " << warrior.name << ", strength: " 
        << warrior.strength << endl;
    }
}

// Function to open and iterate through the file, takes in an fstream
// Returns nothing
void run_file(fstream& warriors_file){
    warriors_file.open("warriors.txt");

    if (!warriors_file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    WarriorList warriorlist;
    string command;

    while(warriors_file >> command){
        if (command == "Warrior"){ 
            add_warrior(warriors_file, warriorlist);
        } else if (command == "Battle"){ 
            execute_battle(warriors_file, warriorlist);
        } else if (command == "Status"){ 
            status(warriorlist.Warriors);
        }
    }
    warriors_file.close();
}

// Function to add a new warrior to the list, takes in fstream and vector of 
// warriors, returns nothing
void add_warrior(fstream& warriors_file, WarriorList& warriorlist) {
    string name;
    int strength;
    warriors_file >> name >> strength;
    bool duplicate = false;

    for (const Warrior& warrior : warriorlist.Warriors) {
        if (warrior.name == name) {
            cerr << "Error: Warrior with the name '" << name 
                 << "' already exists" << endl;
            duplicate = true;
            break;
        }
    }
    if (!duplicate) {
        Warrior new_warrior{name, strength};
        warriorlist.Warriors.push_back(new_warrior);
    }
}

// Function to execute a battle between two warriors, takes in fstream and 
// vector of warriors, returns nothing
void execute_battle(fstream& warriors_file, WarriorList& warriorlist) {
    string name1, name2;
    warriors_file >> name1 >> name2;
    size_t index1 = warriorlist.Warriors.size();
    size_t index2 = warriorlist.Warriors.size();

    for (size_t i = 0; i < warriorlist.Warriors.size(); ++i) {
        if (warriorlist.Warriors[i].name == name1) {
            index1 = i;
        }
        if (warriorlist.Warriors[i].name == name2) {
            index2 = i;
        }
    }
    if (index1 != warriorlist.Warriors.size() 
    && index2 != warriorlist.Warriors.size()) {
        battle(warriorlist.Warriors[index1], warriorlist.Warriors[index2]);
    } else {
        cerr << "Error: One or both warriors not found." << endl;
    }
}
