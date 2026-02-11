#include <iostream>
#include <vector>
#include <algorithm>

// #include "RotateImage.cpp"
#include "SpiralMatrix.cpp"

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
    {1, 2, 3},
    {5, 6, 7},
    {9, 10 ,11},
    // {13, 14, 15, 16, 6, 3}
  };

  printMatrix(vect);
  // reverse(vect.begin(), vect.end());
  cout << endl;
  // sol.rotate(vect);
  vector<int> res = sol.spiralOrder(vect);
  // printMatrix(vect);
  printVector(res);
  return 0;
}