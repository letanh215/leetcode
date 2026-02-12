#include <cmath>

using namespace std;

class Solution {
  public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    double res = 1;
    int power = abs(n);

    while (power) {
      if (power & 1) {
        res *= x;
      }

      x *= x;
      power >>= 1;
    }
    if (n < 0) return 1 / res; 
    else return res;
  }
};
