/*
Anthony Lamelas, polynomial.cpp file for polynomial linked list homework
*/

#include <iostream>
#include <vector>
#include "polynomial.h"
using namespace std;

namespace linkedPolynomial{

    //Constructors
    Polynomial::Polynomial() : head(new NodeTerm()), degree(0) {}

    Polynomial::Polynomial(const std::vector<int>& coefficients)
        : head(nullptr), degree(-1) {
        for (int coefficient : coefficients) addFront(coefficient);
        clearZeroes();
    }

    Polynomial::NodeTerm::NodeTerm(int coefficient, NodeTerm* next) :
    coefficient(coefficient), next(next) {}

    //Copy Control
    Polynomial::Polynomial(const Polynomial& rhs) :
    head(nullptr), degree(0){

        NodeTerm* current = rhs.head;
        NodeTerm* previous = nullptr;

        while (current) {
            previous = addBack(current->coefficient, previous);
            current = current->next;
        }   
    }

    Polynomial& Polynomial::operator=(const Polynomial& rhs){
        if (this != &rhs){
            deletePoly(head);

            NodeTerm* current = rhs.head;
            NodeTerm* previous = nullptr;

            while(current){
                previous = addBack(current->coefficient, previous);
                current = current->next;
            }
        }
        return *this;
    }

    Polynomial::~Polynomial(){
        deletePoly(head);
    }

    //Methods
    void Polynomial::addFront(int data){
        head = new NodeTerm(data, head);
        ++degree;
    }

    Polynomial::NodeTerm* Polynomial::addBack(int data, NodeTerm*current){

        if(!current){
            head = new NodeTerm(data);
            return head;
        }
        else {
            current->next = new NodeTerm(data);
            return current->next;
        }
    }

    void Polynomial::deletePoly(NodeTerm* current){
        while (current) {

            NodeTerm* previous = current;
            current = current->next;
            delete previous;
            --degree;
        }
        current = nullptr;
    }

    int Polynomial::evaluate(int val) const{
        int result = 0;
        NodeTerm* current = head;

        while(current){
            result = result * val + current->coefficient;
            current = current->next;
        }
        return result;
    }

    void Polynomial::clearZeroes() {
        NodeTerm* current = head;
        NodeTerm* previous = nullptr;

        while(current->next){
            if(current->next->coefficient){
                if(previous){
                    previous = nullptr;
                }

            } else{
                if(!previous){
                    previous = current;
                }
            }
            current = current->next;
        }

        if(previous){
            deletePoly(previous->next);
            previous->next = nullptr;
            
        }
    }

    //Member Operators
    Polynomial& Polynomial::operator+=(const Polynomial& rhs){
        NodeTerm* current = head;
        NodeTerm* rhs_current = rhs.head;
        NodeTerm* previous = nullptr;

        while(current){
            if(!rhs_current){
                break;
            }
            current->coefficient += rhs_current->coefficient;

            if(!current->next){
                previous = current;
            }
            current = current->next;
            rhs_current = rhs_current->next;
        }

        while(rhs_current){
            previous = addBack(rhs_current->coefficient, previous);
            rhs_current = rhs_current->next;
        }

        clearZeroes();
        return *this;
    }

    //Non-Member Operators
    ostream& operator<<(ostream& os, const Polynomial& rhs) {
    Polynomial::NodeTerm* current = rhs.head;

    if (!current || (current->coefficient == 0 && !current->next)) {
        os << "0";
        return os;
    }
    int degree = rhs.degree;
    bool firstNodeTerm = true;

    while (current) {
        int coefficient = current->coefficient;

        if (coefficient != 0) {
            if (!firstNodeTerm) {
                if (coefficient > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            } else {
                if (coefficient < 0) {
                    os << "-";
                }
                firstNodeTerm = false; 
            }
            if (abs(coefficient) != 1 || degree == 0) {
                os << abs(coefficient);
            }
            if (degree > 0) {
                os << "x";
                if (degree > 1) {
                    os << "^" << degree;
                    }
                }
            }
        current = current->next;
        --degree;
        }
    return os;
    }

    //operator ==, check if degree is the same, then set currents and check coefficients
    bool operator==(const Polynomial& lhs, const Polynomial& rhs){
        if(lhs.degree != rhs.degree){
            return false;
        } else {
            Polynomial::NodeTerm* lhs_current = lhs.head;
            Polynomial::NodeTerm* rhs_current = rhs.head;

            while(lhs_current){
                if(lhs_current->coefficient != rhs_current->coefficient){
                    return false;
                }
            }
        }
        return true;
    }

    //operator +, create new polunomial from one then add the other
    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
        Polynomial addedPoly = Polynomial(lhs);

        return addedPoly += rhs;
    }

    //operator != return !(lhs==rhs)
    bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
        return !(lhs==rhs);
    }
}
