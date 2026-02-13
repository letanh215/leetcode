#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:

  string sumStrings(string num1, string num2) {
    if (num1.size() < num2.size()) {
      string temp = num1;
      num1 = num2;
      num2 = temp;
    }

    printf("%s %s\n", num1.c_str(), num2.c_str());

    bool carry = false;
    int i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (j >= 0) {
      char t = num1[i] + num2[j] - '0';
      if (carry) {
        t += 1;
        carry = false;  
      }

      if (t > '9') {
        t -= 10;
        carry = true;
      }
      res = t + res;
      j--;
      i--;
    }
    while (i >= 0) {
      if (carry) {
        char t = num1[i] + 1;
        res = t + res;
        carry = false;
      } else {
        res = num1[i] + res;
      }
      i--;
    }
    return res;
  }

  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    vector<int> res(num1.length() + num2.length(), 0);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < num1.length(); i++) {
      for (int j = 0; j < num2.length(); j++) {
        res[i+j] += (num1[i] - '0') * (num2[j] - '0');
        res[i+j+1] += res[i+j] / 10;
        res[i+j] %= 10; 
      }
    }

    int i = res.size() - 1;
    string s;
    while (i >= 0 && res[i] == 0) {
      i--;
    }

    while (i >= 0) {
      s += res[i] + '0';
      i--;
    }
    return s;
  }
};
