/*
 hw07-testcode.cpp
 Anthony Lamelas
 Program Allowing battes between Nobles and their armies of warriors.
 Single Compilation
 */

// Comment out these two includes for the single file solution
//#include "Noble.h"
//#include "Warrior.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Noble;
class Warrior {

    // Operator overload for Warrior
    friend ostream& operator<<(ostream& os, const Warrior& warrior);

public:
   Warrior(const string& n, double s);

    // Methods for Warrior
    const string& getName() const;
    double getStrength() const;
    void setStrength(double newStrength);
    bool isHired() const;
    void changeJobStatus();
    Noble* getBoss() const;
    void setBoss(Noble* noblep);
    bool runaway();
    

private:
    string warr_name;
    double strength;
    bool has_job;
    Noble* boss;
};

class Noble {

    // Operator overload for Noble
    friend ostream& operator<<(ostream& os, const Noble& noble);

public:
    // Initialization
    Noble(const string& n);

    // Methods for Noble
    // Gets the name
    const string& getName() const;

    // Gets the life status
    bool getStatus() const;

    // Gets the army size
    size_t getSize() const;

    // Gets the total strength of the noble's army
    const double getArmyStrength() const;

    // Updates army strength after the battle
    void setArmyStrength(double champ_str, double loser_str);

    // Changes Noble to dead
    void kill();

    // Hire Warrior
    bool hire(Warrior& warrior);

    // Fire Warrior
    bool fire(Warrior& warrior);

    // Battle between two nobles
    void battle(Noble& opponent);

    //Removes Warrior from army
    bool remove_warrior(Warrior& warrior);

private:
    string noble_name;
    vector<Warrior*> army;
    bool living;
};


// Comment out this "using namespace" for the single file solution
//using namespace WarriorCraft;

int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 4);
    Warrior sky("Leia", 6);
    Warrior wizard("Merlin", 9);
    Warrior jaffa("Teal'c", 9);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(jaffa);
    art.hire(cheetah);
    art.hire(wizard);
    art.hire(sky);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(nimoy);

    cout << "================ Initial Status ===============" << endl;
    cout << art << endl
	 << lance << endl
	 << jim << endl
	 << linus << endl
	 << billie << endl;
    cout << "===============================================\n\n";

    art.fire(cheetah);
    wizard.runaway();
    cout << endl << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "\n================ Final Status ===============" << endl;
    cout << art << endl
	 << lance << endl
	 << jim << endl
	 << linus << endl
	 << billie << endl;

    // Tarzan and Merlin should be unemployed
    cout << "Tarzan's Hire Status: " << boolalpha 
	 << cheetah.isHired() << endl;
    cout << "Merlin's Hire Status: " << boolalpha 
	 << wizard.isHired() << endl;
    cout << "===============================================\n\n";
}


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

// Operator overload for Noble
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