/**************************************************************************
 File name:		  main.cpp
 Author:        Scott Rowe
 Date:          2/4/2019
 Class:         CS300
 Assignment:    Count Characters
 Purpose:       To count the number of times characters are repeated in a
				        text file and output those characters to the screen
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
  const int MAX_CHARS = 3000;
  const int NUM_CHARS = 27;

  char aCharacters[MAX_CHARS];
  int numIterations[NUM_CHARS][NUM_CHARS];
  char aWord[NUM_CHARS];
  int highestIterations = 0;
  int counter = 0;
  int asciiValue = 97;
  std::ifstream inFile ("01Counting.txt");

  if (!inFile)
  {
    std::cout << "Error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  while (inFile >> aCharacters[counter])
  {
    counter++;
  }

  inFile.close ();

  if (aCharacters[0] < 97)
  {
    asciiValue = 65;
  }

  for (int i = 0; i < NUM_CHARS; i++)
  {
    numIterations[i][0] = 0;
    numIterations[i][1] = i + asciiValue;
  }

  for (int i = 0; i < counter; i++)
  {
    numIterations[aCharacters[i] - asciiValue][0]++;
    if (aCharacters[i] == '_')
    {
      numIterations[NUM_CHARS - 1][0]++;
    }
  }

  for (int i = 0; i < NUM_CHARS; i++)
  {
    for (int k = 0; k < NUM_CHARS; k++)
    {
      if (numIterations[k][0] > highestIterations)
      {
        highestIterations = numIterations[k][0];
        aWord[i] = static_cast<char> (numIterations[k][1]);
      }
    }
    numIterations[static_cast<int>(aWord[i]) - asciiValue][0] = 0;
    highestIterations = 0;
  }

  counter = 0;
  while (aWord[counter] != '{' && aWord[counter] != '[')
  {
    std::cout << aWord[counter];
    counter++;
  }

  std::cout << std::endl << std::endl;

  system ("pause");
  return EXIT_SUCCESS;
}