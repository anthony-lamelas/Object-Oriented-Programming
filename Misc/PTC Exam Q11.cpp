#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Employee{

    friend ostream& operator <<(ostream& os, Employee& employee){
        os << "Name: " << employee.name << endl;
        os << "Boss: ";
        if (employee.boss != nullptr){
            os << employee.boss->name << endl;
        } else {
            os << "I am the boss." << endl;
        }

        os << "Team... " << endl;

        for(Employee* emp : employee.workers){
            os << emp->name << endl;
        }
        return os;
    }


    public:
        Employee(const string& n, Employee* b = nullptr) : name(n), boss(b) {}

        bool addToTeam(Employee& emp){
            if(emp.boss == nullptr){
                emp.boss = this;
                workers.push_back(&emp);
                return true;
            }
            return false;
        }

        bool removeFromTeam(Employee& emp){

            for(size_t i = 0; i < workers.size(); ++i){
                if (workers[i] == &emp){
                    emp.boss = nullptr;
                    for (size_t j = i; j < workers.size() - 1; ++j){
                        workers[j] = workers[j+1];
                    }
                    workers.pop_back();
                    return true;
                }
            }
            return false;

        }


    private:
        string name;
        Employee* boss;
        vector<Employee*> workers;

};