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
        struct Term;

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

        int eval(int val) const;

        private:

            struct NodeTerm{

                Term(int coefficient = 0, Term* next = nullptr);

                    int coefficient;
                    Term* next;
            };

            Term* head;
            int degree;

            
    };

    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
    bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

}

#endif