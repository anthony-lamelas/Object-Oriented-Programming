#include <iostream>
using namespace std;

class Base{
};

class Derived : public Base{
};

int main(){
    Base base2;
    Derived derived2;

    base2 = derived2;
    //derived2 = base2;

    Base* base = nullptr;
    Derived* derived = nullptr;

    //derived = base;
    //fails because derived would lose info
    
    base = derived;
    //works because derived can always be treated like a base bc a derived
    // is a base object

    base = &base2;
    derived = &derived2;
    base = &derived2;
    //derived = &base2;
}