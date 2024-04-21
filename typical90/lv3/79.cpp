#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int H, W;
  cin >> H >> W;
  ll A[H][W], B[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cin >> A[i][j]; }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cin >> B[i][j]; }
  }
  ll cnt = 0;
  bool ans = true;
  // 左上から1マスずつ合わせていく, 端の行と列以外は合わせられる
  for (int i = 0; i < H - 1; i++) {
    for (int j = 0; j < W - 1; j++) {
      ll d = B[i][j] - A[i][j];
      A[i][j] += d;
      A[i + 1][j] += d;
      A[i][j + 1] += d;
      A[i + 1][j + 1] += d;
      // 操作回数は正負関係ない
      cnt += abs(d);
    }
  }
  // 端のH+W-1の部分だけ確認すればいいが、全部確認
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++)
      if (A[i][j] != B[i][j]) {
        ans = false;
        break;
      }
  }
  if (ans) {
    cout << "Yes" << endl;
    cout << cnt << endl;
  } else cout << "No" << endl;
}