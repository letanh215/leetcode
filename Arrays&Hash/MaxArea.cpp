#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
  int maxArea(vector<int>& heights) {
    int areaMax = 0;

    int i = 0;
    int j = heights.size() - 1;

    while (i < j) {
      int area = (j - i) * min(heights[i], heights[j]);

      if (area > areaMax) {
        areaMax = area;
      }

      if (heights[i] < heights[j]) {
        i++;
      } else {
        j--;
      }
    }
    return areaMax;
  }
};
