#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"
#include "hash.h"

using namespace std;

HashTable::HashTable(int newSize)
{
  size = newSize;
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

int HashTable::hashValue(int newID)
{
  int index = newID % size;
  return index;
}

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
    }
}

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
HashTable::~HashTable() {}
