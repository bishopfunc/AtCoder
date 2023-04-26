#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define rep2(i, s, n) for (int i = (s) - 1; i >= (int)(n); i--) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------

ll power(ll a, ll b, ll m) {
  int res = 1, p = a; // p = a
  rep(i, 0, b + 1) { //b + 1はなんとなく
    int divisor = (1 << i);
    if ((b % divisor) == 1) res = (res * p) % m;
    p = (p * p) % m;
  }
  return res;
}


int main() {
  ll A, B; cin >> A >> B;
  cout << power(A, B, MOD) << endl;
}