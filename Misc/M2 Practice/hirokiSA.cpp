#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Zergling;
class StarCraft {
public:
    StarCraft(int code) : code(code) {}
    virtual ~StarCraft() {}

    StarCraft& operator=(const StarCraft& rhs) {
        if (this != &rhs) {
            code = rhs.code;
        }
        return *this;
    }

    StarCraft(const StarCraft& rhs) : code(rhs.code) {}

private:
    int code;
};


class BroodWar : public StarCraft{

    friend ostream& operator<<(ostream& os, const BroodWar& rhs);

    public:
        BroodWar(const string& name, int code) : name(name), StarCraft(code){}

        ~BroodWar(){
            for (size_t i = 0; i < zergs.size(); ++i){
                delete zergs[i];
                zergs[i] = nullptr;
            }
            
            zergs.clear();
        }
        
        BroodWar& operator=(const BroodWar& rhs){
            if (&rhs != this){

                for (size_t i = 0; i < zergs.size(); ++i){
                    delete zergs[i];
                    zergs[i] = nullptr;
                }
                zergs.clear();

                for (size_t i = 0; i < rhs.zergs.size(); ++i){
                    zergs.push_back(new Zergling(*(rhs.zergs[i])));
                }
            }

            return *this;
        }

        BroodWar(const BroodWar& rhs) : StarCraft(rhs), name(rhs.name){

            for (size_t i = 0; i < rhs.zergs.size(); ++i){
                zergs.push_back(new Zergling(*(rhs.zergs[i])));
            }

        }


        bool operator==(const BroodWar& rhs) const {
            if (zergs.size() == rhs.zergs.size()){

                for (size_t i = 0; i < zergs.size(); ++i){
                    if (*(zergs[i]) != *(rhs.zergs[i])){
                        return false;
                    }
                }
            return true;
            }

            return false;
        }

        explicit operator bool() const {
            return zergs.size() > 0;
        }


    private:
        string name;
        vector<Zergling*> zergs;
};

class Zergling {
public:
    Zergling() {}
    Zergling(const Zergling&) {}
    Zergling& operator=(const Zergling&) { return *this; }
    bool operator!=(const Zergling&) const { return false; }
    friend ostream& operator<<(ostream& os, const Zergling&) {
        os << "Zergling";
        return os;
    }
};


ostream& operator<<(ostream& os, const BroodWar& rhs){
    os << rhs.name << " " << endl;
    for (size_t i = 0; i < rhs.zergs.size(); ++i){
        os << "Zergling" << endl;

    }

    return os;
}

int main() {
    // Create some Zerglings
    Zergling* z1 = new Zergling();
    Zergling* z2 = new Zergling();
    Zergling* z3 = new Zergling();

    // Create a BroodWar object
    BroodWar brood1("Hive Cluster Alpha", 42);

    // Add Zerglings to brood1
    brood1 = BroodWar("Hive Cluster Alpha", 42);
    brood1.operator bool(); //Test explicit operator usage 

    cout << brood1; // Output brood1
    cout << "Test completed" << endl;

    return 0;
}
