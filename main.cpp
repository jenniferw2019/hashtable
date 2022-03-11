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
  
  ifstream lastname("lastname.txt", ifstream::in);
  if (lastname)
    {
      lastname.seekg(0, lastname.end);
      lengthLast = lastname.tellg();
      lastname.seekg(0, lastname.beg);

      bufferLast = new char[lengthLast];
      //cout << lengthLast << endl;
      lastname.read(bufferLast, lengthLast);

      bufferLast[lengthLast - 1] = '\0';
      //cout << bufferLast << endl;

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

  //cout << "first " << spaceCountFirst << endl;
  //cout << "last " << spaceCountLast << endl;

  //split string into tokens
  char* tokenFirst[spaceCountFirst];
  int i = 0;
  tokenFirst[0] = strtok (bufferFirst, " ");
  
  while (tokenFirst[i] != NULL)
    {
      i = i+1;
      tokenFirst[i] = strtok(NULL, " ");
   
    }
  /*
  for (int i = 0; i < spaceCountFirst; i++)
    {
      cout << tokenFirst[i] << endl;
    }
  */
  
  char* tokenLast[spaceCountLast];
  int j = 0;
  tokenLast[0] = strtok (bufferLast, " ");
  
  while (tokenLast[j] != NULL)
    {
      j = j + 1;
      tokenLast[j] = strtok(NULL, " ");
    
    }
  /*
  for (int j = 0; j < spaceCountLast; j++)
    {
      cout << tokenLast[j] << endl;
    }
  */

  bool runProgram = true;
  int hashSize = 4;
  HashTable* myHashTable = new HashTable(hashSize);
  char strInput[10];
  int students = 0;
  int tempID = 0;
  int deleteID = 0;
  srand(time(NULL));
  
  while (runProgram == true)
    {
      cout << "Type ADD, PRINT, DELETE, RESIZE" << endl;
      cin.get(strInput, 10);
      cin.get();

      if (strcmp(strInput, "ADD") == 0)
	{
	  cout << "How many students? Enter an int value" << endl;
	  cin >> students;
	  cin.get();
	  
	  for (int i = 0; i < students; i++)
	    {
	      Student* newStudent = new Student();
	      int totalStudents = 5;
	      int generateFirst = 0;
	      int generateLast = 0;
	      float generateGPA = 0;

	      //srand(time(NULL));
	      generateFirst = rand() % totalStudents;
	      generateLast = rand() % totalStudents;
	      generateGPA = ((float)rand()) / (float(RAND_MAX/4));
	      //cout << generateFirst << endl;
	      //cout << generateLast << endl;
	      tempID = tempID + 1;
	      
	      newStudent->setFirstName(tokenFirst[generateFirst]);
	      newStudent->setLastName(tokenLast[generateLast]);
	      newStudent->setID(tempID);
	      newStudent->setGPA(generateGPA);
	      //newStudent->displayStudent();

	      Node* studentNode = new Node(newStudent);
	      myHashTable->insertHashTable(studentNode);
	      //myHashTable->reHashTable();
	    }
	}
      else if (strcmp(strInput, "PRINT") == 0)
	{
	  myHashTable->printHashTable();
	}
      else if (strcmp(strInput, "DELETE") == 0)
	{
	  cout << "Type id of student you want to delete" << endl;
	  cin >> deleteID;
	  cin.get();

	  myHashTable->deleteHashTable(deleteID);
	}
      else if (strcmp(strInput, "RESIZE") == 0)
	{
	  myHashTable->reHashTable();
	}
  
      }
  return 0;
}
