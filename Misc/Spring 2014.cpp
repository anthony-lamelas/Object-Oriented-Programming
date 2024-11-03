#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
    public:

    Person(const string& n) : name(n), parent(nullptr) {}

    void runaway() {
        if (parent) {
            for(size_t i = 0; i < parent->children.size(); i++){

                if (parent->children[i] == this){
                    for(size_t j = i; j < parent->children.size(); j++){
                        parent->children[j] = parent->children[j+1];
                    }
                    parent->children.pop_back();
                }

            }
        }
        parent = nullptr;
    }

    void adopt(Person& orphan){
        if (this == &orphan || orphan.parent != nullptr){
            return;
        }
        orphan.parent = this;
        children.push_back(&orphan);
    }


    void display() const {
        cout << "Person: " << name << "; Parent: ";
        if(parent){
            cout << parent->name;
        } else {cout << "none";}
        cout << "; Children: ";

        if(children.size() > 0){
            for(Person* child : children){
                cout << child->name << " ";
            }
            cout << "." << endl;
        }
    }
    private:
        string name;
        vector<Person*> children;
        Person* parent;
};


int main() {
    Person moe("Moe");
    Person larry("Larry");
    Person curly("Curly");
    Person curly2("Curly");

    moe.adopt(larry);
    larry.display(); // Outputs: Person: Larry; Parent: Moe; Children: none.
    moe.adopt(curly);
    moe.adopt(curly2); // Now we have two children named Curly
    moe.display(); // Outputs: Person: Moe; Parent: none; Children: Larry Curly Curly.

    larry.adopt(moe); // No effect
    moe.adopt(moe);   // No effect
    moe.adopt(larry); // No effect
    moe.display(); // Outputs: Person: Moe; Parent: none; Children: Larry Curly Curly.

    larry.runaway();
    larry.adopt(moe); // Larry is now Moe's parent, not his child
    moe.display();    // Outputs: Person: Moe; Parent: Larry; Children: Curly Curly.
    larry.display();  // Outputs: Person: Larry; Parent: none; Children: Moe.
}