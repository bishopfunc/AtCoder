#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define large (ll)1e18

// 掛け算でオーバーフローするなら割り算で判定しよう
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int main() {
  ll A, B;
  cin >> A >> B;
  ll tmp = gcd(A, B);
  ll r = B / tmp;  // 10^18 * 10^18 > 2^32
  ll lcm = r * A;
  // a * r <= 1e18 | a <= 1e18 / r | a > 1e18 / r
  // if (lcm > large || (A != 0 && B != 0 && lcm == 0)) cout << "Large" << endl;
  if (r > (large / A)) cout << "Large" << endl;
  // 1<=A,Bが条件にある マイナスはオーバーフロー
  else cout << lcm << endl;
}