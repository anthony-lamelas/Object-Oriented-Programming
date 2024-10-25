//Anthony Lamelas registrar.cpp file

#include "course.h"
#include "student.h"
#include "registrar.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace BrooklynPoly{

    ostream& operator<<(ostream& os, const Registrar& rhs) {
    os << "Registar's Report" << endl;
    os << "Courses:" << endl;
    for (const Course* coursep : rhs.courses) {
        os << *coursep;
    }
    os << "Students:" << endl;
    for (const Student* studentp : rhs.students) {
        os << *studentp;
    }
    return os;
    }

    Registrar::Registrar() {}

    bool Registrar::addCourse(const string& courseName){
        if(findCourse(courseName) == courses.size()){
            courses.push_back(new Course(courseName));
            return true;
        }
        return false;
    }

    bool Registrar::addStudent(const string& studentName){
        if(findStudent(studentName) == students.size()){
            students.push_back(new Student(studentName));
            return true;
        }
        return false;
    }

    size_t Registrar::findStudent(const string& studentName) const{
        for(size_t i = 0; i < students.size(); i++){
            if(students[i]->getName() == studentName){
                return i;
            }
        }
        return students.size();
    }

    size_t Registrar::findCourse(const string& courseName) const{
        for(size_t i = 0; i < courses.size(); i++){
            if(courses[i]->getName() == courseName){
                return i;
            }
        }
        return courses.size();
    }

    bool Registrar:: enrollStudentInCourse(const string& studentName, 
    const string& courseName){

        size_t studentInd = findStudent(studentName);
        size_t courseInd = findCourse(courseName);

        if(studentInd != students.size() && courseInd != courses.size()){
            return courses[courseInd]->addStudent(students[studentInd]);
        }
        return false;
    }

    bool Registrar::cancelCourse(const string& courseName){
        size_t courseInd = findCourse(courseName);

        if(courseInd != courses.size()){
            courses[courseInd]->removeStudentsFromCourse();
            delete courses[courseInd];

            for(size_t i = courseInd; i < courses.size() - 1; ++i){
                courses[courseInd] = courses[courseInd + 1];
            }
            courses.pop_back();
            return true;
            }
            return false;
        }

    void Registrar::purge(){
        for (Student* student : students){
            delete student;
        }
        students.clear();

        for (Course* course : courses){
            delete course;
        }
        courses.clear();
    }
}
