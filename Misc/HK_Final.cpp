#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

// class Thing {};

// void func(const Thing& something){
    
//      const Thing* p = &something;

//     *p = 17;
// }2

// class Base {
// public:
//     virtual void foo(Base b) { 
//         cout << "Base::foo(Base)\n"; 
//     }
// };

// class Derived : public Base {
// public:
//     void foo(Derived d) { 
//         cout << "Derived::foo(Derived)\n"; 
//     }
// };

// int main() {
//     Derived der;          // line A
//     Base base = der;      // line A
//     base.foo(der);        // line B
//     der.foo(der);         // line C
// }



// class B {
// public:
//     B(int val = 42) : n(val) {}
//     virtual void foo() const { cout << "B"; }
// private:
//     int n;
// };

// class A {
// public:
//     void foo() { cout << "A"; }
// private:
//     B someB;
// };

// int main() {
//     A a;
//     a.foo();
// }


// #include <iostream>
// #include <string>
// using namespace std;

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
//     Cat(string name) : Pet(name) {
//     }
// };

// class Dog : public Pet {
// public:
//     Dog() : Pet("ruff") {}
//     void setCatName(Cat& rhs) {
//         rhs.setName("Mehitabel");  // A
//     }
//     void setDogName(Dog& rhs) {
//         rhs.setName("Fido");      // B
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

//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Base {
// public:
//     virtual void foo() { cout << " - Base::foo()\n"; }
// };

// class Derived : public Base {
// public:
//     virtual void foo() { cout << " - Derived::foo()\n"; }
// };

// void func(Base& arg) {
//     cout << "func(Base)"; 
//     arg.foo();
// }

// void func(Derived& arg) {
//     cout << "func(Derived)";
//     arg.foo();
// }

// void otherFunc(Base& arg) {
//     func(arg);
// }

// int main() {
//     Derived d;
//     otherFunc(d);
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class P1 {
// public:
//     void whoamI() { cout << "P1"; }
// };

// class P2 {
// public:
//     void whoamI() { cout << "P2"; }
// };

// class Child : public P2, public P1 {
//     // Inherits from both P2 and P1
// };

// int main() {
//     Child c;
//     c.whoamI();
//     return 0;
// }



///////////////////////////////////////////////////////////////////////////


// template <typename Iter, typename Pred>

// int count(Iter begin, Iter end, Pred predicate){
//     int count = 0;

//     for (Iter it = begin; it != end; ++it){
//         if(predicate(*it)){
//             count++;
//         }
//     }
//     return count;
// }

// int baseThree(int val){

//     if(val % 3 == 0){
//         return;
//     }

//     baseThree(val / 3);

//     cout << (val % 3);
// }


// struct TernNode {int data; TernNode *left, *mid, *right; };

// int treeMin(TernNode* root){


//     if(!root){
//         throw invalid_argument("no root");
//     }

//     int minVal = root->data;

//     if(!root->left && !root->right && !root->mid){
//         return minVal;
//     }

//     if(root->right){
//         if(treeMin((root->right)) < minVal){
//             minVal = treeMin((root->right));
//         }
//     }

//     if(root->left){
//         if(treeMin((root->left)) < minVal){
//             minVal = treeMin((root->left));
//         } 
//     }

//     if(root->mid){
//         if(treeMin((root->mid)) < minVal){
//             return treeMin((root->mid));
//         } 
//     }

//     return minVal;
// }


// #include <iostream>
// using namespace std;

// class SLL {  // SLL is short for Singly Linked List
//     struct Node {
//         Node(int data = 0, Node* next = nullptr) : data(data), next(next), prev(prev) {}
//         int data;
//         Node* next;
//         Node* prev;
//     };

// public:
//     SLL() { headPtr = nullptr; }

//     // Adds the data to the head of the Singly Linked List
//     void addFront(int data);

//     // begin and end methods correctly defined. You don't define them.

//     class Iterator{
           

//         public:

//             Iterator(Node* ptr) : current(ptr) {}

//             int& operator*() const{
//                 return current->data;
//             }

//             bool operator==(const Iterator& rhs){
//                 return current == rhs.current;
//             }

//             bool operator!=( Iterator& rhs){
//                 return !(current == rhs.current);
//             }

//             Iterator& operator++(){
//                 current = current ->next;
//                 return *this;
//             }

//             Iterator& operator--(){
//                 current = current->prev;
//                 return *this;
//             }
         
//         private:
//             Node* current;
//     };

//      // Begin iterator
//     Iterator begin() {
//         return Iterator(headPtr);
//     }

//     // End iterator (nullptr represents the end of the list)
//     Iterator end() {
//         return Iterator(nullptr);
//     }

// private:
//     // This is the only field in SLL. In an empty list, headPtr is null.
//     // The last Node in an SLL has a next pointer that holds null.
//     Node* headPtr;
// };



// // Function to double every int in the SLL
// void doubleValues(SLL& v) {
//     for (int& val : v) {
//         val *= 2;
//     }
// }



// struct Node {
//     Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
//     int data;
//     Node* next;
// };

// bool removeLastValue(Node* head, int val){
//         if (!head) {
//         return true;
//     }

//      if (head->data == val && head->next == nullptr) {
//         delete head;
//         head = nullptr;
//         return false; 
//     }

//     Node* current = head;
//     Node* value = nullptr;

//     while(current){
//         if(current->next && current->next->data == val){
//             value = current;
//         }
//     current = current->next;
//     }

//     if(value != nullptr){
//         Node* Todelete = value->next;
//         value->next = value->next->next;

//         delete Todelete;
//         Todelete = nullptr;

//         return false;
//     }
//     return true;
// }








// int main() {
//     vector<double> myList = {1.2, 2.3, 3.4}; // Example values

//     int sum = 0;
//     for (vector<double>::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
//         sum += *iter;
//     }

//     cout << "Sum: " << sum << endl;

// }



