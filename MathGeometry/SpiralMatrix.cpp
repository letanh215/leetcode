#include <vector>

using namespace std;

class Solution {
  public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int t = 0;
    int b = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    
    int i = 0;
    int j = 0;
    
    vector<int> res;
    for (int inex = 0; inex < matrix.size() / 2; inex++) {
      if (inex > 0) {
        j++;
      }
      while (j < r) {
        res.push_back(matrix[i][j]);
        j++;
      }
      
      while (i < b) {
        res.push_back(matrix[i][j]);
        i++;
      }
      
      while (j > l) {
        res.push_back(matrix[i][j]);
        j--;
      }
      
      while (i > t) {
        res.push_back(matrix[i][j]);
        i--;
      }

      t++;
      b--;
      l++;
      r--;
    }
    if (matrix.size() % 2 == 1) {
      res.push_back(matrix[matrix.size() / 2][matrix.size() / 2]);
    }
    return res;
  }
};
