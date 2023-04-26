#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000;
//---------------------------------------------------------------------------------------------------
ll dp[110][10100]; //dp[i][j] i番目までの整数でjを作れるのに必要な整数の最小個
int main() {
  int N, M; 
  cin >> N >> M;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  
  rep(i, 0, 110) rep(j, 0, 10100) dp[i][j] = INF; //最小値だから最大で初期化, {0}は0しか初期化できない
  dp[0][0] = 0; //0番目で(なし)で0を作るには0個整数が必要

  rep(i, 0, N) rep(j, 0, M + 1) {
    if (j - a[i] >= 0) chmin(dp[i + 1][j], dp[i][j - a[i]] + 1); //a[i]を足すかどうか
    chmin(dp[i + 1][j], dp[i][j]); //足さない 
    // 作れるなら必要な数+1する, 選ぶ場合
  }
  if (dp[N][M] != INF) cout << dp[N][M] << endl;
  else cout << -1 << endl;
}