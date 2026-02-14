#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int r = *max_element(piles.begin(), piles.end());

    int sumHour;
    int minHour = h + 1;
    int l = 0;

    while (l < r) {
      int rate = (l + r) / 2;
      
      sumHour = 0;
      for (int i = 0; i < piles.size(); i++) {
        sumHour += ceil((double)piles[i] / rate);
      }
      if (sumHour > h) {
        l = rate + 1;
      } else if (sumHour < h) {
        r = rate;
      }
      minHour = min(sumHour, minHour);
      printf("%d %d\n", rate, sumHour);
    }

    return minHour;
  }
};
