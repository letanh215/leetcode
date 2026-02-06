#include <vector>

using namespace std;

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    
    int minValue = 101;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
      int sellVal = prices[i] - minValue;
      if (sellVal > maxProfit) {
        maxProfit = sellVal;
      }
      if (prices[i] < minValue) {
        minValue = prices[i];
      }
    }
    
    return maxProfit;
  }
};
