#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 期待値の計算
// A方式
// B方式 E = Y + 1/6 E
//  E = 6/5 Y  コストを倍
// 2~6のサイコロだと考える
// 3 -> 1: 1/6E + 2~3: 2/6Y*2 + 4~6: 3/6Y
// sum 2~6 f(N/b) / 5
// 20 * 6/5 + 20 * 2/5
ll N, A, X, Y;
map<int, double> memo;
double f(ll n) {
  if (n == 0) return 0;  // base case
  if (memo.count(n)) return memo[n];
  double exp_a = f(n / A) + X;
  double exp_b = 0;
  for (int b = 2; b <= 6; b++) { exp_b += f(n / b); }
  exp_b /= 5.0;
  exp_b += Y * 1.2;
  return memo[n] = min(exp_a, exp_b);
}

int main() {
  cin >> N >> A >> X >> Y;
  printf("%.10f", f(N));
}