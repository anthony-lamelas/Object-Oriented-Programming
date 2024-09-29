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
    string getName() const { return warr_name; }
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
    string getName() const { return noble_name; }
    bool getStatus() const { return living; }
    vector<Warrior*> getArmy() const { return army; }

    // Gets the total strength of the noble's army
    double getArmyStrength() const {
        double total_str = 0;
        for (Warrior* const& warrior : army) {
            total_str += warrior->getStrength();
        }
        return total_str;
    }

    // Updates army strength after the battle
    void setArmyStrength(double champ_str, double loser_str) {
        double str_ratio = loser_str / champ_str;
        for (Warrior*& warrior : army) {
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

        // Both dead
        if (!living && !opponent.getStatus()) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        // Main dead
        else if (!living && opponent.getStatus()) {
            cout << "He's dead, " << opponent.getName() << endl;
        }
        // Enemy is dead
        else if (living && !opponent.getStatus()) {
            cout << "He's dead, " << noble_name << endl;
        }
        // Both are alive
        else {
            double my_str = getArmyStrength();
            double opponent_str = opponent.getArmyStrength();

            // If it is a tie
            if (my_str == opponent_str) {
                kill();
                opponent.kill();
                cout << "Mutual Annihilation: " << noble_name << " and "
                    << opponent.getName() << " die at each other's hands"
                    << endl;
            }
            // If main noble wins
            else if (my_str > opponent_str) {
                setArmyStrength(my_str, opponent_str);
                opponent.kill();
                cout << noble_name << " defeats " << opponent.getName()
                    << endl;
            }
            // If opponent wins
            else {
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
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    art.hire(nimoy);

    cout << "==========\n\n"
        << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n\n";

    art.fire(cheetah);
    cout << art << endl;

    lance.fire(nimoy);
    cout << lance << endl;
    cout << "==========\n\n";

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n\n"
        << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

} // main


// Operator overload for Warrior
ostream& operator<<(ostream& os, const Warrior& warrior) {
    os << " " << warrior.getName() << ": " << warrior.getStrength();
    return os;
}

// Operator overload for Noble
ostream& operator<<(ostream& os, const Noble& noble) {
    os << noble.getName() << " has an army of " << noble.getArmy().size()
        << endl;

    for (Warrior* warrior : noble.getArmy()) {
        if (warrior) {
            os << *warrior << endl;
        }
    }
    return os;
}