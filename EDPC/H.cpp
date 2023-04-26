#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
//---------------------------------------------------------------------------------------------------

void add(ll &a, ll b) {
  a += b;
  if (a >= MOD) a %= MOD;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, 0, H) cin >> S[i];
  
  ll dp[1010][1010] = {0};
  dp[0][0] = 1;
  rep(i, 0, H) rep(j, 0, W) {
    if (i + 1 < H && S[i + 1][j] == '.') add(dp[i + 1][j], dp[i][j]);
    if (j + 1 < W && S[i][j + 1] == '.') add(dp[i][j + 1], dp[i][j]); //次のますが空なら
    // DP: (0,0)=>(i,j)経路の合計
    // 最初の1がたされていく
    // 配るDP
  }
  //  rep(i, 0, H) {
  //   rep(j, 0, W) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[H - 1][W - 1] << endl;
}