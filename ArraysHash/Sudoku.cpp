#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
  public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int n = 9;

    if (board.size() != 9) {
      return false;
    }
    vector<unordered_set<int>> row(9);
    vector<unordered_set<int>> col(9);
    vector<unordered_set<int>> square(9);
    
    for (int rows = 0; rows < n; rows++) {
      for (int cols = 0; cols < n; cols++) {
        if (board[rows][cols] != '.') {
          int val = board[rows][cols] - '0';
          
          if (row[rows].count(val) == 0) {
            row[rows].insert(val);
          } else {
            return false;
          }
          
          if (col[cols].count(val) == 0) {
            col[cols].insert(val);
          } else {
            return false;
          }
          
          int n_squared = (rows / 3) * 3 + (cols / 3);
          if (square[n_squared].count(val) == 0) {
            square[n_squared].insert(val);
          } else {
            return false;
          }
        }
      }
    }
    
    return true;
  }
};
