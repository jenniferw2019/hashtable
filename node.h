#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

class Node
{

 public:
  Node();
  Node(Student* newStudent);
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newNode);
  ~Node();
  
 private:
  Node* next;
  Student* student;  
};

#endif
