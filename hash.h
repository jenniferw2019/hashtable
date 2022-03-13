//header file for hash
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
  int getCollision();
  int hashValue(int newID);
  void insertHashTable(Node* nStudent);
  void printHashTable();
  void deleteHashTable(int searchID);
  void reHashTable();
  ~HashTable();

 private:
  //variables
  Node** hashData;
  int size;
  int collision;
};

#endif
