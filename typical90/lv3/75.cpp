#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N (ll)1e12

// 素因数分解
vector<ll> prime_factorize(ll N) {
  vector<ll> factors;
  for (ll i = 2; i * i <= N; ++i) {
    while (N % i == 0) {
      factors.push_back(i);
      N /= i;
    }
  }
  if (N != 1LL) factors.push_back(N);  // 最後の素因数
  return factors;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> factors = prime_factorize(N);

  // 素因数の個数を満たす最小の2のべき乗
  ll ans = 0;
  while ((1LL << ans) < factors.size()) { ans++; }
  cout << ans << endl;
}