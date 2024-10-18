#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Complex {
public:
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend bool operator==(const Complex& lhs, const Complex& rhs);

    // constructor (3 in 1)
    Complex(double re = 0, double im = 0):real(re), imag(im) {}

    // operator+=
    Complex& operator+=(const Complex& rhs) {
        real += rhs.real;
        //this->real += rhs.real; // same thing as above
        imag += rhs.imag;
        return *this;
    }

    // pre-increment operator++()
    Complex& operator++() {
        ++real;
        return *this;
    }

    // post-increment operator++
    Complex operator++(int dummy) {
        Complex temp(*this); // YES, we invoked the IMPLICIT copy constructor
        real++;
        return temp;
    }
    // bool

    explicit operator bool(){
        return real || imag;
    }// Explicit is needed because (c1 == 1) can convert rhs to int OR lhs to bool to int
    // compiler gets confused.. it needs one operation --> block lhs to int using explicit

private:
    double real;
    double imag;
};

ostream& operator<<(ostream& os, const Complex& rhs) {
    os << rhs.real << (rhs.imag >= 0 ? "+" : "") << rhs.imag << "i";
    return os;
}
bool operator==(const Complex& lhs, const Complex& rhs) {
    return (lhs.real==rhs.real && lhs.imag==rhs.imag);
}
bool operator!=(const Complex& lhs, const Complex& rhs) {
    return !(lhs == rhs);
}
Complex operator+(const Complex& lhs, const Complex& rhs){
//    return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
    Complex temp(lhs);  // YES, we invoked the IMPLICIT copy constructor
    temp += rhs;
    return temp;
}

int main() {
	
	// Instantiate 3 complex numbers using 3 constructor types + print
    Complex c1;
    Complex c2(1);
    Complex c3(2, -2);
    cout << "c1, c2 and c3 are: " << c1 << " " << c2 << " " << c3 << endl;

    
    // print/test equality and inequality of two complex numbers
    cout << "c1 and c2 are " << (c1 == c2 ? "equal" : "not equal") << endl;
    cout << "c1 and c1 are " << (c1 == c1 ? "equal" : "not equal") << endl;
    cout << "c1 and c2 are " << (c1 != c2 ? "not equal" : "equal") << endl;


	// print/test if one of the complex numbers is equal to 1
    cout << "c1 and 1 are " << (c1 == 1 ? "equal" : "not equal") << endl;
    cout << "c2 and 1 are " << (c2 == 1 ? "equal" : "not equal") << endl;

    	
	// Repeat, but put the "1" on left hand side
    cout << "1 and c2 are " << (1 == c2 ? "equal" : "not equal") << endl; // this is the advantage of creating
    // the equality operator as a free function!!


    // Invoke/print "combination operator" op+=
    Complex c4(3, -3);
    (c4 += c3)+=2;
    cout << "(c4+=c3)+=2 is: " << c4 << endl;   


    // Add/print two of the complex numbers, store in third
    Complex c5;
    c5 = c3 + c4;
    cout << "c5=c3+c4 is: " << c5 << endl;

	// post and pre increment on integers - OUTPUT ON LEFT SIDE
    int i = 0;
    (++i) = 4;
    cout << "(++i)=4 is: " << i << endl;
    //(i++) = 4; // post increment returns a value --> cannot be assigned


    // pre-increment operator and function call) + print
    cout << ++c5 << endl;
    cout << c5.operator++() << endl;

    // post increment operator and function call + print
    cout << c5++ << endl;
    cout << c5.operator++(77) << endl; // any dummy int value would do!


	// conditional operator (requires casting) + print in two paths
    cout << (c1 ? "c1 is not zero" : "c1 is zero") << endl;
    cout << (c5 ? "c5 is not zero" : "c5 is zero") << endl;



    // We are "converting" ifs to a bool. How?
    // The member function operator bool.
    //while (ifs >> s) {}


}