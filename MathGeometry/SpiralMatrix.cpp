#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<size_t> steps = {matrix[0].size(), matrix.size() - 1}; // 3 , 2 -> 2, 2 -> 2, 1 -> 1, 1 -> 

    int r = 0, c = -1, d = 0;

    vector<int> res;

    while (steps[d & 1] > 0) {

      for (int i = 0; i < steps[d & 1]; i++) {
        r += directions[d][0];
        c += directions[d][1];
        res.push_back(matrix[r][c]);
      }
      steps[d & 1]--;
      d = (d + 1) % 4;
    }
    return res;
  }
};
