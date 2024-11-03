#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Bit {

public:

    friend ostream& operator<<(ostream& os, const Bit& bit){

        os << "Name: " << bit.name << "; Boss: ";
        if(bit.boss != nullptr){
            os << bit.boss->name << ";";
        } else{
            os << "none;";
        }
        os << " Bits: ";
        if(bit.employees.size() > 0){
            for (Bit* employee : bit.employees){
                os << employee->name << " ";
            }
        } else{
            os << "none";
        }
        os << ".";

        return os;

    }

    Bit(const string& n) : name(n), boss(nullptr) {}

    bool hire(Bit& new_hire){
        if(new_hire.boss == nullptr && &new_hire != this && boss != &new_hire){
            new_hire.boss = this;
            employees.push_back(&new_hire);
            return true;
        }else{
            cerr << "failed to hire" << endl;
            return false;
        }
    }

    bool quit(){
        Bit* old_boss = boss;
        size_t index;
        for(size_t i = 0; i < boss->employees.size(); i++){
            if (this == boss->employees[i]){
                index = i;
                break;
            }
        }
        if (index != -1) {

        for(size_t j = index; j < boss->employees.size() - 1; j++){
            boss->employees[index] = boss->employees[index +1];
        }
        
        boss->employees.pop_back();
        boss = nullptr;
        return true;
        }
        return false;
    }


private:
    string name;
    vector<Bit*> employees;
    Bit* boss;
};