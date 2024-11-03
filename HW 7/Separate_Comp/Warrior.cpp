//Anthony Lamelas Warrior.cpp file

#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace WarriorCraft{

    // Operator overload for Warrior
ostream& operator<<(ostream& os, const Warrior& warrior) {
    os << " " << warrior.warr_name << ": " << warrior.strength;
    return os;
}

Warrior::Warrior(const string& n, double s) : warr_name(n), strength(s), 
    has_job(false) {}

const string& Warrior::getName() const { return warr_name; }
double Warrior::getStrength() const { return strength; }
void Warrior::setStrength(double newStrength) { strength = newStrength; }
bool Warrior::isHired() const { return has_job; }
void Warrior::changeJobStatus() { has_job = !has_job; }
void Warrior::setBoss(Noble* noblep) { boss = noblep; }
Noble* Warrior::getBoss() const  {return boss; }

bool Warrior::runaway() {
        if (strength == 0) {  // fail if warrior is dead
            cout << warr_name << " is already dead!" << endl;
            return false;
        }
        if (!boss) {  // fail if boss does not exist
            cout << warr_name << " has no boss.";
            return false;
        }
        string lordname = boss->getName();
        if (boss->remove_warrior(*this)) {
            cout << warr_name << " flees in terror, abandoning his lord, "
                 << lordname << endl;
            return true;
        }
        return false;  
    }



}