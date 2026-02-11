#include <vector>

using namespace std;

class Solution {
  public:
  void setZeroes(vector<vector<int>>& matrix) {

    vector<bool> rows(matrix.size(), false);
    vector<bool> cols(matrix.size(), false);
    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        if (matrix[r][c] == 0) {
          rows[r] = true;
          cols[c] = true;
        }
      }
    }  

    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        if (rows[r]) {
          matrix[r][c] = 0;
        }
        if (cols[c]) {
          matrix[r][c] = 0;
        }
      }
    } 
  }
};
