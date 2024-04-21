#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353

// ユークリッド LLにしてないからWA
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  ll res = gcd(gcd(A, B), C);
  cout << ((A + B + C) / res - 3) << endl;
  // 高さ / 最大公約数 = 分割できる個数 - 1 = 切る回数
}