#include <vector>
#include <iostream>

#include "BinarySearch.cpp"
using namespace std;

int main() {
  Solution sol;

  vector<int> vect = {-1,0,2,4,6,8};
  cout << sol.search(vect, 1) << endl;
  // cout << 5  2 << endl;

  return 0;
}