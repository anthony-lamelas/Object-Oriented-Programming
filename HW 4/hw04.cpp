#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Warrior {

    // Operator overload for Warrior
    friend ostream& operator<<(ostream& os, const Warrior& warrior);

public:
    Warrior(const string& n, double s) : warr_name(n), strength(s), has_job(false) {}

    // Methods for Warrior
    const string& getName() const { return warr_name; }
    double getStrength() const { return strength; }
    void setStrength(double newStrength) { strength = newStrength; }
    bool getJobStatus() const { return has_job; }
    void changeJobStatus() { has_job = !has_job; }

private:
    string warr_name;
    double strength;
    bool has_job;
};

class Noble {

    // Operator overload for Noble
    friend ostream& operator<<(ostream& os, const Noble& noble);

public:
    // Initialization
    Noble(const string& n) : noble_name(n), army(), living(true) {}

    // Methods for Noble
    const string& getName() const { return noble_name; }
    const bool getStatus() const { return living; }

    // Gets the total strength of the noble's army
    const double getArmyStrength() const {
        double total_str = 0;
        for (const Warrior* const warrior : army) {
            total_str += warrior->getStrength();
        }
        return total_str;
    }

    // Updates army strength after the battle
    void setArmyStrength(double champ_str, double loser_str) {
        double str_ratio = loser_str / champ_str;
        for (Warrior* const warrior : army) {
            double new_str = warrior->getStrength() * (1 - str_ratio);
            warrior->setStrength(new_str);
        }
    }

    // Changes Noble to dead
    void kill() {
        living = false;

        // Makes all warrior strengths 0 
        for (Warrior* const& warrior : army) {
            warrior->setStrength(0);
        }
    }

    // Hire Warrior
    bool hire(Warrior& warrior) {
        if (warrior.getJobStatus() || !living) {
            cout << noble_name << " failed to hire " << warrior.getName() 
            << endl;
            return false;
        } else {
            warrior.changeJobStatus();
            army.push_back(&warrior);
            return true;
        }
    }

    // Fire Warrior
    bool fire(Warrior& warrior) {
        if (!living) {
            return false;
        }
        bool found = false;
        int index;
        // Finds the warrior that is going to be fired in the army
        for (size_t i = 0; i < army.size(); i++) {
            if (army[i] == &warrior) {
                cout << warrior.getName() 
                << ", you don't work for me anymore! -- " << noble_name << "."
                    << endl;
                warrior.changeJobStatus();
                found = true;
                index = i;
                break;
            }
        }
        // Shifts elements if warrior is found, then removes the pointer of
        // fired warrior
        if (found) {
            for (size_t i = index; i < army.size() - 1; i++) {
                army[i] = army[i + 1];
            }
            army.pop_back();
        } 
        else {
          cout << noble_name << " failed to fire " << warrior.getName() << endl;
        }
        return found;
    }

    // Battle between two nobles
    void battle(Noble& opponent) {
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

private:
    string noble_name;
    vector<Warrior*> army;
    bool living;
};

// Operator overload for Warrior
ostream& operator<<(ostream& os, const Warrior& warrior) {
    os << " " << warrior.warr_name << ": " << warrior.strength;
    return os;
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

int main() {

    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    

} // main


