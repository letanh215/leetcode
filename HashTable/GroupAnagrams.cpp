  #include "GroupAnagrams.h"

  vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    
    unordered_map<int, vector<string>> anagrams;
    
    for (auto it : strings) {
      int hash = 0;
      for (auto ite = it.begin(); ite != it.end(); ite++) {
        hash += int(*ite) * (int(*ite) - 96);
      }
      auto temp = anagrams.find(hash);
      if (temp == anagrams.end()) {
        vector<string> v = {it};
        anagrams.insert({hash, v});
      } else {
        temp->second.push_back(it);
      }
    }

    vector<vector<string>> output;

    for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
      output.push_back(it->second);
    }
    
    return output;
  }