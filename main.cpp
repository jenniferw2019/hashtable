#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

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
      cout << bufferFirst << endl;
      
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
      cout << bufferLast << endl;

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

  cout << "first " << spaceCountFirst << endl;
  cout << "last " << spaceCountLast << endl;

  //split string into tokens
  char* tokenFirst[spaceCountFirst];
  int i = 1;
  tokenFirst[0] = strtok (bufferFirst, " ");
  
  while (tokenFirst[i] != NULL)
    {
      tokenFirst[i] = strtok(NULL, " ");
      i = i + 1;
    }
 
  char* tokenLast[spaceCountLast];
  int j = 1;
  tokenLast[0] = strtok (bufferLast, " ");

  for (int i = 0; i < spaceCountFirst; i++)
    {
      cout << tokenFirst[i] << endl;
    }

  while (tokenLast[j] != NULL)
    {
      tokenLast[j] = strtok(NULL, " ");
      j = j + 1;
    }
  
  for (int j = 0; j < spaceCountLast; j++)
    {
      cout << tokenLast[j] << endl;
    }
  


  return 0;
}
