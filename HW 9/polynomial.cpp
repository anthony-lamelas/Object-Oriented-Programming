/*
Anthony Lamelas, polynomial.cpp file for polynomai linked list homework
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
        clearLeading();
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

    int Polynomial::eval(int val) const{
        int result = 0;
        NodeTerm* current = head;

        while(current){
            result = result * val + current->coefficient;
            current = current->next;
        }
        return result;
    }


}