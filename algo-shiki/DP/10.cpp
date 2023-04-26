// なんでDP遷移式が成立するのかよくわからない, なぜ-1
#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll LINF = 1LL << 60;
const int INF = 1 << 29;
const ll MOD = 1000;
//---------------------------------------------------------------------------------------------------
int dp[1010][1010]; //sのi文字まで,tのj文字まで変換する最小変換回数, j挿入+1,i削除+1, if i=j 変換+0 else +1

int main() {
  string S, T; cin >> S >> T;
  int s_size = (int)S.size();
  int t_size = (int)T.size();
  rep(i, 0, s_size + 1) rep(j, 0, t_size + 1) dp[i][j] = INF;

  dp[0][0] = 0;
  rep(i, -1, s_size) 
    rep(j, -1, t_size) {
      if (i == -1 && j == -1) continue; //なぜか-1からはじめて, スキップする
      if (i >= 0 && j >= 0) {
        if (S[i] == T[j]) chmin(dp[i + 1][j + 1], dp[i][j]);
        else chmin(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      if (i >= 0) chmin(dp[i + 1][j + 1], dp[i][j + 1] + 1); //削除 //>0 -1を判定, もう片方は+1>=0
      if (j >= 0) chmin(dp[i + 1][j + 1], dp[i + 1][j] + 1); //挿入
    }
  // rep(i, 0, s_size + 1) {
  //   rep(j, 0, t_size + 1) cout << dp[i][j] << " ";
  //   cout << endl;
  // }    
  cout << dp[s_size][t_size] << endl;
}