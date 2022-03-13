/*
This program program allows the user to choose how many students to generate. 
New students are generated with a random first and last name, id, and random gpa. 
The hash table starts with 100 slots.
The hash function spreads out the data evenly through the table. Hash function is: (student id) % size. 
If there are more than 3 collisions, 
the table double the number of slots and rehash students into the new table.
User can add, print, and delete students. There is also a quit command. 
Author: Jennifer Wang
3/11/22
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "student.h"
#include "node.h"
#include "hash.h"

using namespace std;

int main()
{
  //variables
  char* bufferFirst;
  char* bufferLast;
  int lengthFirst;
  int lengthLast;

  
  //read first name text file to buffer
  ifstream firstname ("firstname.txt", ifstream::in);
  if (firstname)
    {
      firstname.seekg(0, firstname.end);
      lengthFirst = firstname.tellg();
      firstname.seekg(0, firstname.beg);

      bufferFirst = new char[lengthFirst];
      //cout << lengthFirst << endl;
      firstname.read(bufferFirst, lengthFirst);

      bufferFirst[lengthFirst - 1] = '\0';
      //cout << bufferFirst << endl;
      
      firstname.close();
      
    }
  else
    {
      cerr << "no such file named firstname.txt" << endl;
    }
  
  //count the number of token in bufferFirst
  int spaceCountFirst = 1;
  for (int i = 0; i < lengthFirst; i++)
    {
      if (bufferFirst[i] == ' ')
	{
	  spaceCountFirst++;
	}
    }

  
  //split first name string into tokens
  char* tokenFirst[spaceCountFirst];
  int i = 0;
  char* temptok;
  temptok = strtok (bufferFirst, " ");
  
  while (temptok != NULL)
    {
      tokenFirst[i] = temptok;
      temptok = strtok(NULL, " ");
      i = i + 1;
    
    }

  /*
  for (int i = 0; i < spaceCountFirst; i++)
    {
      cout << tokenFirst[i] << " ";
    }
  cout << endl;
  */
  
  //read last name text file to buffer
  ifstream lastname("lastname.txt", ifstream::in);
  if (lastname)
    {
      lastname.seekg(0, lastname.end);
      lengthLast = lastname.tellg();
      lastname.seekg(0, lastname.beg);

      bufferLast = new char[lengthLast];
      lastname.read(bufferLast, lengthLast);

      bufferLast[lengthLast - 1] = '\0';

      lastname.close();
      
    }
  else
    {
      cerr << "no such file named lastname.txt" << endl;
    }
    
  //count the number of token in bufferLast
  int spaceCountLast = 1;
  for (int i = 0; i < lengthLast; i ++)
    {
      if (bufferLast[i] == ' ')
	{
	  spaceCountLast++;
	}
    }
 
  //split last name string into tokens
  char* tokenLast[spaceCountLast];
  int j = 0;
  char* temptok2;
  temptok2 = strtok (bufferLast, " ");
  
  while (temptok2 != NULL)
    {
      tokenLast[j] = temptok2;
      temptok2 = strtok(NULL, " ");
      j = j + 1;
    
    }
  /*
  for (int i = 0; i < spaceCountLast; i++)
    {
      cout << tokenLast[i] << " ";
    }
  cout << endl;
  
  cout << tokenFirst[0]  << endl;
  */
  
  //variables
  bool runProgram = true;
  int hashSize = 100;
  HashTable* myHashTable = new HashTable(hashSize);
  char strInput[10];
  int students = 0;
  int tempID = 0;
  int deleteID = 0;
  srand(time(NULL));

  /*
  //cout << tokenFirst[0] << endl;
  Student* tempStu = new Student();
  //tempStu->setFirstName(tokenFirst[0]);
  tempStu->setLastName(tokenLast[1]);
  tempStu->setID(1);
  tempStu->setGPA(4.00);
  //tempStu->displayStudent();
  */
  
  while (runProgram == true)
    {
      cout << "Type ADD, PRINT, DELETE, QUIT" << endl;
      cin.get(strInput, 10);
      cin.get();

      //if user type ADD, prompt user to enter how many students. create students and add to hash table
      if (strcmp(strInput, "ADD") == 0)
	{
	  cout << "How many students? Enter an int value" << endl;
	  cin >> students;
	  cin.get();
	  
	  for (int i = 0; i < students; i++)
	    {
	      //cout << "LINE 143" << endl;
	      Student* newStudent = new Student();
	      int generateFirst = 0;
	      int generateLast = 0;
	      float generateGPA = 0;

	      //generate students
	      generateFirst = rand() % 12;
	      generateLast = rand() % 12;
	      generateGPA = ((float)rand()) / (float(RAND_MAX/4));
	      tempID = tempID + 1;
	      //cout << generateFirst << " " << generateLast << endl;
	      
	      newStudent->setFirstName(tokenFirst[generateFirst]);
	      newStudent->setLastName(tokenLast[generateLast]);
	      newStudent->setID(tempID);
	      newStudent->setGPA(generateGPA);

	      //newStudent->displayStudent();
	      //cout << endl;
	      //insert to hash table
	      Node* studentNode = new Node(newStudent);
	      myHashTable->insertHashTable(studentNode);
	     
	      
	    }

	  
	  //while collision is greater than 3, rehash table
	  while (myHashTable->getCollision() > 3)
	    {
	      myHashTable->reHashTable();
	      cout << "hash table size has been doubled" << endl;
	    }
	  
	  
	}
      //if user types PRINT, prints hash table
      else if (strcmp(strInput, "PRINT") == 0)
	{
	  myHashTable->printHashTable();
	}

      //if user types DELETE, prompt user to enter the student ID number
      //and then delete that student
      else if (strcmp(strInput, "DELETE") == 0)
	{
	  cout << "Type id of student you want to delete" << endl;
	  cin >> deleteID;
	  cin.get();

	  myHashTable->deleteHashTable(deleteID);
	}

      //if user types QUIT, program stops
      else if (strcmp(strInput, "QUIT") == 0)
	{
	  runProgram = false;
	}
  
      }

  return 0;
}
