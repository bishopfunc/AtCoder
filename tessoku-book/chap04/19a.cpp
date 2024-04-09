#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9

int main() {
  int N, W;
  cin >> N >> W;
  ll dp[N + 1][W + 1];  // i番目の商品で重さjの時の価値の最大値
  // 何もしない dp[i-1][j]
  // 重さw,価値vを追加する dp[i-1][j-w]+v
  // 上記2つの最大値

  // 初期化
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = -INF;  // 初期値はマイナス
    }
  }
  dp[0][0] = 0;  // 商品なしで重さ0なら価値も0
  for (int i = 1; i <= N; i++) {
    ll w, v;
    cin >> w >> v;

    for (int j = 0; j <= W; j++) {
      // 重さ0価値0も意味ある(ナップザックに何もない)
      if (j >= w)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  ll max_v = 0;
  for (int j = 0; j <= W; j++) max_v = max(dp[N][j], max_v);
  cout << max_v << endl;
}