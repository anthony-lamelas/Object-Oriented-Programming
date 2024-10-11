/*
hw05
Anthony Lamelas
October 10, 2024
CS2124 24F
Simulates battles between nobles and their armies of warriors
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Warrior {

    // Operator overload for Warrior
    friend ostream& operator<<(ostream& os, const Warrior& warrior);

public:
    Warrior(const string& n, double s) : warr_name(n), strength(s), 
    has_job(false) {}

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

    // Gets the name
    const string& getName() const { return noble_name; }

    // Gets the life status
    const bool getStatus() const { return living; }

    // Gets the army size
    const size_t getSize() const { return army.size(); }

    // Gets the total strength of the noble's army
    const double getArmyStrength() const {
        double total_str = 0;
        for ( Warrior* const& warrior : army) {
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


//Function Prototypes
void openFile(ifstream& fileStream);
Warrior* findWarrior(const vector<Warrior*>& warrior_vect, const string& name);
Noble* findNoble(const vector<Noble*>& noble_vect, const string& name);
void deletePtrs(vector<Noble*>& noble_vect, vector<Warrior*>& warrior_vect);
void display(vector<Noble*> const& noble_vect, 
vector<Warrior*> const& warrior_vect);

//test for noble already exists, warrior not found

int main() {
    ifstream stream; 
    openFile(stream);

    string command;
    vector<Noble*> noble_vect;
    vector<Warrior*> warrior_vect;
    cout << "Here" << endl;
    while (stream >> command){
        if (command == "Noble"){
            string name;
            stream >> name;
            cout << "Here 2" << endl;
            if(findNoble(noble_vect, name)){
                cout << "Noble " << name <<  " already exists." << endl;
            } else{
                noble_vect.emplace_back(new Noble(name));
            }
        }

        else if (command == "Warrior"){
            string name;
            cout << "Here 3" << endl;
            double strength;
            stream >> name >> strength;

            if (findWarrior(warrior_vect, name)){
                cout << "Warrior " << name << " already exists." << endl;
            } else{
                warrior_vect.emplace_back(new Warrior(name, strength));
            }
        }

        else if (command == "Hire"){
            string noble_name;
            string warrior_name;
            stream >> noble_name >> warrior_name;
            Noble* nobleptr;
            Warrior* warriorptr;

            nobleptr = findNoble(noble_vect, noble_name);
            warriorptr = findWarrior(warrior_vect, warrior_name);

            if (nobleptr && warriorptr) {
                nobleptr->hire(*warriorptr);
            } else {
                if (!nobleptr) {
                    cout << "Noble " << noble_name << " does not exist" << endl;
                } 
                if (!warriorptr) {
                    cout << "Attempting to hire unknown warrior: " 
                    << warrior_name << endl;
                }
            }
        }   

        else if (command == "Status"){
            display(noble_vect, warrior_vect);
        }

        else if (command == "Fire"){
            string noble_name;
            string warrior_name;
            stream >> noble_name >> warrior_name;
            Noble* nobleptr;
            Warrior* warriorptr;

            nobleptr = findNoble(noble_vect, noble_name);
            warriorptr = findWarrior(warrior_vect, warrior_name);

            if (nobleptr && warriorptr) {
                nobleptr->fire(*warriorptr);
            } else {
                if (!nobleptr) {
                    cout << "Noble " << noble_name << " not found!" << endl;
                } 
                if (!warriorptr) {
                    cout << "Warrior " << warrior_name << " not found!" << endl;
                }
            }

        }

        else if (command == "Battle"){

            string noble1;
            string noble2;

            stream >> noble1 >> noble2;
            Noble *nobleptr1, *nobleptr2;

            nobleptr1 = findNoble(noble_vect, noble1);
            nobleptr2 = findNoble(noble_vect, noble2);

            if (nobleptr1 && nobleptr2) {
                nobleptr1->battle(*nobleptr2);
            } else {
                if (!nobleptr1) {
                    cout << "Noble " << noble1 << " not found!" << endl;
                } 
                if (!nobleptr2) {
                    cout << "Noble " << noble2 << " not found!" << endl;
                }
            }
        }
        
        else {
            deletePtrs(noble_vect, warrior_vect);
            noble_vect.clear();
            warrior_vect.clear();
        }
    }
}

void openFile(ifstream& fileStream){
    fileStream.clear();
    fileStream.open("nobleWarriors.txt");

    if(!fileStream) {
        cerr << "Failed to open the file." << endl;
        exit(1);
    }
}

//Finds Warrior from the vector storing all warriors, returns warrior pointer
//and takes in the warrior vector and a name
Warrior* findWarrior(const vector<Warrior*>& warrior_vect, const string& name){

    for (Warrior* warriorptr : warrior_vect){
        if(warriorptr->getName() == name) {
            return warriorptr;
        }
    }
    return nullptr;
}

//Finds Noble from the vector storing all Nobles, returns noble pointer
//and takes in the noble vector and a name
Noble* findNoble(const vector<Noble*>& noble_vect, const string& name){
    for (Noble* nobleptr : noble_vect){
        if (nobleptr->getName() == name){
            return nobleptr;
        }
    }
    return nullptr;
}

//Deletes memory from heap for when done reading file, takes in noble and 
//warrior vectors
void deletePtrs(vector<Noble*>& noble_vect, vector<Warrior*>& warrior_vect){
    for (Noble* nobleptr : noble_vect){
        delete nobleptr;
    }

    for (Warrior* warriorptr : warrior_vect){
        delete warriorptr;
    }
}

//Displays status of all nobles and warriors
void display(vector<Noble*> const& noble_vect,
 vector<Warrior*> const& warrior_vect){
    cout << "Status" << endl << "======" << endl << "Nobles:" << endl;
    int hiredCount = 0;

    for (Noble* nobleptr: noble_vect){
        cout << *nobleptr << endl;
        hiredCount += nobleptr->getSize();
    }

    cout << "Unemployed Warriors:" << endl;

    if (warrior_vect.size() - hiredCount > 0){
        for (Warrior* warrior : warrior_vect){
            if (!warrior->getJobStatus()){
                cout << *warrior << endl;
            }
        }
    }
    else {
        cout << "NONE" << endl;
    }
}