#include <bits/stdc++.h>
using namespace std;
int I[1502][1502], S[1501][1501];

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  // 初期化
  for (int i = 0; i <= H + 1; i++) {
    for (int j = 0; j <= W + 1; j++) {
      I[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
  }
  // imos
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // たすやつ
    I[a][b]++;
    I[c + 1][d + 1]++;
    // 引くやつ
    I[a][d + 1]--;
    I[c + 1][b]--;
  }
  // 横方向の累積和
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      S[i][j] = S[i][j - 1] + I[i][j];
    }
  }
  // 縦方向の累積和
  // 大きいループは横方向、小さいループは縦方向、既存の横の累積和を使う
  for (int j = 1; j <= W; j++) {
    for (int i = 1; i <= H; i++) {
      S[i][j] = S[i - 1][j] + S[i][j];
    }
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (j != 1) cout << " ";
      cout << S[i][j];
    }
    cout << endl;
  }
  cout << endl;
}