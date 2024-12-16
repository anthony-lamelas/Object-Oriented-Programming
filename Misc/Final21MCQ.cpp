#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;


// class Television {
//     virtual void connect() {
//     cout << "scanning channels...";
// }
// };

// class Computer {
//     virtual void connect() {
//     cout << "joining network...";
// }
// };

//     class SmartTelevision: public Television, public Computer {};

// int main() {
//     SmartTelevision x287;
//     x287.connect();
// }


// legal because pointer arithmetic wont crash, just prints 2

// void increment(int* num, int n_times) {
// for (int i = 0; i < n_times; i++) num = num + 1;
// }
// int main() {
// int val = 2;
// increment(&val, 3);
// cout << val;
// }



// class GreetingCard {
// public:
// GreetingCard(double price, string msg = ":-)") :
// price(price), msg(msg) { } // Line 1
// void display() {
// cout << '$' << price << " - " << msg; // Line 2
// }
// private:
// double price;
// string msg;
// };


// int main() {
// GreetingCard card(3.99, "Happy Birthday!"); // Line 3
// card = 5.99; // Line 4
// card.display(); // Line 5
// }

// class Pet {
// public:
// virtual void communicate() const = 0; // Line 1
// };
// class Cat : public Pet {
// public:
// void communicate() const {
// cout << "meow" << endl; // Line 2
// }
// };
// class Dog : public Pet {
// public:
// void communicate() {
// cout << "woof" << endl; // Line 3
// }

// };
// void pet(const Pet& p) {
// p.communicate(); // Line 4
// }
// int main() {
// Dog fido; // Line 5
// pet(fido); // Line 6
// }


// class Derived;  // Forward declaration

// class Base {
// public:
//     virtual void method(Base& arg) {
//         cout << "Base::method(Base)\n";
//     }
//     virtual void method(Derived& arg) {
//         cout << "Base::method(Derived)\n";
//     }
// };

// class Derived : public Base {
// public:
//     void method(Base& arg) override {
//         cout << "Derived::method(Base)\n";
//     }
//     void method(Derived& arg) override {
//         cout << "Derived::method(Derived)\n";
//     }
// };

// void someFunc(Base& argA, Derived& argB) {
//     argA.method(argB);
// }

// int main() {
//     Derived d;
//     Derived e;

//     someFunc(e,d);
// }


// class Base {
// public:
//     virtual void foo(Base& b) { cout << "Base::foo(Base)\n"; }
// };

// class Derived: public Base {
// public:
//     void foo(Derived d) { cout << "Derived::foo(Derived)\n"; }
// };

// int main() {
//     Derived der;
//     Base base = der;       // line A
//     base.foo(der);         // line B
//     der.foo(base);         // line C
// }


// class B {
// public:
//     B(int val=0) : n() {}
//     virtual void foo() const { cout << "B"; }
// private:
//     int n;
// };

// class A {
// public:
//     A(int val=0) : someB(val) {}
//     void foo() { cout << "A"; }
// private:
//     B someB;
// };

// int main() {
//     A a;
//     a.foo();
// }




// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     vector<int> v { 6, 42, 28, 17, 16, 49 };
//     cout << *find_if(v.begin() + 1, v.end(),
//                      [](int val) { return val % 2 == 0; })
//          << endl;
// }


// class Pet {
// public:
//     Pet(string name) : name(name) {}
//     void display() { cout << name << ' '; }
// protected:
//     void setName(string name) { this->name = name; }
// private:
//     string name;
// };

// class Cat : public Pet {
// public:
//     Cat(string name) : Pet(name) {}
// };

// class Dog : public Pet {
// public:
//     Dog() : Pet("ruff") {}
//     void setCatName(Cat& rhs) {
//         rhs.setName("Mehitabel");   // A
//     }
//     void setDogName(Dog& rhs) {
//         rhs.setName("Fido");        // B
//     }
// };

// int main() {
//     Cat felix("Felix");
//     Dog fido;
//     Dog rover;

//     fido.setCatName(felix);
//     felix.display();
//     fido.setDogName(fido);
//     fido.display();
// }


// #include <iostream>
// using namespace std;

// class Parent {
// public:
//     Parent(int x) : x(x) {}
//     virtual void display() const {
//         cout << "x:" << x << endl;
//     }
// private:
//     int x;
// };

// class Child : public Parent {
// public:
//     Child(int y) : y(y) {}
//     void display() const {
//         cout << "y:" << y << endl;
//     }
// private:
//     int y;
// }; 

// void someFunc(Parent& val) {
//     val.display();
// }

// int main() {
//     Child child(10);
//     someFunc(child);
// }
