/*
Anthony Lamelas, polynomial.cpp file for polynomial linked list homework
*/

#include <iostream>
#include <vector>
#include "polynomial.h"
using namespace std;

namespace linkedPolynomial {

    // Constructors
    Polynomial::Polynomial() : head(new NodeTerm()), degree(0) {}  

    Polynomial::Polynomial(const std::vector<int>& coefficients)
        : head(nullptr), degree(coefficients.size() - 1) { 
        NodeTerm* tail = nullptr;  // Tail pointer to build the linked list
        bool lead = false;

        for (int coefficient : coefficients) {
            if(!lead && coefficient == 0){
                
            }
            if (!head) {
                // Creates first node not head
                head = new NodeTerm(coefficient);
                tail = head;
            } else {
                // Adds new node
                tail->next = new NodeTerm(coefficient);
                tail = tail->next;
            }
        }
        clearEndingZeroes(); 

        NodeTerm* current = head;
        while(current){

            current = current->next;

        }
        
    }

//     void Polynomial::clearLeadingZeroes() {

//         if(head->coefficient != 0){
//             return;
//         }
//         NodeTerm* current = head;
//         bool flag = false;

//         while(current->coefficient == 0){
//             flag = true;
//             head->next = current->next;
//             delete current;
//             current = current->next;

//             --degree;
//         }

//         if(head->coefficient == 0){
//             NodeTerm* deleted = head->next;
//             NodeTerm* nextNext = deleted->next;
//             head->coefficient = deleted->coefficient;
//             delete deleted;

//         head->next = nextNext;
//         }

//         NodeTerm* current1 = this->head;

// }


    Polynomial::NodeTerm::NodeTerm(int coefficient, NodeTerm* next) 
        : coefficient(coefficient), next(next) {}  

    // Copy Control
    Polynomial::Polynomial(const Polynomial& rhs) 
        : head(nullptr), degree(-1) { 
        
        NodeTerm* current = rhs.head;  
        NodeTerm* previous = nullptr;  

        while (current) {
            // Adds new node to list 
            previous = addBack(current->coefficient, previous);  
            current = current->next;
        }
    }

    Polynomial& Polynomial::operator=(const Polynomial& rhs) {

        if (this != &rhs) { 
            deletePoly(head); 

           NodeTerm* newHead = new NodeTerm(*(rhs.head));

            head = newHead;
            degree = 0; 

            NodeTerm* current = rhs.head->next;  
            NodeTerm* previous = head;

            while (current) {
                // Adds new node to list 
                previous = addBack(current->coefficient, previous);  
                current = current->next;
            }
        }
        return *this;  
    }

    Polynomial::~Polynomial() {
        deletePoly(head);  
    }

    // Methods
    void Polynomial::addFront(int data) {
        // Create new node and set it as head
        head = new NodeTerm(data, head);  
        ++degree; 
    }

    bool Polynomial::isEmpty() const {
        return (degree == 0 && head->coefficient == 0);
    }

    Polynomial::NodeTerm* Polynomial::addBack(int data, NodeTerm* current) {
        if (!current) {
            // Initialize the head if empty
            head = new NodeTerm(data);
            ++degree;
            return head;
        } else {
            // Add new node to list
            current->next = new NodeTerm(data);
            ++degree;
            return current->next;
        }
    }

    void Polynomial::deletePoly(NodeTerm* current) {
        while (current) {
            NodeTerm* previous = current;  
            current = current->next;  
            delete previous;  // Delete the current node
            --degree;  // Decrease the degree
        }
        current = nullptr;  
    }

    // Horner's Method
    int Polynomial::evaluate(int val) const {
        int result = 0;
        NodeTerm* current = head;

        while (current) {
            result = result * val + current->coefficient;
            current = current->next;
        }
        return result;  
    }

    void Polynomial::clearEndingZeroes() {
        NodeTerm* current = head;
        NodeTerm* previous = nullptr;

        // Traverse the list and remove zero coefficients
        while (current->next) {
            if (!current->next->coefficient) {
                if (!previous) previous = current;  
            } else {
                if (previous) previous = nullptr;  
            }
            current = current->next;
        }
        if (previous) {  // Remove nodes from previous to the end of the list
            deletePoly(previous->next);
            previous->next = nullptr;
        }
    }

    // Member Operators
    Polynomial& Polynomial::operator+=(const Polynomial& other) {
        Polynomial rhs (other);
        if(rhs.isEmpty()){ return *this;} 
        
        else if(this->isEmpty() && !rhs.isEmpty()){ //A is empty, B is not empty
            Polynomial newPoly = Polynomial(rhs);
            return newPoly;
        }  //Now we can assume none of them are empty
        const Polynomial* higher;
        const Polynomial* lower;

        if(this->degree > rhs.degree){ //set higher/lower by checking degrees
            higher = this;
            lower = &rhs;
        } else {
            higher = &rhs;
            lower = this;
        }
        if(!higher || !lower){ //Error catching
            cerr << "They are null." << endl;
            return *this;
        }
        NodeTerm* current = higher->head;
        int countIters = (higher->degree - lower->degree);

        for(int i = 0; i < countIters; ++i){ current = current->next; }

        NodeTerm* lowerCurr = lower->head;
        while(current){
            current->coefficient += lowerCurr->coefficient; 
            current = current->next;
            lowerCurr = lowerCurr->next; }
        
        clearEndingZeroes();           
        const Polynomial* result = higher;
        *this = *higher;
        NodeTerm* current1 = this->head;

        while(current1){ current1 = current1->next;}
        return *this;
    }

    // Non-Member Operators
    ostream& operator<<(ostream& os, const Polynomial& rhs) {
        Polynomial::NodeTerm* current = rhs.head;

        if (!current || (current->coefficient == 0 && !current->next)) {
            os << "0";  // Zero polynomial case
            return os;
        }
        int degree = rhs.degree;
        bool firstNodeTerm = true;

        while (current) {
            int coefficient = current->coefficient;

            if (coefficient != 0) {
                if (!firstNodeTerm) {
                    if (coefficient > 0) os << " + ";
                    else os << " - ";
                } else {
                    if (coefficient < 0) os << "-";
                    firstNodeTerm = false;
                }
                
                if (abs(coefficient) != 1 || degree == 0) os << abs(coefficient);

                if (degree > 0) {
                    os << "x";
                    if (degree > 1) os << "^" << degree;
                }
            }
            current = current->next;
            --degree;
        }
        return os;
    }

    bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
        
        Polynomial::NodeTerm* iter1 = lhs.head;
        Polynomial::NodeTerm* iter2 = lhs.head; //RHS, BUT IT BREAKS AT THE FIRST == alskdfjas;dlkfjasd;lfkjasd;flkasdjf;alskdfjasd;lkfjasd;lfkasdjf;ladskj

        while(iter1->coefficient == 0){
            iter1 = iter1->next;
        }
        while(iter2->coefficient == 0){
            iter2 = iter2->next;
        }
        while(iter1 && iter2){

            if(iter1->coefficient != iter2->coefficient){
                return false;
            }
            iter1 = iter1->next;
            iter2 = iter2->next;
        }

       if(iter1 || iter2){
        return false;
       }

       return true;
    }

    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
        Polynomial addedPoly = Polynomial(lhs);  
        return addedPoly += rhs; 
    }

    bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
        return !(lhs == rhs);  
    }
}
