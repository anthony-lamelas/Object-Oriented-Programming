#include <string>
#include<iostream>
#include<vector>
using namespace std;

class Superhero {
    Superhero(const string& n) : name(n) {}


    private:
        string name;
};


class Avenger : public Superhero {


    friend ostream& operator<<(ostream& os, const Avenger& rhs);
        

    public:
        Avenger(const string& name, int age) : Superhero(name), age(age){}

        size_t getNumPowers() {
            return powers.size();
        }

    ~Avenger(){

        for(size_t i = 0; i < powers.size(); ++i){
            delete powers[i];
            powers[i] = nullptr;
        }
        powers.clear();
    }

    Avenger& operator=(const Avenger& rhs){
        Superhero::operator=(rhs);
        age = rhs.age;

        for(size_t i = 0; i < powers.size(); ++i){
            delete powers[i];
            powers[i] = nullptr;
        }
        powers.clear();

        for(size_t i = 0; i < rhs.powers.size(); ++i){
            powers.push_back(new Power(*rhs.powers[i]));
        }

        return *this;
    }


    Avenger(const Avenger& rhs) : Superhero(rhs), age(rhs.age) {

        for(size_t i = 0; i < rhs.powers.size(); ++i){
            powers.push_back(new Power(*rhs.powers[i]));
        }
    }

    friend bool operator==(const Avenger& rhs, const Avenger& lhs){};

    explicit bool operator(const Avenger& rhs){
        if(getNumPowers() == 3){
            return true;
        }
        return false;
    }

    private:
        string name;
        int age;
        vector<Power*> powers;




};

bool operator==(const Avenger& rhs, const Avenger& lhs){

    if (rhs.getNumPowers() != lhs.getNumPowers()){
        return false;
    } else {
    
         for(size_t i = 0; i < rhs.getNumPowers(); ++i){
            if(*rhs.powers[i] != *lhs.powers[i]){
                return false;
            }
        }

    return true;

    }
}


ostream& operator<<(ostream& os, const Avenger& rhs){
        os << "age: " << rhs.age << "name: " << rhs.name << endl;

        if (rhs.powers.size() == 0){
            os << "powerless" << endl;
        }

        for(size_t i = 0; i < rhs.powers.size(); ++i){
            os << *rhs.powers[i] << endl;
        }
        
        return os;
    }


class Power {};