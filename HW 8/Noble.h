/*
  Anthony Lamelas
*/

#ifndef NOBLE_HPP
#define NOBLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Protector.h"

namespace WarriorCraft {
  class Protector;
  class Noble;
  class Lord;
  
  // Output Operators
  std::ostream& operator<<(std::ostream& os, const Noble& noble);
  std::ostream& operator<<(std::ostream& os, const Lord& lord);

    

    // Noble Class (Lords, Fighters)
class Noble {
  public:

  Noble(const std::string& name);

  // Battle with Opponent
  void battle(Noble& opponent);

  // Gets the name
  const std::string& getName() const;

  // Gets strength 
  virtual int getStrength() const = 0;

  // Changes strength after fight
  virtual void setStrength(int champ_str, int loser_str) = 0;

  // Defend, different ouptut depending on type of Noble
  virtual void defend() const = 0;

  // Changes Noble to dead
  void kill();

  protected:
    // Gets the life status
    bool getStatus() const;
    void changeStatus();

  private:
    std::string noble_name;
    bool living;
};

class Lord : public Noble {
  public:

  Lord(const std::string& name);

    // Removes protector from army
    bool remove_protector(Protector& protector);

      // Hire protector
    bool hires(Protector& protector);

    // fires protector
    bool fires(Protector& protector);

    // Gets the total strength of the noble's army
    int getStrength() const override;

    // Updates army strength after the battle
    void setStrength(int champ_str, int loser_str) override;

    //Defend func
    void defend() const override;

    //Gets army
    const std::vector<Protector*> getArmy() const;


  private:
    std::vector<Protector*> army;
};

class PersonWithStrengthToFight : public Noble {
  public:

   PersonWithStrengthToFight(const std::string& name, int strength);

  // Get's the strength of the noble
    int getStrength() const override;

  // Changes strength after battle
  void setStrength(int champ_str, int loser_str) override;

  // Defend fuction
  void defend() const override;

  private:
    int strength;
};
}

#endif