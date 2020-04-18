#include "student.h"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

Student::Student(const char * const name, int perm) {
  this->name = NULL;
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
  if(this->name) {delete[] this->name;}
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
}


Student::Student(const Student &orig) {
  this->name = 0;
  this->setName(orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  /*int len = strlen(this->name);
  for(int i = 0; i < len; i++){
    delete name+i;
  }*/
  if(this->name) {delete[] this->name;}
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  //delete[] this->name;
  this->setName(right.getName());
  this->perm=right.getPerm();


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss;
  
  oss << "[" 
      << this->getName() << ","
      << this->getPerm() << "]";
  return oss.str();
}

