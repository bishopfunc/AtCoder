#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
const ll INF = 1LL << 60;
int main() {
  int N; cin >> N;
  vector<ll> h(N);
  vector<ll> dp(N, INF);
  rep(i, 0, N) cin >> h[i];

  dp[0] = 0;
  rep(i, 1, N) {
    if (i == 1) dp[i] = abs(h[i] - h[i - 1]);
    else dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs( h[i] - h[i - 2]));
  }


  // rep(i, 0, N) cout << dp[i] << endl;
  cout << dp[N - 1] << endl;

}