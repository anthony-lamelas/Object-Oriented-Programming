//Anthony Lamelas student cpp


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
        for (const Course* coursep : rhs.courses) {
            os << " " << coursep->getName();
        }
    }
    os << endl;
    return os;
}

Student::Student(const string& n) : name(n){}

const string& Student::getName() const {return name;}

bool Student::addCourse(Course* course){
    for (const Course* c : courses) {
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
            for(size_t j = i; j < courses.size() - 1; ++j){
                courses[j] = courses[j+1];
            }
            
            courses.pop_back();
            break;
        }
    }
}
}

