#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// template <typename Iter, typename target>

// Iter find(Iter begin, Iter end, const target& val){

//     for(Iter iter = begin; iter != end; ++iter){
//         if(*iter == val){
//             return iter;
//         }
//     }

//     return end;

// }


// bool parity(int val){
//     int count = 0;

//     if(val == 0){
//         return false;
//     }

//     return (val % 2 == 1) != parity(val / 2);


// F != (T != (T != F ))


// }

// class Iterator{

//     //!=
//     friend bool operator!=(const Iterator& rhs, const Iterator& lhs){
//         return rhs.current != lhs.current;
//     }

//     Iterator(int* c = nullptr) : current(c){}

//     //* 
//     int& operator*() const {
//         return *current;
//     }

//     //++
//     Iterator& operator++(){
//         ++current;
//         return *this;
//     }

//     private:
//         int* current;

// };


struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void removeValue(Node*& head, int val) {

    while(head && head->data == val){
        Node* next = head;
        head = head->next;
        delete next;
        next = nullptr;
    }

    Node* current = head;

    while(current){
        Node* next = current->next;

        if(next && next->data == val){
            current->next = next->next;
            delete next;
            next = nullptr;
        }
        current = current->next;
    }
}



int main() {
// vector<double> myVector = {1.0,2.0,3.0};

// double product = 1.0;

// for(vector<double>::iterator it = myVector.begin(); it != myVector.end(); ++it){
//     product *= *it;
// }

// cout << product;

// cout << parity(6);

}