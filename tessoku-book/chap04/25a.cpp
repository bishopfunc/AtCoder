#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp[i][j] ijマスまでの通り方
// dp[i][j] = dp[i][j-1] + dp[i-1][j]
// 障害物があれば更新しない

int main() {
  int H, W;
  cin >> H >> W;
  ll dp[H][W];
  char C[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i][j];
      dp[i][j] = 0;  // 初期化
    }
  }
  if (C[0][0] != '#') dp[0][0] = 1LL;  // 1通り
  // 0列目
  for (int i = 1; i < H; i++) {
    if (C[i][0] == '#') dp[i][0] = 0;  // ブロックなら0
    else dp[i][0] = dp[i - 1][0];
  }
  // 0行目
  for (int j = 1; j < W; j++) {
    if (C[0][j] != '#') dp[0][j] = 0;  // ブロックなら0
    else dp[0][j] = dp[0][j];
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i >= 1 && j >= 1 && C[i][j] != '#' && C[i][j] != '#')
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      else if (i >= 1 && C[i][j] != '#') dp[i][j] = dp[i - 1][j];
      else if (j >= 1 && C[i][j] != '#') dp[i][j] = dp[i][j - 1];
      // else if (j ==0) dp[i][j] = dp[i][j];
    }
  }
  cout << dp[H - 1][W - 1] << endl;
}