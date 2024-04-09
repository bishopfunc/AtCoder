#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
const ll INF = 1LL << 60;

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  int N; cin >> N;

  vector<vector<ll>>c(N + 1, vector<ll>(N + 1));
  vector<ll>dp(N + 1, INF);
  rep(i, 0, N + 1) {
    rep(j, 0, N + 1) {
      cin >> c[i][j];
    }
  }
  dp[0] = 0;
  rep(i, 0, N + 1) {
    rep(j, 0, i) {
      chmin(dp[i], dp[j] + c[i][j]);
    }
  }
  cout << dp[N] << endl;
}