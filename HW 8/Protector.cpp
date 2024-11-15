/*
  Anthony Lamelas
*/

#include "Noble.h"
#include "Protector.h"
using namespace std;

namespace WarriorCraft {

Protector::Protector(const string& name, int str) : protector_name(name), 
strength(str), boss(nullptr), has_job(false){}

// Getters and Setters
const string& Protector::getName() const { return protector_name; }
int Protector::getStrength() const { return strength; }
void Protector::setBoss(Lord* noblep) { boss = noblep; }
Lord* Protector::getBoss() const  {return boss; }
void Protector::setStrength(int newStrength) { strength = newStrength; }

// Checks if protector has a job
bool Protector::isHired() const { return has_job; }

// Changes job status
void Protector::changeJobStatus() { has_job = !has_job; }

bool Protector::runaway() {
        // fail if Protector is dead
        if (strength == 0) {  
            cout << protector_name << " is already dead!" << endl;
            return false;
        }
        // fail if boss does not exist
        if (!boss) {  
            return false;
        }
        string lord_name = boss->getName();
        if (boss->remove_protector(*this)) {
            cout << protector_name << " flees in terror, abandoning his lord, "
                 << lord_name << endl;
            return true;
        }
        return false;  
    }

// Output Operator
std::ostream& operator<<(std::ostream& os, 
    const WarriorCraft::Protector& protector) {

    os << protector.getName() << " has strength " << protector.getStrength();
    return os;
}


void Warrior::defend() const {
    cout << getName() << " says: Take that in the name of my lord, " 
    << getBoss()->getName() << endl;
}

void Wizard::defend() const { cout << "POOF!" << endl; }

void Archer::defend() const {
    cout << "TWANG! ";
    Warrior::defend();
}

void Swordsman::defend() const {
    cout << "CLANG! ";
    Warrior::defend();
}

}

