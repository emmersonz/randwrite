/*
  EMMERSON ZHAIME
  DATA STRUCTURES (CPSCI 111)
  PROJECT 5: RANDWRITE
  11/07/2014

  The program takes an input text file, a seed length k, a string 
  length and an output file. It then checks whether it can read the
  input and output file and prints an error message if it cannot read
  any of these files. It also checks whether k and length are non-negative 
  and that k is less that length. If one of these conditions is not met,
  it prints out anerror message. The program then write a random textfile
  to the output file based on the probability of finding a particular 
  character in front of a given seed. It does this by first creating a 
  random string seed string of length k and then choosing a character at 
  random that can be in front of the string based on probabilities. It then 
  writes the first character in the string seed to the output file and updates
  the seed by adding the chosen character in front of it and deleting the first 
  character in the current seed. It does this continuosly until it write 
  length characters on the output file.
 */

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "list.h"
#include <ctime>

using namespace std;

char pick_char(list string)
{
  // Picks a random character in a list of characters
  return string.get(rand() % string.size());
}

string make_seed(const list & textfile , size_t k)
{
  // Makes the initial seed to start the random writing and returns it
  size_t starting_index = rand() % textfile.size() - k + 1;
  string seed = "";
  for(size_t i = 0; i < k; i++)
    seed += textfile.get(starting_index + i);
  return seed;
}

list poss_next_char(const list & text, string seed, size_t k)
{
  /*
    Searches for the characters that are next to a given seed, put them
    into a list and then returns the list. It searches by going on all
    the positions in the list of all charactersand makes a string with
    length k and compares it to the seed. If the constructed string is 
    the same as the seed, the next characterin the list is added to a
    new list of possible next characters.
  */

  list nextChars;
  for(size_t i = 0; i < text.size()- k; i++){
    string constructed_string = "";
    for(size_t j = 0; j < k; j++)
      constructed_string += text.get(i + j);
    if(constructed_string == seed)
      nextChars.add(text.get(i + k), 0);
  }
  return nextChars;
}

string update_seed(const string & current_seed, char chosen_char,ofstream & result)
{
  /* 
     Takes in a seed, a chosen character and the output file, and makes a new seed
     with all the characters in the initial string except the first, then adds the
     chosen character to the end of the new seed and returns it.It also writes the
     first character in the input seed to the output file.
  */

  char c = current_seed[0];
  result << c;
  result.flush();
  string new_seed= "";
  for (size_t i = 1; i < current_seed.length(); i++)
    new_seed += current_seed[i];
  new_seed += chosen_char;
  return new_seed;  
}

void usage(int k, int length, ifstream &  source, ofstream & result)
{
  // Prints out an error message if either k or length is negative 
  if ( k < 0 or length < 0){
    cout << "k and length should be non-negative" << endl;
    exit(1);
  }
  // Print out an error message if the length is less than k
  if(length < k){
    cout << "the length should be greater than k" << endl;
    exit(1);
  }
}

int main(int argc, char *argv [])
{
  srand(time(NULL));
  int k = atoi(argv[1]);
  int length = atoi(argv[2]);
  string text  = argv[3];
  string output = argv[4];

  ifstream source(text.c_str());
  ofstream result(output.c_str());
  
  if (not source){
    cout << "can't open the input file for reading" << endl;
    exit(1);
  }
  if (not result){
    cout << "can't open the output file for writing" << endl;
    exit(1); 
  }
  // Checks whether all the conditions for the input arguments are met
  usage( k, length, source, result);
 
  // Creates a list and and all characters from the textfile to the list  
  list allChars;
  char c; 
  while(( c = source.get()) != -1)
    allChars.add(c, allChars.size());
  string seed = make_seed (allChars, k); // Makes initial seed
  char chosen_char = pick_char(poss_next_char(allChars, seed, k));
  string new_seed = update_seed(seed, chosen_char,result); 
  for( int i = 0; i < length -1; i++){
    list possible_chars = poss_next_char(allChars, new_seed, k);
    if (possible_chars.size() > 0){
      chosen_char = pick_char(possible_chars); 
      new_seed = update_seed(new_seed, chosen_char,result); 
    }
    else{
      new_seed = make_seed(allChars, k);
      i--; // No character written to output file so no incrementation of i
    } 
  }
}
