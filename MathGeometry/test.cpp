#include <iostream>
#include <vector>
#include <algorithm>

// #include "RotateImage.cpp"
// #include "SpiralMatrix.cpp"
// #include "SetMatrixZeroes.cpp"
// #include "NonCyclicalNumber.cpp"
// #include "PlusOne.cpp"
// #include "PowXN.cpp"
#include "MultiplyStrings.cpp"

using namespace std;

void printMatrix(const vector<vector<int>> vect) {
  for (auto row: vect) {
    for (auto ele : row) {
      printf("%2d ", ele);
    }
    cout << endl;
  }
}

void printVector(const vector<int> vect) {
  for (auto ele : vect) {
    printf("%2d ", ele);
  }
  cout << endl;
}

int main() {

  Solution sol;

  vector<vector<int>> vect = {
    // {1,2,3},{5,0,7},{9,10,11}
    {0, 1}, {1, 1}
  };

  // printMatrix(vect);
  // reverse(vect.begin(), vect.end());
  // cout << endl;
  // sol.rotate(vect);
  // vector<int> res = sol.spiralOrder(vect);
  // sol.setZeroes(vect);
  // printMatrix(vect);
  // printVector(res);
  // int n = 100;
  // cout << sol.isHappy(n) << endl;

  // vector<int> vect1 = {9, 9, 9};
  // printVector(sol.plusOne(vect1));

  // cout << sol.myPow(1.10000, -3) << endl;
  cout << sol.multiply("563", "13") << endl;
  return 0;
}