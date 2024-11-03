#include <iostream>
#include <vector>
#include <string>
using namespace std;


// create base class with eat() - 
// Create derived class with eat() invoking base's eat + purr()
// Do we need a destructor? (overridable?)
class Pet{
public:
//    Pet(const string& n = "un-named" ) :name(n) { cout << "Pet::Pet()" << endl; }
    void display() const { cout << "Name: " << name << endl; }
private:
    string name;
};
class Cat : public Pet {
public:
    Cat(const string& n = "un-named_2") /* :Pet(n)*/ { cout << "Cat::Cat()" << endl; }
private:

};

int main() {
	
    // Create objects of base class Pet (single method, eat, name) 
    // and 3 child classes: Cat, Slug and Roach ( eat )
//    Pet p; p.display();
    Cat c; c.display();

    // Invoke func by value (keyword?)

    // Invoke by ref 
	
	// Invoke by pointer


    // create vector of objects + push all 4 objects + eat

    // create vector of refs + push all 4 objects + eat ?

    // Adding attributes + invoking base constructor - done

    // Add another attribute
	
 
    /////////////////////////////////////////////////////////////////////
    // Can we assign "pointer to base" to address-of derived?
    // Can we assign "pointer to derived" to address-of base?

    // Adding a derived method (purr) - Who can call the drived's method?
        // 1) method has to exist for declared type
        // 2) which version of that overriden method to pick depends on actual type

    // A polymorphic call is routed correctly to derived::eat() when
    // 1) using pointer/reference
    // 2) eat() is a virtual method (overridable)


    // protected ////////////////////////////////////////////////////////
	// Better used for methods not attributes (getName() )

    // Can a method in a Cat object access protected getName in a Roach object?

    // Can a method in a Cat object access protected getName in another Cat object?

    // attribute redifinition


    /////////////////////////////////////////////////////////////////////
    // create a WildCat + 2 keywords

    // Can a method in WildCat object access getName in a Cat object (Kattie) ?
    
    // constructor inheritance

    // override vs overload vs redefine


}
