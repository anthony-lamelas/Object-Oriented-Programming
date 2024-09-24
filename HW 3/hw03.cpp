/*
hw03
Anthony Lamelas
September 22, 2024
CS2124 24F
Simulates battles determined by strength of weapons between warriors
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
using namespace std;

class Warrior {
    class Weapon;

    // Operator overlaod friend for warrior
    friend ostream& operator<<(ostream& os, const Warrior& warrior);

    // Operator overload friend for weapon
    friend ostream& operator<<(ostream& os, const Warrior::Weapon& weapon);

    public:
        // Initialization
        Warrior(const string& name, const string& weapon_name, int weapon_str) 
        : warrior_name(name), weapon(weapon_name, weapon_str)  {}

        // Methods for warrior
        string getName() const { return warrior_name; }
        int getStrength() const {return weapon.getStrength(); }
        void setStrength(int weapon_str) {weapon.setStrength(weapon_str);}

        void battle(Warrior& opponent){
            
         cout << getName() << " battles " << opponent.getName() << endl;
        // Case where Warrior exists and opponent does not
        if (getStrength() > 0 && opponent.getStrength() == 0){  
            cout << "He's dead, " << getName() << endl;

        // Case where opponent exists and Warrior does not
        } else if (opponent.getStrength() > 0 && getStrength() == 0){  
            cout << "He's dead, " << opponent.getName() << endl;

        // Case where both Warrior and opponent are dead
        } else if (getStrength() == 0 && opponent.getStrength() == 0){ 
            cout << "Oh, NO! They're both dead! Yuck!" << endl;

        // Case if Warrior is stronger
        } else if (getStrength() > opponent.getStrength()){ 
            cout << getName() << " defeats " << opponent.getName() << endl;
            setStrength(getStrength() - opponent.getStrength());
            opponent.setStrength(0);

        // Case if opponent is stronger
        } else if (opponent.getStrength() > getStrength()){ 
            cout << opponent.getName() << " defeats " << getName() << endl;
            opponent.setStrength(opponent.getStrength() - getStrength());
            setStrength(0);

        // Case if the strengths are equal
        } else {  
            setStrength(0);
            opponent.setStrength(0);
            cout << "Mutual Annihilation: " << getName() << " and "
             << opponent.getName()  
                 << " die at each other's hands" << endl;
        }
    
}

    private:

    class Weapon {
        public:
            // Initialization
            Weapon(const string& name, int& strength)
             : name(name), strength(strength) {}

                // Methods for Weapon
                string getName() const { return name; }
                int getStrength() const { return strength; }
                void setStrength(int new_strength) { strength = new_strength; }

        // Private variables for weapon
        private:
            string name;
            int strength;
            };

        // Private variables for warrior
        private:
            string warrior_name;
            Weapon weapon;
};

// Function prototypes
void add_warrior(fstream& warriors_file, vector<Warrior>& warriorlist);
void execute_battle(fstream& warriors_file, vector<Warrior>& warriorlist);
void status(const vector<Warrior>& Warriors);

// Main

int main(){
    fstream warriors_file;
    vector<Warrior> warriorlist;

    warriors_file.open("warriors.txt");
    if (!warriors_file.is_open()) {
        cerr << "Error opening file" << endl;
    }

    string command;

    while(warriors_file >> command){
        if (command == "Warrior"){ 
            add_warrior(warriors_file, warriorlist);
        } else if (command == "Battle"){ 
            execute_battle(warriors_file, warriorlist);
        } else if (command == "Status"){ 
            status(warriorlist);
        }
    }
    warriors_file.close();

}

// Function to add a new warrior to the list, takes in fstream and vector of 
// warriors, returns nothing
void add_warrior(fstream& warriors_file, vector<Warrior>& warriorlist) {
    string name;
    int weapon_strength;
    string weapon_name;

    warriors_file >> name >> weapon_name >> weapon_strength;
    bool duplicate = false;

    for (const Warrior& warrior : warriorlist) {
        if (warrior.getName() == name) {
            cerr << "Error: Warrior with the name '" << name 
                 << "' already exists" << endl;
            duplicate = true;
            break;
        }
    }
    if (!duplicate) {
        Warrior new_warrior(name, weapon_name, weapon_strength);
        warriorlist.push_back(new_warrior);
    }
}

// Function to execute a battle between two warriors, takes in fstream and 
// vector of warriors, returns nothing
void execute_battle(fstream& warriors_file, vector<Warrior>& warriorlist) {
    string name1, name2;
    warriors_file >> name1 >> name2;
    size_t index1 = warriorlist.size();
    size_t index2 = warriorlist.size();

    for (size_t i = 0; i < warriorlist.size(); ++i) {
        if (warriorlist[i].getName() == name1) {
            index1 = i;
        }
        if (warriorlist[i].getName() == name2) {
            index2 = i;
        }
    }
    if (index1 != warriorlist.size() && index2 != warriorlist.size()) {
       warriorlist[index1].battle(warriorlist[index2]);
    } else {
        cerr << "Error: One or both warriors not found." << endl;
    }
}

// Status command displays how many warriors and their amount of strength
// Takes in a vector of warriors, returns nothing
void status(const vector<Warrior>& Warriors){
    size_t amount_warriors = Warriors.size();
    cout << "There are: " << amount_warriors << " warriors" << endl;

    for (Warrior warrior : Warriors){
        cout << warrior;
    }
}

// Operator overload for warrior
ostream& operator<<(ostream& os, const Warrior& warrior){
    os << "Warrior " << warrior.getName() << ", " << warrior.weapon;
    return os;
}

// Operator overload for weapon 
ostream& operator<<(ostream& os, const Warrior::Weapon& weapon){
    os << "weapon: " << weapon.getName() << ", " << weapon.getStrength()
    << endl;
    return os;
}