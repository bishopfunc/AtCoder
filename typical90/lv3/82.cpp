#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod (ull)(1e9 + 7ULL)

// 100が100個書くので 等差数列の和の公式
// 交通範囲がないと反転する cnt(max(3,10), (min(5, 99))) => cnt(10, 5)

ull power(ull a, ull b) {
  a %= mod;
  if (b == 0) return 1ULL;
  if (a == 0) return 0ULL;
  if (b % 2 == 0) {
    ull half = power(a, b / 2ULL);
    return (half * half) % mod;  // 修正: 計算結果が大きくなりすぎないように
  }
  return (a * power(a, b - 1ULL)) % mod;  // 修正: ここも同様
}

// a / b  % M = (a * b(M - 2)) % M
ull divide_mod(ull a, ull b) {
  a %= mod;
  b %= mod;
  return (a * power(b, mod - 2ULL)) % mod;
}

ull cnt(ull a, ull b) {
  if (a > b) return 0;
  ull N = b - a + 1;
  ull sum = (N % mod) * ((a + b) % mod) % mod;
  return divide_mod(sum, 2ULL);
}

int main() {
  ull L, R;
  // L = (ull)1e18 - 1ULL;
  // R = (ull)1e18;
  cin >> L >> R;
  ull pow = 1;
  // iは桁数 1-19
  ull ans = 0;
  for (int i = 1; i <= 19; i++) {
    ull l = pow, r = pow * 10ULL - 1ULL;
    // cout << i << endl;
    // cout << "l: " << l << ", r: " << r << endl;
    // cout << "L: " << L << ", R: " << R << endl;
    ans = (ans + (ull)i * cnt(max(L, l), min(R, r)) % mod) % mod;
    // ans += でmod計算されてない部分がある
    pow *= 10;
  }
  // cout << ((L % mod) * (18 % mod) + (R % mod) * (19 % mod)) % mod << endl;
  // cout << pow * 10 << endl;
  // if (L >= pow || R >= pow) { ans += 19ULL * cnt(L, R); }
  cout << ans << endl;
}