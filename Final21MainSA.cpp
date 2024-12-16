#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Member{

    public:

    Member(const string& s) : name(s), status(false) {}

    virtual void check_security() const = 0;

    string getName() const {return name;}

    void changeStatus()  {status = true;}

    bool getStatus() const {return status;}

    private:
        string name;
        bool status;

};

class Student : public Member {

    public:

    Student(const string& s, int sec) : Member(s), security(sec) {}

    void check_security() const {

        cout << getName() << ": has security level: " << security << endl;

    }

    private:
        int security;

};

class Faculty : public Member {

    public:

    Faculty(const string& s) : Member(s) {}

    void check_security() const {

        cout << getName() << ": has high level security" << endl;

    }
};


class University{
    public:
        University() {}


        bool add_member(Member& mem){
            if(mem.getStatus()){
                return false;
            } else {
                mem.changeStatus();
                members.push_back(&mem);
                return true;
            }
        }

       void security_check() const {
            for(size_t i = 0; i < members.size(); ++i){
                members[i]->check_security();
            }
       }


    private:
        vector<Member*> members;
};



int main() {
    University nyu;
    University columbia;
    Faculty depasquale("Peter DePasquale");
    Faculty sterling("John Sterling");
    Faculty reeves("Darryl Reeves");
    Student chen("Mike Chen", 100);
    Student smith("Sarah Smith", 100);
    Student liu("Christie Liu", 200);
    nyu.add_member(depasquale);
    nyu.add_member(sterling);
    nyu.add_member(reeves);
    columbia.add_member(reeves);
    nyu.add_member(chen);
    nyu.add_member(smith);
    nyu.add_member(liu);
    nyu.security_check();
}