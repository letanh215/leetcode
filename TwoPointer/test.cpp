#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// #include "MaxArea.cpp"
#include "TrappingRain.cpp"

using namespace std;

template <typename T>
void printVector(vector<T> vect) {
  for (auto ele : vect) {
    cout << ele << ", " ;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> vect = {0,2,0,3,1,0,1,3,2,1};
  // vector<int> res = sol.twoSum(vect, 5);
  // vector<vector<int>> res = sol.threeSum(vect);
  // printf("%d \n", sol.maxArea(vect));
  // vector<int> res = sol.topKFrequent(vect, 1);
  cout << sol.trap(vect) << endl;
  // printVector(res);
  return 0;
}