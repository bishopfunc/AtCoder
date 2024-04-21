// 区間DP
// https://qiita.com/mizoono/items/18cda7b6333bf35fb9ad
// https://kutimoti.hatenablog.com/entry/2018/03/10/220819
// ぷよぷよの連鎖的なことができるイメージ
// 2パターンに分け、再帰で実装

// dp[l][r] = dp[l+1][r] と dp[l][r-1]から更新 N^2 N=3000
// dp[l][r] = 全ての i について dp[l][i] と dp[i][r] を確認して更新 N^3 N=500

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp[l][r] 区間 [l,r]の最大スコア
// ブロックiがブロックP_iより先に除去された場合、A_i点
// 逆に、ブロックP_iがブロックiよりあとならOK
// ブロックP_l-1がブロックl-1よりあとならOK
//  l-1<l<=P[l-1]  l-1はlより早く除去
// ブロックP_r+1がブロックr+1よりあとならOK
// P[r+1]<=r<r+1  r+1はrより早く除去
// こらから除去されるには l<=P[i]<=r の範囲に入ってないといけない

int main() {
  int N;
  cin >> N;
  int dp[N + 1][N + 1];
  vector<int> A(N + 1), P(N + 1);
  for (int i = 1; i <= N; i++) { cin >> P[i] >> A[i]; }  // P A の順序
  dp[1][N] = 0;                                          // 初期値 区間1~N

  // 長さN-2~0まで探索 1,(2,3),4 が最後
  for (int len = N - 2; len >= 0; len--) {
    for (int l = 1; l + len <= N; l++) {  // r <= N
      int r = l + len;
      int score1 = 0, score2 = 0;
      // l-1が除去される
      // if (l <= P[l - 1]) score1 = A[l - 1];
      if (l <= P[l - 1] && P[l - 1] <= r) score1 = A[l - 1];

      // r+1が除去される
      // if (P[r + 1] <= r) score2 = A[r + 1];
      if (l <= P[r + 1] && P[r + 1] <= r) score2 = A[r + 1];

      if (l == 1) dp[l][r] = dp[l][r + 1] + score2;
      else if (r == N) dp[l][r] = dp[l - 1][r] + score1;
      else dp[l][r] = max(dp[l - 1][r] + score1, dp[l][r + 1] + score2);
    }
  }
  // 単独で取った時の最大スコア これまでのパターンや最初に取った場合がある
  int ans = 0;
  for (int i = 1; i <= N; i++) ans = max(ans, dp[i][i]);
  // 最後の1個に詰まってる
  cout << ans << endl;
}