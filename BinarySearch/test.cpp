#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

// #include "BinarySearch.cpp"
// #include "2DMatrixSearch.cpp"
#include "KokoBanana.cpp"

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

  vector<int> vect = {1, 4, 3, 2};
  // cout << sol.search(vect, 1) << endl;
  // cout << 5  2 << endl;

  vector<vector<int>> matrix = {
    {1,2,4,8},{10,11,12,13},{14,20,30,40}
  };

  // cout << sol.searchMatrix(matrix, 11) << endl;
  cout << sol.minEatingSpeed(vect, 9) << endl;
  return 0;
}