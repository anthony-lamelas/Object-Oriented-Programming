#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;




class Performer{
    public:

    Performer(const string& n) : name(n) {}
    
    virtual void perform() const = 0;

    bool getJobStatus() const {
        return has_job;
    }

    bool hireMe() {
        has_job = true;
    }

    private:

    string name;
    bool has_job = false;

};

class Company{
    public:
        Company() {}

        bool hire(Performer& performer){
            if(performer.getJobStatus()){
                return false;
            } else {
                performers.push_back(&performer);
                performer.hireMe();
                return true;
            }
        }

        void showtime () const{
            for(const Performer* performer : performers){
                performer->perform();
            }
        }
    private:
        vector<Performer*> performers;

};

class Actor : public Performer{
    public:
    Actor(const string& n, const string& s) : Performer(n), script(s) {}

    void perform() const override {
        cout << "I am " << name << ". " << script << endl;
    }

    private:
        string name;
        string script;
};

class Mime : public Performer{
    public:
    Mime(const string& n) : Performer(n){}

    void perform() const override {
        cout << "(silence)" << endl;
    }

    private:
        string name;
};


int main() {
    Company troupe;
    Company otherTroupe;

    Actor frog("Froggie", "Hiya, kids!");
    Mime red("Red Skelton");
    Actor bogie("Humphrey Bogart", "Play it again.");

    troupe.hire(frog);
    otherTroupe.hire(frog); // Nothing happens. Froggie was already hired.
    troupe.hire(red);
    troupe.hire(bogie);
    troupe.showtime();

    return 0;
}