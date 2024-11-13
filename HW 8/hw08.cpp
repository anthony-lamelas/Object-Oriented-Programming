/*
  Anthony Lamelas
  Noble and protector program, Nobles can fight or have armies with protectors,
  protectors can be wizards or protectors
  protectors can be archers or swordsmen
  CS2124 hw08.cpp
  -jbs

 */

  //Close gap in vector when fired or runaway
  //Change str of wizard name to magic

#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

// Noble Class (Lords, Fighters)
class Noble {
  public:

  Noble(const string& name);

  // Battle with Opponent
  virtual void battle(Noble& opponent) = 0;

    // Gets the name
    const string& getName() const;

    // Gets the life status
    bool getStatus() const;

    // Changes Noble to dead
    void kill();

  protected:
    string noble_name;
    bool living;
};

class Lord : public Noble {
  public:

  Lord(const string& name);

  void battle(Noble& opponent) override;

  // Gets the army size
    size_t getSize() const;

    //Removes protector from army
    bool remove_protector(Protector& protector);

      // Hire protector
    bool hires(Protector& protector);

    // Fire protector
    bool fire(Protector& protector);

    // Gets the total strength of the noble's army
    const double getArmyStrength() const;

    // Updates army strength after the battle
    void setArmyStrength(double champ_str, double loser_str);


  private:
    vector<Protector*> army;
};

class PersonWithStrengthToFight : public Noble {
  public:

   PersonWithStrengthToFight(const string& name, const double& strength);


  void battle(Noble& opponent) override;

  private:
    double strength;
};

class Protector {

  Protector(const string& name, double str);

    const string& getName() const;
    double getStrength() const;
    void setStrength(double newStrength);
    bool isHired() const;
    void changeJobStatus();
    Noble* getBoss() const;
    void setBoss(Noble* noblep);
    bool runaway();

    private:
      string protector_name;
      double strength;
      bool has_job;
      Noble* boss;

};

class Wizard : public Protector {
  Wizard(const string& name, double str);

};

class protector : public Protector {
  protector(const string& name, double str);


};

class Archer : public protector {
  Archer(const string& name, double str);

};

class Swordsman : public protector {
  Swordsman(const string& name, double str);


};

//
// Test Code
//
int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250); 	
    Lord janet("Janet");	
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);	
    janet.hires(stout);	
    janet.hires(samantha);     // fails because samantha works for sam.
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);	
    cout << "\n==========\nNobles: \n"
	 << sam << endl
	 << randy << endl
	 << janet << endl
	 << barclay << endl
	 << joe << endl
	 << "\n==========\n";
    joe.battle(randy);	            // joe has no army and dies.
    joe.battle(sam);	            // joe is dead
    janet.battle(barclay);          // barclay wins
    Archer pethora("Pethora", 50);	
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);          // janet is dead, so can't hire
    sam.hires(thora);              // sam brings in reinforcements
    sam.hires(pethora);
    sam.hires(merlin);
    janet.battle(barclay);	   // Silly janet
    sam.battle(barclay);           // Go Sam!
    samantha.runaway();            // Samantha has had enough
    sam.fires(thora);              // These layoffs! Sam fires thora.
    joe.battle(barclay);           // They're both dead already

    cout << "\n==========\nNobles: \n"
	 << sam << endl
	 << randy << endl
	 << janet << endl
	 << barclay << endl
	 << joe << endl
	 << "==========\n";
} // main


Noble::Noble(const string& name) : noble_name(name), living(true) {}

// Gets the name
const string& Noble::getName() const { return noble_name; }

// Gets the life status
bool Noble::getStatus() const { return living; }

void Noble::kill() {
        living = false;
        // Makes all protector strengths 0 
        for (Protector* const& protector : army) {
            protector->setStrength(0);
            protector->setBoss(nullptr);
        }
    }

Lord::Lord(const string& name) : Noble(name){}

size_t Lord::getSize() const { return army.size(); }

// Gets the total strength of the noble's army
const double Lord::getArmyStrength() const {
        double total_str = 0;
        for ( protector* const& protector : army) {
            total_str += protector->getStrength();
        }
        return total_str;
    }

// Updates army strength after the battle
void Lord::setArmyStrength(double champ_str, double loser_str) {
        double str_ratio = loser_str / champ_str;
        for (protector* const protector : army) {
            double new_str = protector->getStrength() * (1 - str_ratio);
            protector->setStrength(new_str);
        }
    }
// Hire protector
bool Lord::hires(Protector& protector) {
        if (protector.isHired() || !living) {
            cout << noble_name << " failed to hire " << protector.getName() 
            << endl;
            return false;
        } else {
            protector.changeJobStatus();
            army.push_back(&protector);
            protector.setBoss(this);
            return true;
        }
    }

// Fire protector
bool Lord::fire(Protector& protector) {
    if (!living) {
        return false;
    }
    if (remove_protector(protector)){
        cout << protector.getName() << ", you don't work for me anymore  ! -- " 
        << noble_name << "." << endl;
        return true;
        }

        return false;
}

void Lord::battle(Noble& opponent) {
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

bool Lord::remove_protector(Protector& protector) {
    bool found = false;
    int index;

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

PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, 
const double& str) : Noble(name), strength(str) {}

void PersonWithStrengthToFight::battle(Noble& opponent){

}

Protector::Protector(const string& name, double str) : protector_name(name), 
strength(str){}

const string& Protector::getName() const { return protector_name; }
double Protector::getStrength() const { return strength; }
void Protector::setStrength(double newStrength) { strength = newStrength; }
bool Protector::isHired() const { return has_job; }
void Protector::changeJobStatus() { has_job = !has_job; }
void Protector::setBoss(Noble* noblep) { boss = noblep; }
Noble* Protector::getBoss() const  {return boss; }

bool Protector::runaway() {
        if (strength == 0) {  // fail if Protector is dead
            cout << protector_name << " is already dead!" << endl;
            return false;
        }
        if (!boss) {  // fail if boss does not exist
            cout << protector_name << " has no boss.";
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



//Noble Operator

//Lord Operator

//PersonWithStrengthToFight Operator

//Protector Operator

//Wizard Operator

//Warroir Operator

//Archer Operator