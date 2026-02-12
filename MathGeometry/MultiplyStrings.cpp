#include <string>

using namespace std;

class Solution {
  public:

  string sumStrings(string num1, string num2) {
    if (num1.size() < num2.size()) {
      string temp = num1;
      num1 = num2;
      num2 = num1;
    }

    bool carry = false;
    int i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (j >= 0) {
      char t = num1[i] + num2[j] - 2 * '0';

    }
  }

  string multiply(string num1, string num2) {
    
  }
};
