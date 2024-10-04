/*
  rec05-start.cpp
  
  Anthony Lamelas
  Lab 5: Classes, delegation, output operator, copy control
  Model of the the CS lab administration

  Remember that the file you are to submit should be named rec05.cpp.
  And YOUR NAME should appear up here in the comment.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section;

class StudentRecord{

  //Overload
  friend ostream& operator<<(ostream& os, const Section& section);

  public:
    StudentRecord(const string& name): name(name), grades(14, -1) {}

  //Methods
  const string getName() const {return name;}
  void setGrade(int grade, int labIndex){
    grades[labIndex - 1] = grade;
  }

  private:
    string name;
    vector<int> grades;
};

class Section{
  //Overload
friend ostream& operator<<(ostream& os, const Section& section);

  public:
    class TimeSlot{
      //Overload
      friend ostream& operator<<(ostream& os, const Section& section);

      public:
        TimeSlot(const string& day, unsigned int hour) : day(day), hour(hour) {}


      private:
      string day;
      int hour;
    };


  Section(const string& name, const string& day, int hour) : 
    name(name), timeslot(day, hour) {}

  //Copy Constructor
  Section(const Section& otherSection) : name(otherSection.name),
  timeslot(otherSection.timeslot){

    for (size_t i = 0; i < otherSection.records.size(); i++) {
            records.push_back(new StudentRecord(*otherSection.records[i]));
        }
  }

  //Methods
  // vector<StudentRecord*> getRecord() {return records;}
  void addStudent(const string& name) {
    records.push_back(new StudentRecord(name));
  }
  void reset(){
    for (StudentRecord*& rec : records){
      delete rec;
      rec = nullptr;
    }
  }
  
  bool addGrade(const string& studentName, int grade, int section_num){
    for (StudentRecord* record : records){
      if (record->getName() == studentName){
        record->setGrade(grade, section_num);
        return true;
      }
    }
    return false;
  }

  //Destructor
  ~Section() {
    cout << "section " << name << " is being deleted" << endl;
    for(StudentRecord* record : records){
      cout << "Deleting " << record->getName() << endl;
      delete record;
    }
  }

  private:
    string name;
    TimeSlot timeslot;
    vector<StudentRecord*> records;
};

class LabWorker{
  
  //Overload
  friend ostream& operator<<(ostream& os, const LabWorker& lab_worker);

  public:
  LabWorker(const string& name) : name(name), section(nullptr) {}
  

  //Methods

  void addSection(Section& sec) {
    section = &sec;
}

  bool addGrade(const string& studentName, int grade, int section_num){
    return section->addGrade(studentName, grade, section_num);
  }
  
  private:
    string name;
    Section* section;
};


//Overload operators
ostream& operator<<(ostream& os, const Section& section){
  os << "Section: " << section.name << ", Time slot: [Day: " << section.timeslot.day 
  << ", Start time: ";
  if (section.timeslot.hour > 12){
    os << section.timeslot.hour - 12 << "pm], Students:" << endl;
  } else{
    os << section.timeslot.hour << "am], Students:" << endl;
  }
  
  for(const StudentRecord* record : section.records){
    os << "Name: " << record->getName() << ", Grades: ";
    for(const int grade : record->grades){
      os << grade << " ";
    }
    os << endl;
  }
  return os;
}

ostream& operator<<(ostream& os, const LabWorker& lab_worker){
  if (!lab_worker.section){
    os << lab_worker.name << " does not have a section";
    return os;
  } else{
    os << lab_worker.name << " has Section: " << *lab_worker.section;
    return os;
  }
  
}

// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main()
{

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);  
    moe.addGrade("Paul", 19, 1);  
    moe.addGrade("George", 16, 1);  
    moe.addGrade("Ringo", 7, 1);  
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);  
    moe.addGrade("Paul", 20, 3);  
    moe.addGrade("Ringo", 0, 3);  
    moe.addGrade("George", 16, 3);  
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Copy Constructor: make sure the following calls work:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n" << secA2 << endl;

} // main
