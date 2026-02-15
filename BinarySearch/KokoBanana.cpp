#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int minEatingSpeed(vector<int>& piles, int h) {
    long r = *max_element(piles.begin(), piles.end());

    long sumHour;
    long res;
    long l = 0;

    while (l <= r) {
      long rate = (l + r) / 2;
      if (rate == 0) {
        if (l != r) {
          rate = 1;
        } else {
          break;
        }
      }
      
      sumHour = 0;
      for (int i = 0; i < piles.size(); i++) {
        // printf("%5.2f", ceil((double)piles[i] / rate));
        sumHour += ceil((double)piles[i] / rate);
      }
      // printf("\nLeft: %ld, Right: %ld\n", l, r);
      // printf("Rate: %ld, Sum: %ld\n", rate, sumHour);

      if (sumHour > h) {
        l = rate + 1;
      } else if (sumHour <= h) {
        r = rate - 1;
        res = rate;
      }
    }

    return res;
  }
};
