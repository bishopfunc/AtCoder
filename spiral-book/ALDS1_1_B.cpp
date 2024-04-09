#include <bits/stdc++.h>
using namespace std;

// Greatest Common Divisor

// int gcd(int x, int y) {
//   int minv = min(x, y);
//   for (int d = minv; d >= 1; d--) {
//     if (x % d == 0 && y % d == 0) {
//       return d;
//     }
//   }
//   return 1;
// }

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
// gcd(15, 21) -> gcd(21, 15) 入れ替えるだけで結果は変わらない

// int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
// yが0でない場合はgcd(y, x % y)を返し、yが0の場合はxを返す

int main() {
  int x, y;
  cin >> x >> y;
  cout << gcd(x, y) << endl;
}