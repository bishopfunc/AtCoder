#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000;
int dp[1010][1010] = {0}; //dp[i][j]: s[i]とt[j]までのLCSの最大値
//---------------------------------------------------------------------------------------------------
int main() {
  string S, T;
  cin >> S >> T;

  dp[0][0] = 0;
  rep(i, 0, (int)S.size())
    rep(j, 0, (int)T.size()) {
      if (S[i] == T[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1); //共通なら+1
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  cout << dp[(int)S.size()][(int)T.size()] << endl;
}