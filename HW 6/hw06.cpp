/*
hw06
Anthony Lamelas
October 23, 2024
CS2124 24F
Class and operators for Unsigned Integer 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addDigits(vector<int>& result, const vector<int>& a, const vector<int>& b);

class BigUnsigned {

friend ostream& operator<<(ostream& os, const BigUnsigned& num);
friend BigUnsigned operator+(const BigUnsigned& lhs, const BigUnsigned& rhs);

public:
    // Constructors
    BigUnsigned(int value = 0) {
        digits.clear();
        if (value == 0) {
            digits.push_back(0);
        } else {
            int num = value;
            for (int i = 0; num > 0; ++i) {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }

    BigUnsigned(const string& str) {
        digits.clear();
        int startIdx = 0;
        // Skip leading zeros
        while (startIdx < str.size() && str[startIdx] == '0') {
            startIdx++;
        }
        // Read digits up to the first non-digit character
        for (int i = str.size() - 1; i >= startIdx; i--) {
            if (isdigit(str[i])) {
                digits.push_back(str[i] - '0');
            } else {
                break;
            }
        }
        // If empty, push back a 0
        if (digits.size() == 0) {
            digits.push_back(0);
        }
    }

    // Operators
    BigUnsigned& operator+=(const BigUnsigned& other) {
    int carry = 0;
    size_t maxLength = digits.size();
    if (other.digits.size() > maxLength) {
        maxLength = other.digits.size();
    }
    vector<int> result;

    // Loop through digits, adding corresponding digits and managing carry
    // Makes sure to add leftover remainder 
    for (size_t i = 0; i < maxLength || carry; ++i) {
        int digitSum = carry;
        if (i < digits.size()) {
            digitSum += digits[i];
        }
        if (i < other.digits.size()) {
            digitSum += other.digits[i];
        }
        carry = digitSum / 10;
        result.push_back(digitSum % 10);
    }
    digits = result;
    return *this;

    }

    bool operator<(const BigUnsigned& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size();
        }
        // Compare digits, starting from most significant
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator==(const BigUnsigned& other) const {
        return digits == other.digits;
    }

    bool operator==(int value) const {
        return *this == BigUnsigned(value);
    }

    bool operator!=(const BigUnsigned& other) const {
        return !(*this == other);
    }

    bool operator>(const BigUnsigned& other) const {
        return other < *this;
    }

    bool operator<=(const BigUnsigned& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigUnsigned& other) const {
        return !(*this < other);
    }

    // Pre-increment
    BigUnsigned& operator++() {
        *this += 1;
        return *this;
    }

    // Post-increment
    BigUnsigned operator++(int dummy) {
        BigUnsigned copy = *this;
        *this += 1;
        return copy;
    }

    // Implicit conversion to bool
    operator bool() const {
        return !(digits.size() == 1 && digits[0] == 0);
    }

private:
    vector<int> digits;
};

int main()
{
    BigUnsigned zero;
    BigUnsigned one(1);

    cout << "zero: " << zero << endl;
    cout << "one: " << one << endl;

    BigUnsigned val = 1;
    cout << "val: " << val << endl;
    cout << "++val: " << ++val << endl;
    cout << "val: " << val << endl;
    cout << "val++: " << val++ << endl;
    cout << "val: " << val << endl;
    
    cout << "(one + zero): " << (one + zero) << endl;
    cout << "(one + one): " <<  (one + one) << endl;

    cout << boolalpha;
    cout << "one < one: " << (one < one) << endl;
    cout << "zero < one: " << (zero < one) << endl;

    BigUnsigned a = 123;
    BigUnsigned b = 1234;
    BigUnsigned c = 124;
    BigUnsigned d = 12345;

    cout << "a: " << a << ", b: " << b 
         << ", c: " << c << ", d: " << d << endl;
    cout << "a + d: " << (a + d) << endl;
    cout << "d + d: " << (d + d) << endl;
    cout << "a < d: " << (a < d) << endl;
    cout << "d < a: " << (d < a) << endl;
    cout << "zero == zero: " << (zero == zero) << endl
         << "zero == one: " << (zero == one) << endl
         << "a == a: " << (a == a) << endl
         << "a == d: " << (a == d) << endl
         << "d == a: " << (d == a) << endl;

    cout << "(zero == 0): " << (zero == 0) << endl
         << "(one == 0): " << (one == 0) << endl
         << "(1 == one): " << (1 == one) << endl;

    // +=
    cout << "b: " << b << ", c: " << c << endl;
    cout << "(c += b): " << (c += b) << endl;
    cout << "b: " << b << ", c: " << c << endl;


    BigUnsigned x = a;
    cout << "x: " << x << ", a: " << a << endl
         << "x == a: " << (x == a) << endl
         << "a == x: " << (a == x) << endl
         << "a < x: " << (a < x) << endl
         << "a > x: " << (a > x) << endl;
    
    cout << "x > a: " << (x > a) << endl
         << "x >= a: " << (x >= a) << endl
         << "x <= a: " << (x <= a) << endl
         << "x != a: " << (x != a) << endl;
         
    
    BigUnsigned big("987654321");
    BigUnsigned big2("  ");
    BigUnsigned big3("felix");
    BigUnsigned big4("00987654321");

    cout << "big: " << big << endl
         << "big2: " << big2 << endl
         << "big3: " << big3 << endl
         << "big4: " << big4 << endl;

    BigUnsigned big5(98765);
    BigUnsigned big6(2457);
    cout << "big5: " << big5  << ", big6: " <<  big6 << endl
         << "(big5 + big6): " << (big5 + big6) << endl
         << "(big6 + big5): " << (big6 + big5) << endl;


    // How does this work?
    cout << zero << " is " << (zero ? "true" : "false") << endl;
    cout << one << " is " << (one ? "true" : "false") << endl;
    cout << big4 << " is " << (big4 ? "true" : "false") << endl;
} // main



// << operator
ostream& operator<<(ostream& os, const BigUnsigned& num) {
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }

// + operator
BigUnsigned operator+(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    BigUnsigned result = lhs;
    result += rhs;
    return result;
}