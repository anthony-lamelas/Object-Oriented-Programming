//Anthony Lamelas Warrior.h file

#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft {
    class Noble;

    class Warrior{
     // Operator overload for Warrior
    friend std::ostream& operator<<(std::ostream& os, const Warrior& warrior);

    public:
    Warrior(const std::string& n, double s);

        // Methods for Warrior
        const std::string& getName() const;
        double getStrength() const;
        void setStrength(double newStrength);
        bool isHired() const;
        void changeJobStatus();
        Noble* getBoss() const;
        void setBoss(Noble* noblep);
        bool runaway();
        

    private:
        std::string warr_name;
        double strength;
        bool has_job;
        Noble* boss;
    };
}

#endif