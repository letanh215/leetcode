#include "FirstNonRepeatingChar.h"

char firstNonRepeatingChar(const string& input_string) {
  
  unordered_map<char, int> char_map;
  for (auto it = input_string.begin(); it != input_string.end(); it++) {
    auto temp = char_map.find(*it);
    if (temp != char_map.end()) {
      temp->second++;
    } else {
      char_map.insert({*it, 1});
    }
  }

  for (auto it = input_string.begin(); it != input_string.end(); it++) {
    auto temp = char_map.find(*it);
    if (temp->second == 1) {
      return temp->first;
    }
  }

  return '\0';
}