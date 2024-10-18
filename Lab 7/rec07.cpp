/*
  rec07_begin.cpp
  CS2124
  Implement the class Rational, so that the following program works.
 */

#include <iostream>
using namespace std;

int greatestCommonDivisor(int x, int y);

// Put your Rational class here.
class Rational{
    friend ostream& operator<<(ostream& os, const Rational& rhs);
    friend istream& operator>>(istream& in, Rational& rhs);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);

    public:
        Rational(int n = 0, int d = 1) : numerator(n), denominator(d) {}

        void simplify() {
            int gcd = greatestCommonDivisor(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;

            if (denominator < 0){
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        Rational& operator+=(const Rational& rhs){
            numerator = rhs.denominator * numerator + rhs.numerator * denominator;
            denominator *= rhs.denominator;
            simplify();
            return *this;
}
        //Pre 
        Rational& operator++(){
            numerator += denominator;
            simplify();
            return *this;
        }

        //Post 
        Rational operator++(int dummy){
            Rational original(*this);
            numerator += denominator;
            simplify();
            return original;
        }
    
        explicit operator bool(){
            return numerator != 0;
        }
    
    private:
        int numerator;
        int denominator;

};

// Any functions that are not members and not friends should have
// prototypes here and their definitions after main.
// Function prototypes
Rational operator+(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
Rational operator--(Rational& lhs, int dummy);
Rational& operator--(Rational& rhs);

int main()
{
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
    
    // Implement + as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing? Why shouldn't it compile?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    } 

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    } 

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : " 
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;
}

int greatestCommonDivisor(int x, int y)
{
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

// Any functions that are not members and not friends should have
// their definitions here...

ostream& operator<<(ostream& os, const Rational& rhs){
    os << rhs.numerator << "/" << rhs.denominator << endl;
    return os;
}

istream& operator>>(istream& in, Rational& rhs){
    char slash;
    in >> rhs.numerator >> slash >> rhs.denominator;
    rhs.simplify();

    return in; 
}

Rational operator+(const Rational& lhs, const Rational& rhs){
    Rational result(lhs);
    result += rhs;
    return result;
}

bool operator==(const Rational& lhs, const Rational& rhs){
    return (rhs.numerator == lhs.numerator && rhs.denominator == lhs.denominator);
}

bool operator<(const Rational& lhs, const Rational& rhs){
    return (lhs.numerator * rhs.denominator) < (rhs.numerator * lhs.denominator);
}

Rational& operator--(Rational& rhs){
    rhs += -1;
    return rhs;
}

Rational operator--(Rational& lhs, int dummy){
    Rational original(lhs);
    lhs += -1;
    return original;    
}

bool operator!=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}

bool operator<=(const Rational& lhs, const Rational& rhs){
    return !(rhs < lhs);
    
}

bool operator>(const Rational& lhs, const Rational& rhs){
    return (rhs < lhs);
    
}

bool operator>=(const Rational& lhs, const Rational& rhs){
    return !(lhs < rhs);
}


