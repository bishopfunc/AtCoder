// Binary Method Exponentiation 
#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;

ll pow_mod(ll n, ll k, ll m) {
  ll r = 1; //10110=22 
  for(; k > 0; k >>= 1) { //右シフト代入
    if (k & 1) r = (r * n) % m; //下1桁が1のとき、その時の値を保持
    n = (n * n) % m; //毎回自乗する
  }
  return r; //n^16, n^4, n^2を返す
}

int main() {
  ll N, M, P;
  cin >> N >> M >> P;
  cout << pow_mod(N, P, M) << endl;
}