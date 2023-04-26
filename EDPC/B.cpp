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
  int N, K; 
  cin >> N >> K;
  vector<ll> h(N);
  rep(i, 0, N) cin >> h[i];

  vector<ll> dp(N + K, INF); //配列外参照 i+j
  dp[0] = 0;
  rep(i, 0, N) rep(j, 1, K + 1) {
    chmin(dp[i + j], abs(h[i + j] - h[i]) + dp[i]);
  }
  cout << dp[N - 1] << endl;
}