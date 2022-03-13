//header for student
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{

 public:
  Student();
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  void setFirstName(char* newFirstName);
  void setLastName(char* newLastName);
  void setID(int newID);
  void setGPA(float newGPA);
  void displayStudent();
  ~Student();

 private:
  //variables
  char firstName[50];
  char lastName[50];
  int id;
  float gpa;
};

#endif
