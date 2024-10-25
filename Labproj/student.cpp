#include "course.h"
#include "student.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace BrooklynPoly{

    ostream& operator<<(ostream& os, const Student& rhs) {
    os << rhs.name << ":";
    if (rhs.courses.empty()) {
        os << " No Courses";
    } else {
        for (Course* coursep : rhs.courses) {
            os << " " << coursep->getName();
        }
    }
    os << endl;
    return os;
}

Student::Student(const string& n) : name(n){}

const string& Student::getName() const {return name;}

bool Student::addCourse(Course* course){
    for (Course* c : courses) {
        if (c == course) {
            return false; 
        }
    }
    courses.push_back(course);
    return true;
}

void Student::removedFromCourse(Course* course){
    for (size_t i = 0; i < courses.size(); ++i){
        if (courses[i] == course){
            courses[i] = courses[courses.size() - 1];
            courses.pop_back();
            break;
        }
    }
}

}

