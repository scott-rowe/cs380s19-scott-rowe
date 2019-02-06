/**************************************************************************
 File name:		  main.cpp
 Author:        Scott Rowe
 Date:          2/4/2019
 Class:         CS300
 Assignment:    Euclidean Division
 Purpose:       To use euclidean division to divine a word from a number
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

int main ()
{
  const int HASH_NUM = 37;
  const int WORD_LENGTH = 9;

  int64_t key = 910897038977002;
  std::string letters = "acdegilmnoprstuw";
  char word[9];
  int remainder = 0;

  for (int i = 0; i < 9; i++)
  {
    remainder = key % HASH_NUM;
    key = key / HASH_NUM;
    word[i] = letters[remainder];
  }

  for (int i = 8; i >= 0; i--)
  {
    std::cout << word[i];
  }

  std::cout << std::endl << std::endl;
  
  system ("pause");
  return EXIT_SUCCESS;
}