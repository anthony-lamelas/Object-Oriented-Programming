#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// class Thing {
// public:
//     Thing(double x = 0) : x(x) {}  // line 1
//     void display() /*const*/ {              // line 2
//         cout << x;
//     }

// private:
//     double x;
// };

// int main() {
//     const Thing* th = new Thing;  // line 3
//     th->display();                // line 4
//     delete th;                    // line 5
// }


// class Thing {
// public:
//     Thing(double x = 0) : x(x) {}
//     void display() {
//         cout << x;
//     }

// private:
//     double x;
// };

// int main() {
//     Thing th;
//     th = 2.718;  // Assignment
//     th.display();
// }


// const int SIZE = 8;

// int main() {
//     int* arr = new int[SIZE];
//     for (int i = 0; i < SIZE; i++) {
//         arr[i] = i * i;
//     }
//     int* p = arr + SIZE - 4;
//     cout << p[1] << endl;
// }

// class Parent {
// public:
//     virtual void display() const { cout << "Parent "; }  // Line A
// };

// class Child : public Parent {
// public:
//     void display() const { cout << "Child "; }    // Line B
// };

// class Grandchild : public Child {
// public:
//     void display()   { cout << "Grandchild "; }    // Line C
// };

// int main() {
//     Child c;                                     // Line D
//     Grandchild gc;                               // Line E
//     const Parent* par = &gc;                    // Line F
//     par->display();
// }

// class Parent {
// public:
//     virtual void display() const = 0;  // Line A
// };

// void Parent::display() const {        // Line B
//     cout << "Parent";
// }

// class Child : public Parent {
// public:
//     void display() const {                  // Line C
//         cout << "Child";
//     }
// };

// void someFunc(Parent& val) {          // Line D
//     val.display();
// }

// int main() {
//     Child child;                      // Line E
//     someFunc(child);                  // Line F
// }


// class Parent {
// public:
//     Parent(int x) : x(x) {}  // Default value for x
//     virtual void display() const {
//         cout << "x:" << x << endl;
//     }
// private:
//     int x;
// };

// class Child : public Parent {
// public:
//     Child(int y) : Parent(0), y(y) {} // Explicitly initializes Parent's x to 0
//     void display() const override {   // Override Parent's display()
//         cout << "y:" << y << endl;
//     }
// private:
//     int y;
// };

// void someFunc(Parent& val) {
//     val.display(); // Calls display() based on dynamic type
// }

// int main() {
//     Child child(10);
//     child.Parent::display(); // Explicitly calls Parent's display()
//     someFunc(child);         // Pass Child to a function expecting Parent reference
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

// void someFunc(Derived& argA, Base& argB) {
//     argA.method(argB);
// }

// int main() {
//     Derived d;
//     Base b;
//     someFunc(d, d);  // Calls with two Derived objects
// }


// class Parent {
// public:
//     virtual void display() const { 
//         cout << "Parent "; 
//     }
// };

// class Child : public Parent {
// public:
//     void display() const override { 
//         cout << "Child "; 
//     }
// };

// class Gc : public Child {
// public:
//     void display() const override { 
//         cout << "Gc "; 
//     }
// };

// int main() {
//     vector<Parent*> vp;
//     vp.push_back(new Parent);
//     vp.push_back(new Child);
//     vp.push_back(new Gc);

//     for (const Parent* ptr : vp) {
//         ptr->display();
//     }

//     // Memory cleanup
//     for (Parent* ptr : vp) {
//         delete ptr;
//     }
// }
