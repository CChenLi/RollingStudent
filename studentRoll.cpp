#include <string>
#include "studentRoll.h"
#include <iostream>
#include <sstream>
StudentRoll::StudentRoll() {
  head = tail = NULL;
}

StudentRoll::Node::~Node(){delete s;}

void StudentRoll::insertAtTail(const Student &s) {
  Student* n = new Student(s);
  if(!head){
    head = new Node;
    head->s = n;
    head->next = NULL;
    tail = head;
  } else{
    tail->next = new Node;;
    tail->next->s = n;
    tail->next->next=NULL;
    tail = tail->next;
  }
}

std::string StudentRoll::toString() const {
  //std::cout << "break 1" << std::endl;
  std::ostringstream oss;
  oss << "[" ;
  Node* n = head;
  while(n){
    //std::cout << "break 3" <<std::endl;
    oss << n->s->toString();
    if(n->next) oss <<",";
    n = n->next;
  }
  oss << "]";
  //std::cout << "break 2" << std::endl;
  return oss.str();
}


StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node* n = orig.head;
  while(n){
    this->insertAtTail(*(n->s));
    n = n->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* n = head;
  while(n){
    n = head->next;
    //delete head->s;
    delete head;
    head = n;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  StudentRoll temp(right);
  Node* thead = this->head;
  Node* ttail = this->tail;
  this->head = temp.head;
  this->tail = temp.tail;
  temp.head = thead;
  temp.tail = ttail;



  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





