/*
Anthony Lamelas, polynomial.h file for polynomai linked list homework
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_h

#include <iostream>
#include <string>
#include <vector>

namespace linkedPolynomial{

    class Polynomial{
        struct NodeTerm;

        friend ostream& operator <<(std::ostream& os, const Polynomial rhs);
        friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);

        public:
            Polynomial();
            Polynomial(const std::vector<int>& coefficients);
            
            Polynomial& operator+=(const Polynomial& rhs);
            
        //Copy Control
            Polynomial& operator=(const Polynomial& rhs);
            Polynomial(const Polynomial& rhs);
            ~Polynomial();

            void clearLeading();
            void deletePoly(NodeTerm* current);
            int eval(int val) const;
            void addFront(int data);
            Polynomial::NodeTerm* addBack(int data, NodeTerm* current);

        private:

            struct NodeTerm{

                NodeTerm(int coefficient = 0, NodeTerm* next = nullptr);

                    int coefficient;
                    NodeTerm* next;
            };

            NodeTerm* head;
            int degree;

            
    };

    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
    bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

}

#endif