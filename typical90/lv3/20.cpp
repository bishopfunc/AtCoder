#include <bits/stdc++.h>
using namespace std;
#define INF (ll)1e18
typedef long long ll;

// 小数は誤差があるから整数を使おう

ll log2ll(ll x) {
  if (x == 0) return INF;
  if (x == 1) return 0;
  ll ret = 0;
  while (x > 1) {
    x >>= 1;
    ret++;
  }
  return ret;
}

// x^y
ll powll(ll x, ll y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  if (y % 2 == 0) return powll(x * x, y / 2);
  else return x * powll(x, y - 1);
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  bool res = false;
  // log2(a) < log2(c) * b => a < c^b
  if (a < powll(c, b)) res = true;
  cout << (res ? "Yes" : "No") << endl;
}