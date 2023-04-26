#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
//---------------------------------------------------------------------------------------------------
ll h[100010][3];
ll dp[100010][3];

int main() {
  int N; cin >> N;
  rep(i, 0, N) rep(j, 0, 3) {
    cin >> h[i][j];
    dp[i][j] = 0; //initialize
  }
  rep(i, 0, N) rep(j, 0, 3) rep(k, 0, 3) {
    if (j == k) continue;
    chmax(dp[i + 1][k], dp[i][j] + h[i][k]); //h[i,k]k個目を選んだからd[i+1,k]
  }
  ll max = 0;
  rep(k, 0, 3) chmax(max, dp[N][k]); //i+1=N番目まで更新する, i=N-1のときdp[N]が更新される？？
  cout << max << endl;
}