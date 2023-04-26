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
ll dp[110][10100] = {0}; //dp[i][j] i番目までの整数でjを作れる場合の数
int main() {
  int N, M; 
  cin >> N >> M;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  
  dp[0][0] = 1; //0番目で(なし)で1通り作る
  rep(i, 0, N) rep(j, 0, M + 1) {
    if (j - a[i] >= 0) (dp[i + 1][j] += dp[i][j - a[i]]) %= MOD; //a[i]を足すかどうか
    (dp[i + 1][j] += dp[i][j]) %= MOD; //足さない 
    // 場合の数を更新する, だいたい0に足す
    // 7を0...12まで1通り作れる, 1通りを更新する
  }
  cout << dp[N][M] << endl;
}