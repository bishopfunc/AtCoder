#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> dp(N, vector<ll>(N, INF));
  rep(i, 0, M) {
    int a, b, w;
    cin >> a >> b >> w;
    dp[a][b] = w;
  }
  rep(v, 0, N) dp[v][v] = 0; //辺がないときはINF

  // WarsghallFroid
  rep(k, 0, N) 
    rep(i, 0, N) 
      rep(j, 0, N) 
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  bool exist_negative_cycle = false;
  rep(v, 0, N) {
    if (dp[v][v] < 0) exist_negative_cycle = true;
  }
  if (exist_negative_cycle) cout << "negative" << endl;
  else {
    rep(i, 0, N) rep(j, 0, N) {
      if (dp[i][j] < INF/2) cout << dp[i][j]  << endl;
      else cout << "INF" << endl;
    }
  }
}