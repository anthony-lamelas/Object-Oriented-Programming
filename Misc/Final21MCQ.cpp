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