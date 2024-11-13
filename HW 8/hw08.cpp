/*
  Anthony Lamelas
  Noble and Warrior program, Nobles can fight or have armies with protectors,
  protectors can be wizards or warriors
  Warriors can be archers or swordsmen
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

    //Removes Warrior from army
    bool remove_protector(Protector& protector);

      // Hire Warrior
    bool hires(Protector& protector);

    // Fire Warrior
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

   PersonWithStrengthToFight(const string& name, int strength);


  void battle(Noble& opponent) override;

  private:
    int strength;
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

class Warrior : public Protector {
  Warrior(const string& name, double str);


};

class Archer : public Warrior {
  Archer(const string& name, double str);

};

class Swordsman : public Warrior {
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

