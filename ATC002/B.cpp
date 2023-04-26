// Exponentiation by Squaring
#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;

ll pow_mod(ll n, ll k, ll m) {
  if (k == 0) return 1;
  else if (k % 2 == 1) return pow_mod(n, k - 1, m) * n % m; //奇数 自身*n 
  else {
    ll t = pow_mod(n, k / 2, m);
    return t * t % m;
  }
}

int main() {
  ll N, M, P;
  cin >> N >> M >> P;
  cout << pow_mod(N, P, M) << endl;
}