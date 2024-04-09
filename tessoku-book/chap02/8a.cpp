#include <bits/stdc++.h>
using namespace std;
int X[1501][1501], S[1501][1501];
;
int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> X[i][j];
    }
  }
  // 初期化
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      S[i][j] = 0;
    }
  }
  // 横方向の累積和
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      S[i][j] = S[i][j - 1] + X[i][j];
    }
  }
  // 縦方向の累積和
  // 大きいループは横方向、小さいループは縦方向、既存の横の累積和を使う
  for (int j = 1; j <= W; j++) {
    for (int i = 1; i <= H; i++) {
      S[i][j] = S[i - 1][j] + S[i][j];
    }
  }
  int Q;
  cin >> Q;
  //
  for (int i = 0; i < Q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = S[c][d] + S[a - 1][b - 1] - S[a - 1][d] - S[c][b - 1];
    cout << res << endl;
  }
}