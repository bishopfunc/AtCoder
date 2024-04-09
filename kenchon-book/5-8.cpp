#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
const int INF = 1 << 29;

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  string S, T;
  cin >> S >> T;
  int size_s = S.size(), size_t = T.size();
  vector<vector<int>>dp(size_s + 1, vector<int>(size_t + 1, INF));

  dp[0][0] = 0;
  rep(i, 0, size_s + 1) {
    rep(j, 0, size_t + 1) {
      // 変更
      if (i > 0 & j > 0) {
        if(S[i - 1] == T[j - 1]) chmin(dp[i][j], dp[i - 1][j - 1]);
        else chmin(dp[i][j], dp[i - 1][j - 1] + 1);
      }
      // 削除
      if(i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);
      if(j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);
    }
  }
  cout << dp[size_s][size_t] << endl;
}