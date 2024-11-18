#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Superbeing {
public:
    Superbeing(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    virtual ~Superbeing() {}

private:
    string name;
};

class Villain : public Superbeing {
    friend ostream& operator<<(ostream& os, const Villain& rhs);

    friend bool operator==(const Villain& lhs, const Villain& rhs);

    public:

    Villain(const string& name, int str) : Superbeing(name), strength(str) {}


    void addSkill(Skill* skill){
        skills.push_back(skill);
    }

    ~Villain(){
        for(size_t i = 0; i < skills.size(); ++i){
            delete skills[i];
            skills[i] = nullptr;
        }
        skills.clear();
    }

    Villain(const Villain& rhs) : Superbeing(rhs), strength(rhs.strength){
        for(size_t i = 0; i < rhs.skills.size(); ++i){
            skills.push_back(new Skill(*(rhs.skills[i])));
        }
    }

    Villain& operator=(const Villain& rhs){
        if(&rhs != this){
            strength = rhs.strength;

            for(size_t i = 0; i < skills.size(); ++i){
                delete skills[i];
                skills[i] = nullptr;
            }
            skills.clear();

            for(size_t i = 0; i < rhs.skills.size(); ++i){
                skills.push_back(new Skill(*(rhs.skills[i])));
            }

        }
        return *this;
    }

    explicit operator bool const(){
        return skills.size() > 0;
    }

    private:
        string name;
        int strength;
        vector<Skill*> skills;


};

ostream& operator<<(ostream& os, const Villain& rhs){
    os << "Villain: " << rhs.name << endl;
    os << "Strength: " << rhs.strength << endl;
    os << "Skills: ";

    if (rhs.skills.size() == 0){
        os << "None" << endl;
    }

    for(size_t i = 0; i < rhs.skills.size(); ++i){
        os << *(rhs.skills[i]) << endl;
    }
}

bool operator==(const Villain& lhs, const Villain& rhs) {
    if((lhs.strength != rhs.strength) || lhs.skills.size() != rhs.skills.size()){
        return false;
    }

    for(size_t i = 0; i < lhs.skills.size(); ++i){

        if(*(lhs.skills[i]) != *(rhs.skills[i])){
            return false;
        }
    }
    return true;
}


class Skill {
public:
    Skill(const string& skillName, int powerLevel) 
        : name(skillName), power(powerLevel) {}

    Skill(const Skill& other) 
        : name(other.name), power(other.power) {}

    Skill& operator=(const Skill& other) {
        if (this != &other) {
            name = other.name;
            power = other.power;
        }
        return *this;
    }

    bool operator==(const Skill& other) const {
        return name == other.name && power == other.power;
    }

    bool operator!=(const Skill& other) const {
    return !(*this == other);
}

    friend ostream& operator<<(ostream& os, const Skill& skill) {
        os << skill.name << " (" << skill.power << ")";
        return os;
    }

    ~Skill() {}

private:
    string name;
    int power;
};


int main() {
    Skill* fireball = new Skill("Fireball", 10);
Skill* iceBlast = new Skill("Ice Blast", 12);

Villain v1("Loki", 100);
v1.addSkill(fireball);
v1.addSkill(iceBlast);

Villain v2 = v1;

cout << v1 << endl;

if (v1 == v2) {
    cout << "Loki is equal to his clone!" << endl;
}

}