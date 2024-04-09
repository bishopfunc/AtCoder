#include <bits/stdc++.h>
using namespace std;

vector<int> dp(50, -1);

int fib(int n) {
  if (dp[n] != -1) return dp[n];
  if (n == 0 || n == 1) return dp[n] = 1;
  return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  cin >> n;
  cout << fib(n) << endl;
  // for (int i = 0; i <= n; i++) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
}