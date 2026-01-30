#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int counter = 0;

vector<unsigned long long> memo(100, -1);

unsigned long long fib_memo(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  counter++;
  if (memo[n-1] == -1) {
    memo[n-1] = fib_memo(n-1);
  } 
  if (memo[n-2] == -1) {
    memo[n-2] = fib_memo(n-2);
  }
  return memo[n-1] + memo[n-2];
}

unsigned long long fib(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  counter++;
  return fib(n-1) + fib(n-2);
}

int main() {
  long res = fib(90);
  // unsigned long long res = fib_memo(90);
  auto start = chrono::system_clock::now();
  std::cout << res << " " << counter << std::endl;
  chrono::duration<double, std::milli> duration = chrono::system_clock::now() - start;
  std::cout << duration.count() << endl;
  return 0;
}