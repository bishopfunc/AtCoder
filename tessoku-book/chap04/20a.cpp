#include <bits/stdc++.h>
using namespace std;
// 最長共通部分列(Common Longest Subsequence)

// TODO
int dp[2001][2001];  // S,Tの合計共通部分列
// S+1文字 dp[i-1][j]
// T+1文字 dp[i][j-1]
// ST一致 S+1,T+1文字 dp[i-1][j-1]+1

int main() {
  string S, T;
  cin >> S >> T;
  int M = S.size();
  int N = T.size();
  dp[0][0] = 0;
  // 初期化 ijの0行列めはなし、1~N(0~N-1に変換して)文字までカウント
  // i=0 jの行をdp[0][j]で埋めるから全部初期化しなくていい
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= N; j++) {
      if (i >= 1 && j >= 1 && S[i - 1] == T[j - 1])
        dp[i][j] = max({
            dp[i - 1][j - 1] + 1,
            dp[i][j - 1],
            dp[i - 1][j],
        });
      else if (i >= 1 && j >= 1)
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      else if (i >= 1)
        dp[i][j] = dp[i - 1][j];
      else if (j >= 1)
        dp[i][j] = dp[i][j - 1];
    }
  }
  cout << dp[M][N] << endl;
}
