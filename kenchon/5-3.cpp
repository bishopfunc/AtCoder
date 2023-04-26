#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
const ll INF = 1LL << 60;

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  int N; cin >> N;
  vector<ll> h(N);
  vector<ll> dp(N, INF);
  rep(i, 0, N) cin >> h[i];

  dp[0] = 0;
  rep(i, 1, N) {
    chmin(dp[i], dp[i - 1] +  abs(h[i] - h[i - 1]));
    if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }


  // rep(i, 0, N) cout << dp[i] << endl;
  cout << dp[N - 1] << endl;

}