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