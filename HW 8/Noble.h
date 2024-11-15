/*
  Anthony Lamelas
*/

#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <string>
#include <vector>
#include "Protector.h"

namespace WarriorCraft {
  class Protector;
  class Noble;
  class Lord;
  
    // Noble Class (Lords, Fighters)
class Noble {

  public:

  Noble(const std::string& name);

  // Battle with Opponent
  void battle(Noble& opponent);

  // Gets the name
  const std::string& getName() const;

  // Gets strength 
  virtual double getStrength() const = 0;

  // Changes strength after fight
  virtual void setStrength(double champ_str, double loser_str) = 0;

  // Defend, different ouptut depending on type of Noble
  virtual void defend() const = 0;

  // Changes Noble to dead
  virtual void kill() = 0;

  // Gets life status
  bool getStatus() const;

  // Changes life status
  void changeStatus();

  private:
    std::string noble_name;
    bool living;
};

class Lord : public Noble {

    //Output Operator
    friend std::ostream& operator<<(std::ostream& os, const Lord& lord);

  public:

  Lord(const std::string& name);

    // Removes protector from army
    bool remove_protector(Protector& protector);

      // Hire protector
    bool hires(Protector& protector);

    // fires protector
    bool fires(Protector& protector);

    // Gets the total strength of the noble's army
    double getStrength() const override;

    // Updates army strength after the battle
    void setStrength(double champ_str, double loser_str) override;

    //Defend func
    void defend() const override;

    //Gets army
    const std::vector<Protector*> getArmy() const;

    //You die
    void kill();


  private:
    std::vector<Protector*> army;
};

class PersonWithStrengthToFight : public Noble {

    // Output Operator
  friend std::ostream& operator<<(std::ostream& os, 
  const WarriorCraft::PersonWithStrengthToFight& noble);

  public:

   PersonWithStrengthToFight(const std::string& name, double strength);

  // Get's the strength of the noble
    double getStrength() const override;

  // Changes strength after battle
  void setStrength(double champ_str, double loser_str) override;

  // Defend fuction
  void defend() const override;

  //You die
  void kill();

  private:
    double strength;
};
}

#endif