// なぜかACできない
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
ll dp[510][10100]; //dp[i][j] i番目までの整数でjを作れるのに選んだA[i]の最小個数
int main() {
  int N, M; 
  cin >> N >> M;
  vector<ll> a(N), b(N);
  rep(i, 0, N) {
    cin >> a[i] >> b[i];
  }
  rep(i, 0, N + 1) rep(j, 0, M + 1) dp[i][j] = INF; //最小値だから最大で初期化, {0}は0しか初期化できない
  dp[0][0] = 0; //0番目で(なし)で0を作るには0個整数が必要

  rep(i, 0, N) rep(j, 0, M + 1) {
    if (dp[i][j] != INF) dp[i + 1][j] = 0; //A[i]選ばない, A[i]を選ぶ個数は0, なんらんかの更新がかかるとき
    if (j - a[i] >= 0) {
    if(dp[i][j - a[i]] != INF) chmin(dp[i + 1][j], 1LL); //a[i]を新しく使う, dp[i][j - a[i]]選ぶ前が更新済みか考える //(ll, ll) //計i+1番目の整数,j個のA[i]
      if(dp[i][j - a[i]] < b[i]) chmin(dp[i + 1][j], dp[i + 1][j - a[i]] + 1); //a[i]を追加する, //計i+1番目の整数
    }
    //3つの最小値を考える
  }
  if (dp[N][M] != INF) cout << "Yes" << endl;
  else cout << "No" << endl;
  // rep(i, 0, N + 1) {
  //   rep(j, 0, M + 1) cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  cout << 1LL << endl;
}