#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

class HashTable
{

 public:
  HashTable(int newSize);
  int getSize();
  void setSize(int addSize);
  int hashValue(int newID);
  void insertHashTable(Node* nStudent);
  void printHashTable();
  ~HashTable();

 private:
  Node** hashData;
  int size;
};

#endif
