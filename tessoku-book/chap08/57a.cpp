#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
// 2^32 > 10^9
// d回目の移動
int dp[32][MAX_N];  // (日, 今の穴) = N日後の穴
int A[MAX_N];
int main() {
  int N, Q;
  cin >> N >> Q;
  // 1-index 穴の番号が1~なので
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  // 初期状態は0
  for (int i = 1; i <= N; i++) {
    dp[0][i] = A[i];  // 2^0=1日後の場所
  }
  for (int d = 0; d <= 30; d++) {
    for (int i = 1; i <= N; i++) {
      int pos = dp[d][i];  // 次の位置 穴iから2^d日後の場所
      dp[d + 1][i] = dp[d][pos];
      // 穴iから2^d+1日後の場所 =
      // 穴iから2^d日後の場所から2^d日後の場所
      // 穴iから2^3日後の場所=穴iから2^2日後の場所 の2^2日後の場所
      // 穴iから2日後の場所=穴iから1日後の場所 の1日後の場所
      // 穴iから4日後の場所=穴iから2日後の場所 の2日後の場所
    }
  }
  // print dp
  // for (int d = 0; d < 8; d++) {
  //   for (int i = 1; i <= N; i++) {
  //     cout << dp[d][i] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < Q; i++) {
    int X, Y;
    cin >> X >> Y;  // いま穴 X にいるとき、Y 日後にはどの穴にいるか？
    int pos = X;
    for (int d = 31; d >= 0; d--) {
      // if ((Y / (1 << d)) % 2 == 1) {
      if ((Y >> d) & 1) {
        // cout << "pos: " << pos << ", day: " << (1 << d) << endl;
        pos = dp[d][pos];
      }
    }
    cout << pos << endl;
  }
}