
#include <cstring>
#include <iostream>
//#include "tddFuncs.h"
using namespace std;

#include <string>

class Student {

 public:
  Student(const char * const name, int perm);

  int getPerm() const;
  const char * const getName() const;

  void setPerm(const int perm);
  void setName(const char * const name);

  Student(const Student &orig);
  ~Student();
  Student & operator=(const Student &right);

  std::string toString() const;

 private:
  int perm;
  char *name; // allocated on heap
};

Student::Student(const char * const name, int perm) {
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return this->perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  this->perm=permNumber;
}

void Student::setName(const char * const name) {
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
}


Student::Student(const Student &orig) {
  this->setName(orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  delete name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  delete this->name;
  this->setName(right.getName());
  this->perm=right.getPerm();


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  return "tostring stub";
}

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  Student s("Phill Conrad",1234567);

  //cout << ("Phill Conrad" == s.getName());
  cout<<(s.getPerm()) << endl;
  cout<<("[Phill Conrad,1234567]"==s.toString())<< endl;

  return 0;
}
