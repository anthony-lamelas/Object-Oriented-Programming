/*
  Anthony Lamelas
*/

#include <iostream>
#include <vector>
#include "Noble.h"
#include "Protector.h"

using namespace std;

namespace WarriorCraft {

    Noble::Noble(const string& name) : noble_name(name), living(true) {}

    //Getters and Setters
    const string& Noble::getName() const { return noble_name; }
    bool Noble::getStatus() const { return living; }
    void Noble::changeStatus() {living = !living; }

    void Noble::battle(Noble& opponent) {
        cout << noble_name << " battles " << opponent.getName() << endl;
        if (!living && !opponent.getStatus()) { // Both dead
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        else if (!living && opponent.getStatus()) { // Main dead
            opponent.defend();
            cout << "He's dead, " << opponent.getName() << endl;
        }
        
        else if (living && !opponent.getStatus()) { // Enemy is dead
            defend();
            cout << "He's dead, " << noble_name << endl;
        }
        
        else { // Both are alive
            double my_str = getStrength();
            double opponent_str = opponent.getStrength();
            defend();
            opponent.defend();

            if (my_str == opponent_str) { // If it is a tie
                kill();
                opponent.kill();
                cout << "Mutual Annihilation: " << noble_name << " and "
                    << opponent.getName() << " die at each other's hands"
                    << endl;
            }
            else if (my_str > opponent_str) { // If main noble wins
                setStrength(my_str, opponent_str);
                opponent.kill();
                cout << noble_name << " defeats " << opponent.getName()
                    << endl;
            }
            else { // If opponent wins
                opponent.setStrength(opponent_str, my_str);
                kill();
                cout << opponent.getName() << " defeats " << noble_name
                    << endl;
            }
        }
    }

Lord::Lord(const string& name) : Noble(name){}

//Kills the Lord
void Lord::kill() {
        changeStatus();
        // Makes all protector strengths 0 
        setStrength(1,1);
    }

//Gets the Army
const vector<Protector*> Lord::getArmy() const {return army; }

// Gets the total strength of the noble's army
 double Lord::getStrength() const {
        double total_str = 0;
        for ( Protector* const& protector : army) {
            total_str += protector->getStrength();
        }
        return total_str;
    }

// Updates army strength after the battle
void Lord::setStrength(double champ_str, double loser_str) {
        double str_ratio = loser_str / champ_str;
        for (Protector* const protector : army) {
            double new_str = protector->getStrength()
             * (champ_str - loser_str) / champ_str;
            protector->setStrength(new_str);
        }
    }

void Lord::defend() const {
    for(Protector* protector : army){
        protector->defend();
    }
}

// Hire protector
bool Lord::hires(Protector& protector) {
        if (protector.isHired() || !getStatus()) {
            cout << getName() << " failed to hire " << protector.getName() 
            << endl;
            return false;
        } else {
            protector.changeJobStatus();
            army.push_back(&protector);
            protector.setBoss(this);
            return true;
        }
    }

// fires protector
bool Lord::fires(Protector& protector) {
    if (!getStatus()) {
        return false;
    }
    if (remove_protector(protector)){
        cout << protector.getName() << ", you don't work for me anymore  ! -- " 
        << getName() << "." << endl;
        return true;
        }

        return false;
}

bool Lord::remove_protector(Protector& protector) {
    bool found = false;
    double index;

    for (size_t i = 0; i < army.size(); i++){
        if (army[i] == &protector){
            protector.changeJobStatus();
            protector.setBoss(nullptr);
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

// Output Operator for Lord
std::ostream& operator<<(std::ostream& os, const WarriorCraft::Lord& lord) {
    os << lord.getName() << " has an army of size: " << lord.army.size()
     << "\n";
    for (const Protector* protector : lord.army) {
        os << "\t" << protector->getName() << " has strength " 
        << protector->getStrength() << "\n";
    }
    return os;
}

PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, 
 double str) : Noble(name), strength(str) {}

// Output Operator for PersonWithStrengthToFight
std::ostream& operator<<(std::ostream& os, 
const WarriorCraft::PersonWithStrengthToFight& noble) {

    os << noble.getName();
    if (noble.getStrength() > 0) {
        os << " has strength: " << noble.strength;
    } else {
        os << " has strength " << 0;
    }
    return os;
}

 void PersonWithStrengthToFight::kill() {
        changeStatus();
        strength = 0;
    }

double PersonWithStrengthToFight::getStrength() const { return strength; }

void PersonWithStrengthToFight::setStrength
    (double champ_str, double loser_str) {
        strength -= loser_str;
    }

void PersonWithStrengthToFight::defend() const { cout << "Ugh!" << endl; }

}

