//Anthony Lamelas Noble.h file

#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft {
    class Warrior;

    class Noble {
        friend std::ostream& operator<<(std::ostream& os, const Noble& noble);

public:
    // Initialization
    Noble(const std::string& n);

    // Methods for Noble
    const std::string& getName() const;
    bool getStatus() const;
    size_t getSize() const;
    const double getArmyStrength() const;
    void setArmyStrength(double champ_str, double loser_str);
    void kill();
    bool hire(Warrior& warrior);
    bool fire(Warrior& warrior);
    void battle(Noble& opponent);
    bool remove_warrior(Warrior& warrior);

private:
    std::string noble_name;
    std::vector<Warrior*> army;
    bool living;
    };

}
#endif