#include "course.h"
#include "student.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace BrooklynPoly{

    ostream& operator<<(ostream& os, const Course& rhs) {
    os << rhs.name << ":";
    if (rhs.students.empty()) {
        os << " No Students";
    } else {
        for (Student* studentp : rhs.students) {
            os << " " << studentp->getName();
        }
    }
    os << endl;
    return os;
}

Course::Course(const string& n) : name(n){}
const string& Course::getName() const {return name;}

bool Course::addStudent(Student* student){
    for (Student* s : students) {
        if (s == student) {
            return false; 
        }
    }
    students.push_back(student);
    return student->addCourse(this); 
}

void Course::removeStudentsFromCourse(){
    for(Student* student : students){
        student->removedFromCourse(this);
    }
    students.clear();
}

}