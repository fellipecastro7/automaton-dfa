#include "Automaton.h"
#include "Automaton.cpp"

using std::cout;
using std::cin;

int main() {
  string word;
  vector <string> tokens;
  string types[] = {"int", "char", "bool", "float", "double"};
  int check;

  cout << "Enter the variable type and name:\n";
  getline(cin, word);

  tokens = split(word, ' ');

  if((tokens[0] == types[0]) || (tokens[0] == types[1]) || (tokens[0] == types[2]) || (tokens[0] == types[3]) || (tokens[0] == types[4])) {
    check = automaton(word);
      
    if(check == 1) {
      cout << "The variable type is: " << tokens[0] << "\n";
    }
  }

  else {
    automaton(tokens[0]);
  }
}