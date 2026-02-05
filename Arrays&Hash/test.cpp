#include <iostream>
#include <algorithm>
// #include "EncodeDecode.cpp"
// #include "ProductsOfArrays.cpp"
// #include "LongestConsecutive.cpp"
// #include "ValidPalindrome.cpp"
// #include "TwoSum2.cpp"
// #include "3Sum.cpp"
// #include "MaxArea.cpp"
#include "KFreq.cpp"
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printVector(vector<T> vect) {
  for (auto ele : vect) {
    cout << ele << ", " ;
  }
  cout << endl;
}

int main() {
  // cout << int('b') * (int('b') - 97) << endl;
  // vector<string> strs = {"Hello", "World", "Hell"};
  // vector<int> set = {-1,0,1,2,3};
  // vector<string> strs = {"",""};
  Solution sol;
  // vector<int> res = sol.productExceptSelf(set);
  // string encoder = sol.encode(strs);
  // cout << encoder << endl;
  // vector<string> res = sol.decode(encoder);
  // cout << res.size() << endl;
  
  // vector<vector<int>> testset(9);
  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9; j++) {
  //     int n_squared = (i / 3) * 3 + (j / 3);
  //     printf("%d ", n_squared);
  //   }
  //   printf("\n");
  // }
  // printf("%d ", '5'-'0');
  // cout << endl; 

  // vector<int> set = {2,20,4,10,3,4,5};
  // string s = "Was it a car or a cat I saw?";
  // cout << sol.isPalindrome(s);

  vector<int> vect = {3,3};
  // vector<int> res = sol.twoSum(vect, 5);
  // vector<vector<int>> res = sol.threeSum(vect);
  // printf("%d \n", sol.maxArea(vect));
  vector<int> res = sol.topKFrequent(vect, 1);
  printVector(res);
  return 0;
}