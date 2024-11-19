#include <string>
#include<iostream>
using namespace std;

// void Thing(const int& x) {
//     int* const p = &x; // line A //error here because const from func def must match the pointer 
//     int y = x; // line B
//     cout << *p << ' '; // line C
//     y = 28; // line D
// }


// class Parent {
// public:
// virtual void Thing() = 0; // Line A
// };

// class Child : public Parent {
// public:
// void Thing() { cout << "Child\n"; } // Line B

// };
// class GrandChild : public Child { };


// int main() {
//     GrandChild gc; // Line C
//     Parent* pp = &gc; // Line D
//     pp->Thing(); // Line E
//     gc.Thing(); // Line F
// }


// class Thing {
// public:
//     Thing(string s, int n) { str = s; num = n; }
//     void display() { cout << str << ':' << num << endl; }
//     private:
//     string str;
//     int num;
// };

// int main() {
//     Thing thingOne("abc", 0);
//     string s = "def";
//     thingOne = s;
//     thingOne.display();
// }


// class Pet {
//     public:
//     virtual void eat() { cout << "Pet::eat\n"; }
// };
// class Cat : public Pet {
//     public:
//     void eat() { cout << "Cat::eat\n"; }
// };
// int main() {
//     Pet* petP = new Cat();
//     Cat* catP = petP; error because cannot point up on hierarchy. Cat cannot go up to pet
//     catP->eat();
// }

// class Derived; // Yes, we need this.
// class Base {
// public:
// virtual void method(Base& arg) {
// cout << "Base::method(Base)\n";
// }
// virtual void method(Derived& arg) {
// cout << "Base::method(Derived)\n";
// }
// };
// class Derived : public Base {
// public:
// void method(Base& arg) {
// cout << "Derived::method(Base)\n";
// }
// void method(Derived& arg) {
// cout << "Derived::method(Derived)\n";
// }
// };
// void someFunc(Base& argA, Base& argB) {
// argA.method(argB);
// }
// int main() {
// Derived d;
// Base b;
// someFunc(d, b);
// }

// class FlyingMachine {
// public:
// FlyingMachine() {}
// virtual void fly() { cout << "In FlyingMachine fly()"; }

// virtual void crash() = 0;
// };
// class HangGlider : public FlyingMachine {
// public:
// virtual void crash() { cout << "In HangGlider crashing()"; }
// void fly() { cout << "In HangGlider fly()"; }
// };

// int main() {
// HangGlider hanger;

// HangGlider* hp = &hanger;
// FlyingMachine* fp = hp;


// fp->crash();

// }


// class FederationStarship {
// public:
// FederationStarship() {}
// void attack(string weapon) {
// cout << "FederationStarship firing " << weapon;
// }
// };
// class Constitution : public FederationStarship {
// public:
// virtual void transport() { cout << "Beam me up!"; }
// void attack() {
// cout << "Constitution firing photon torpedos";
// }
// };

// int main() {
// FederationStarship* NCC_1701 = new Constitution();
// NCC_1701->attack("phasers");
// }

// #include <iostream>
// using namespace std;

// class Member {
// public:
//     Member() { cout << 'a'; }
//     ~Member() { cout << 'b'; }
// };

// class Base {
//     Member member;

// public:
//     Base() { cout << 'c'; }
//     ~Base() { cout << 'd'; }
// };

// class Derived : public Base {
//     Member mem;
// public:
//     Derived() { cout << 'e'; }
//     ~Derived() { cout << 'f'; }
// };

// int main() {
//     Derived der;
//     return 0;
// }
