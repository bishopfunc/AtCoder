#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  vector<ll> h(N);
  rep(i, 0, N) cin >> h[i];

  vector<ll> dp(N + 2, INF); //配列外参照 i+2
  dp[0] = 0;
  rep(i, 0, N) {
    chmin(dp[i + 1], abs(h[i + 1] - h[i]) + dp[i]);
    chmin(dp[i + 2], abs(h[i + 2] - h[i]) + dp[i]);
  }
  cout << dp[N - 1] << endl;
}