#include <iostream>
#include <string>
using namespace std;

class Date {
    Date(int m, int d, int y) :month(m), day(d)< year(y) { }
    Date():month(1), day(1), year(1900){}
private:
    int month;
    int day;;
    int year;
};


class Person {
public:
    Person(const string& n, int m, int d, int y): name(n), dob(m, d, y) { }
    friend ostream& operator<<(ostream& os, const Person& rhs);


private:
    string name;
    Date dob;

friend ostream& operator<<(ostream& os, const Date& rhs){
    os << rhs.name << ": " << rhs.dob;
    return os;
};

friend ostream& operator<<(ostream& os, const Person& rhs){
    os << rhs.month<<"/"<<rhs.day<<"/"<<rhs.year;
    return os;
};
    
};

int main() {
    
}
