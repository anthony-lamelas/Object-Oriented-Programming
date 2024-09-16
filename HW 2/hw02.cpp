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

// WarriorList struct with list of all warriors
struct WarriorList{
    vector<Warrior> Warriors;
};

// Function Prototypes
void battle(Warrior& Warrior1, Warrior& Warrior2);
void status(const vector<Warrior>& Warriors);
void run_file(fstream& warriors_file);

// Main 
int main(){
    fstream warriors_file;
    run_file(warriors_file);
}

// Battle function that takes in two warriors
void battle(Warrior& Warrior1, Warrior& Warrior2){
    if (Warrior1.name.empty() || Warrior2.name.empty()){
        cerr << "Error: At least one of the warriors is not initialized." 
        << endl;
    }
    else {
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
void status(const vector<Warrior>& Warriors){
    size_t amount_warriors = Warriors.size();
    cout << "There are: " << amount_warriors << " warriors" << endl;

    for (Warrior warrior : Warriors){
        cout << "Warrior: " << warrior.name << ", strength: " 
        << warrior.strength << endl;
    }
}

// Function to open and iterate through the file
void run_file(fstream& warriors_file){
    warriors_file.open("warriors.txt");

    if (!warriors_file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    WarriorList warriorlist;
    string command;

    while(warriors_file >> command){
        // Creates new Warrior
        if (command == "Warrior"){ 
            string name;
            int strength;
            warriors_file >> name >> strength;
            bool duplicate = false;

            // Checks for duplicates
            for (const Warrior& warrior : warriorlist.Warriors) { 
                if (warrior.name == name) {
                    cerr << "Error: Warrior with the name '" << name 
                    << "' already exists" << endl;
                    duplicate = true;
                    break;
                }
            }
            
            // If no duplicate, add the new warrior
            if (!duplicate) { 
                Warrior new_warrior;
                new_warrior.name = name;
                new_warrior.strength = strength;
                warriorlist.Warriors.push_back(new_warrior);
            }

        // Handles the Battle command
        } else if (command == "Battle"){ 
            string name1, name2;
            warriors_file >> name1 >> name2;
            Warrior* Warrior1 = nullptr;
            Warrior* Warrior2 = nullptr;

            // Find the warriors by name
            for (size_t i = 0; i < warriorlist.Warriors.size(); ++i) {
                if (warriorlist.Warriors[i].name == name1) {
                    Warrior1 = &warriorlist.Warriors[i];
                }
                if (warriorlist.Warriors[i].name == name2) {
                    Warrior2 = &warriorlist.Warriors[i];
                }
            }

             // If warriors found, run the battle function
            if (Warrior1 && Warrior2) {
                battle(*Warrior1, *Warrior2);
            } else {
                cerr << "Error: One or both warriors not found." << endl;
            }

        // Runs status function
        } else if (command == "Status"){ 
            status(warriorlist.Warriors);
        }
    }
    warriors_file.close();
}
