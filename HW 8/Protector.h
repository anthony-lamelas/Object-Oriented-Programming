/*
  Anthony Lamelas
*/

#ifndef PROTECTOR_HPP
#define PROTECTOR_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "Noble.h"

namespace WarriorCraft {
    class Protector;
    class Noble;

//Output Operator
    std::ostream& operator<<(std::ostream& os, const Protector& protector);

    class Lord;

class Protector {
    public:

  Protector(const std::string& name, int str);

    // Getters and Setters
    const std::string& getName() const;
    int getStrength() const;
    void setStrength(int newStrength);
    Lord* getBoss() const;
    void setBoss(Lord* noblep);

    // Checks if has boss
    bool isHired() const;

    // Changes job status
    void changeJobStatus();

    // When protector leaves army
    bool runaway();

    //defend 
    virtual void defend() const = 0;

    private:
      std::string protector_name;
      int strength;
      bool has_job;
      Lord* boss;

};

class Warrior : public Protector {
    public:
        using Protector::Protector;
        void defend() const override;
    };  

class Wizard : public Protector {
    public:
        using Protector::Protector;
        void defend() const override;
    };  

class Archer : public Warrior {
    public:
        using Warrior::Warrior;
        void defend() const override;
    };  

class Swordsman : public Warrior {
    public:
        using Warrior::Warrior;
        void defend() const override;
    };
}

#endif