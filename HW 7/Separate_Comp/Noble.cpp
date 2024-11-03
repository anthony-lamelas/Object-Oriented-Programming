//Anthony Lamelas Noble.cpp file

#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace WarriorCraft {
ostream& operator<<(ostream& os, const Noble& noble) {
    os << noble.noble_name << " has an army of " << noble.army.size()
        << endl;

    for (const Warrior* const warrior : noble.army) {
        if (warrior) {
            os << *warrior << endl;
        }
    }
    return os;
}

Noble::Noble(const string& n) : noble_name(n), army(), living(true) {}

// Gets the name
const string& Noble::getName() const { return noble_name; }

// Gets the life status
bool Noble::getStatus() const { return living; }

// Gets the army size
size_t Noble::getSize() const { return army.size(); }

// Gets the total strength of the noble's army
const double Noble::getArmyStrength() const {
        double total_str = 0;
        for ( Warrior* const& warrior : army) {
            total_str += warrior->getStrength();
        }
        return total_str;
    }

// Updates army strength after the battle
void Noble::setArmyStrength(double champ_str, double loser_str) {
        double str_ratio = loser_str / champ_str;
        for (Warrior* const warrior : army) {
            double new_str = warrior->getStrength() * (1 - str_ratio);
            warrior->setStrength(new_str);
        }
    }

// Changes Noble to dead
void Noble::kill() {
        living = false;
        // Makes all warrior strengths 0 
        for (Warrior* const& warrior : army) {
            warrior->setStrength(0);
            warrior->setBoss(nullptr);
        }
    }

// Hire Warrior
bool Noble::hire(Warrior& warrior) {
        if (warrior.isHired() || !living) {
            cout << noble_name << " failed to hire " << warrior.getName() 
            << endl;
            return false;
        } else {
            warrior.changeJobStatus();
            army.push_back(&warrior);
            warrior.setBoss(this);
            return true;
        }
    }

// Fire Warrior
bool Noble::fire(Warrior& warrior) {
    if (!living) {
        return false;
    }
    if (remove_warrior(warrior)){
        cout << warrior.getName() << ", you don't work for me anymore  ! -- " 
        << noble_name << "." << endl;
        return true;
        }

        return false;
}

// Battle between two nobles
void Noble::battle(Noble& opponent) {
        cout << noble_name << " battles " << opponent.getName() << endl;
        if (!living && !opponent.getStatus()) { // Both dead
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        else if (!living && opponent.getStatus()) { // Main dead
            cout << "He's dead, " << opponent.getName() << endl;
        }
        
        else if (living && !opponent.getStatus()) { // Enemy is dead
            cout << "He's dead, " << noble_name << endl;
        }
        
        else { // Both are alive
            double my_str = getArmyStrength();
            double opponent_str = opponent.getArmyStrength();
            if (my_str == opponent_str) { // If it is a tie
                kill();
                opponent.kill();
                cout << "Mutual Annihilation: " << noble_name << " and "
                    << opponent.getName() << " die at each other's hands"
                    << endl;
            }
            else if (my_str > opponent_str) { // If main noble wins
                setArmyStrength(my_str, opponent_str);
                opponent.kill();
                cout << noble_name << " defeats " << opponent.getName()
                    << endl;
            }
            else { // If opponent wins
                opponent.setArmyStrength(opponent_str, my_str);
                kill();
                cout << opponent.getName() << " defeats " << noble_name
                    << endl;
            }
        }
    }

bool Noble::remove_warrior(Warrior& warrior) {
    bool found = false;
    int index;

    for (size_t i = 0; i < army.size(); i++){
        if (army[i] == &warrior){
            warrior.changeJobStatus();
            warrior.setBoss(nullptr);
            found = true;
            index = i;
            break;
        }
    }
    if (found) {
            for (size_t i = index; i < army.size() - 1; i++) {
                army[i] = army[i + 1];
            }
            army.pop_back();
            return true;
    }
    return false;
}   
}
