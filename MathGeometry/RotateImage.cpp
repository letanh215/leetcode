#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    reverse(matrix.begin(), matrix.end());

    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int t = matrix[i][j];
        matrix[i][j] = matrix[j][i]; 
        matrix[j][i] = t;
      }
    }
  }
};
