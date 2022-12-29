#include "Automaton.h"

using std::cout;

string declined_status = "rejected";
string states[] = {"q0","q1","qf"};
string accept_states = states[2];
string start_state = states[0];
char alphabetsL[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '$', ',', ';'};
char alphabetsN[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

string transition(string state, char symbol) {
  if(state == start_state) {
    for(int i = 0; i <= 53; i++) {
      if(symbol == alphabetsL[i]) {
        return states[1];
      }
    
      if(isspace(symbol)) {
        return states[0];
      }
    }
  }

  else if(state == states[1]) {
    for(int i = 0; i < 53; i++) {
      if(symbol == alphabetsL[i]) {
        return states[1];
      }
    
      if(isspace(symbol)) {
        return states[0];
      }
    }

    for(int i = 0; i < 10; i++) {
      if(symbol == alphabetsN[i]) {
        return states[1];
      }
    }
    
    if(symbol == ',') {
      return start_state;
    }

    else if(symbol == ';') {
      return states[2];
    }
  }

  return declined_status;
}

int automaton(string word) {
  string state = start_state;
    
  if(transition(start_state, word[0]) != declined_status) {
    for(int i = 0; i < word.length(); i++) {
      cout << "state " << state << " processing " << word[i] << " = ";
      state = transition(state, word[i]);
      cout << state << "\n";

      if(state == declined_status) {
        cout << "word is " << declined_status << "\n";

        return 0;
        break;
      }

      if(i == (word.length() - 1)) {
        if(state == accept_states) {
          cout << "word is accept" << "\n";

          return 1;
        }
    
        else {
          cout << "word is " << declined_status << "\n";

          return 0;
        }
      }
    } 
  }

  return 0;
}

vector <string> split(const string &text, char sep) {
  vector <string> tokens;
  size_t start = 0, end = 0;

  while((end = text.find(sep, start)) != string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }

  tokens.push_back(text.substr(start));
  
  return tokens;
}