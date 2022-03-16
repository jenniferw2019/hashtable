//cpp file for hash
#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"
#include "hash.h"

using namespace std;

HashTable::HashTable(int newSize)
{
  size = newSize;
  collision = 0;
  hashData = new Node*[newSize];
  for (int i = 0; i < newSize; i++)
    {
      hashData[i] = NULL;
    }
}

int HashTable::getSize()
{
  return size;
}
void HashTable::setSize(int addSize)
{
  size = addSize;
}
int HashTable::getCollision()
{
  return collision;
}

int HashTable::hashValue(int newID)
{
  int index = newID % size;
  return index;
}

//insert student into hash table
void HashTable::insertHashTable(Node* nStudent)
{
  int tempID = (nStudent->getStudent())->getID();
  int tempValue = hashValue(tempID);
  if (hashData[tempValue] == NULL)
    {
      hashData[tempValue] = nStudent;
    }
  else
    {
      Node* temp = hashData[tempValue];
      hashData[tempValue] = nStudent;
      hashData[tempValue]->setNext(temp);
      collision = collision + 1;
    }
}

//print hash table
void HashTable::printHashTable()
{
  for (int i = 0; i < size; i++)
    {
      if (hashData[i] != NULL)
	{
	  (hashData[i]->getStudent())->displayStudent();

	  Node* current = hashData[i]->getNext();

	  while (current != NULL)
	    {
	      (current->getStudent())->displayStudent();
	      current = current->getNext();
	    }
	  cout << endl;
	}
    }
}

//delete student from hash table
void HashTable::deleteHashTable(int searchID)
{
  int tempv = hashValue(searchID);

  if (hashData[tempv] != NULL)
    {
      Node* current = hashData[tempv];
      Node* previous;
      
      if ((hashData[tempv]->getStudent())->getID() == searchID)
	{
	  Node* temp = hashData[tempv];
	  hashData[tempv] = hashData[tempv]->getNext();
	  delete temp;
	}
      else
	{
	  while (current->getNext() != NULL)
	    {
	      previous = current;
	      current = current->getNext();

	      if ((current->getStudent()->getID()) == searchID)
		{
		  Node* temp = current->getNext();
		  previous->setNext(temp);
		  delete current;
		  break;
		}
	    }
	}
    }
}

//rehash table
void HashTable::reHashTable()
{
  Node** oldHash = hashData;
  int oldsize = size;
  
  size = oldsize * 2;
  collision = 0;
  hashData = new Node*[size];
  for (int i = 0; i < size; i++)
    {
      hashData[i] = NULL;
    }
  for (int i = 0; i < oldsize; i++)
    {
      
      if (oldHash[i] != NULL)
	{
	  Node* tempHead = oldHash[i];
	  oldHash[i] = oldHash[i]->getNext();
	  tempHead->setNext(NULL);
	  insertHashTable(tempHead);
	  
	  
	  while (oldHash[i] != NULL)
	    {
	      Node* tempHead = oldHash[i];
	      oldHash[i] = oldHash[i]->getNext();
	      tempHead->setNext(NULL);
	      insertHashTable(tempHead);
	      
	    }
	}
    }
}

int HashTable::searchID(int findID)
{
  int temp = hashValue(findID);
  if (hashData[temp] != NULL)
    {
      Node* current = hashData[temp];
      Node* previous;

      if ((hashData[temp]->getStudent())->getID() == findID)
	{
	  return 1;
	}
      else
	{
	  while (current->getNext() != NULL)
	    {
	      previous = current;
	      current = current->getNext();

	      if ((current->getStudent())->getID() == findID)
		{
		  return 1;
		}
	    }
	}
    }
  return 0;
}

HashTable::~HashTable() {}
