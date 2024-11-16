// #include <iostream>
// using namespace std;

// class Food {
// public:
//     virtual void output_type() = 0; // Pure virtual function
// };

// class Vegetable : public Food {
// public:
//     void output_type() override { // Overrides the pure virtual function
//         cout << "Vegetable "
//     }
// };

// class Potato : public Vegetable { 
//     // Inherits output_type() from Vegetable
// };

// int main() {
//     Potato gc;              // Line C: Create an instance of Potato
//     Food* pp = &gc;         // Line D: Pointer to base class pointing to Potato object
//     pp->output_type();      // Line E: Calls the overridden method in Vegetable
//     gc.output_type();       // Line F: Calls the inherited method directly on Potato object

//     return 0;
// }




// #include <iostream>
// #include <string>
// using namespace std;

// class Location {
// public:
//     Location(string loc, int count) : name(loc), size(count) { }

//     void display() { 
//         cout << name << ':' << size << endl; 
//     }

// private:
//     string name;
//     int size;
// };

// int main() {
//     Location thingOne("Tandon", 5212);
//     string s = "CSE";
//     thingOne = s; // This line will cause a compilation error
//     thingOne.display();

//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// class RebelShip {
// public:
//     RebelShip() {}

//     void attack(string weapon) {
//         cout << "RebelShip firing " << weapon;
//     }
// };

// class XWingFighter : public RebelShip {
// public:
//     virtual void transport() { 
//         cout << "Jump to hyperspace!"; 
//     }

//     void attack() {
//         cout << "XWingFighter firing laser cannons";
//     }
// };

// int main() {
//     XWingFighter* red_leader = new XWingFighter();
//     red_leader->attack("proton torpedoes");
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Base {
// public:
//     void show() { cout << "Base show" << endl; } // Non-virtual
// };

// class Derived : public Base {
// public:
//     void show() { cout << "Derived show" << endl; } // Overrides but not virtual
// };

// int main() {
//     Base* ptr;       // Pointer of type Base
//     Derived d;
//     ptr = &d;        // Pointer points to Derived object
//     ptr->show();     // Resolves to Base::show() at compile time
//     return 0;
// }

// class Player {
// protected:
//     void score_touchdown() {}
// };

// class FootballPlayer : public Player {
// public:
//     void win_game() {
//         score_touchdown(); // line A error bc must be this->score or smth, cant be called like that
//     }
// };

// int main() {
//     FootballPlayer fp;
//     fp.score_touchdown(); // line B error bc protected cant be accessed in main


// }

