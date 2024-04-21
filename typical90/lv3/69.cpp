#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e9 + 7)

ll power(ll a, ll b) {
  a %= mod;
  if (b == 0) return 1;
  if (a == 0) return 0;
  if (b % 2 == 0) return power(a * a, b / 2) % mod;
  return a * power(a, b - 1) % mod;
}

// よく見たらpowの問題でした
//  K * (K - 1) * (K - 2) * ...

// N K 22-OK 12-OK 11-OK 21-NG
// K=1の時だけ場合分けすれば良い
int main() {
  ll N, K;
  cin >> N >> K;
  ll res;
  if (K == 1) res = (N == 1) ? 1 : 0;
  else if (N == 1) res = K;
  else if (N == 2) res = (K * (K - 1)) % mod;
  else { res = ((K * (K - 1)) % mod) * (power(K - 2, N - 2) % mod) % mod; }
  cout << res << endl;
}