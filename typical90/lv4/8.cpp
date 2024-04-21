// dp[i][なんらかの状態] i番目まで見てなんらかの状態になる
// dp[i][j] i番目の文字まで見て atcoderのj番目まで作れる場合の数
// https://qiita.com/wihan23/items/7cc09d56bc0ea6444313
// https://drken1215.hatenablog.com/entry/2022/04/01/121700
// この図がわかりやすい
// 行けるルートを考える 何通りあるかは前のものを継承する
// aa なら2通りが伝播する
// aattt なら6通りが伝播する
// // S[i] を選ばない場合
// dp[i+1][j] = dp[i][j];

// // S[i] を選ぶ場合 (T = "atcoder" とする)
// すでにatcodが完成  attcoにdを追加 or attcodにdを追加
// if (S[i] == T[j]) {
//     dp[i+1][j+1] += dp[i][j];
// }

//   dp[i+1][j+1] = dp[i][j] + dp[i][j+1]
//   dp[i+1][j+1] = dp[i][j+1]

// aatctでat 4
// aatctでatc 2
// aatctcでatc 6
// 1文字増やしても 通り数は累積するだけ jとj+1でcを選ばないパターンを分ける
// 選ぶ or 選ばない がnapsackDP

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e9 + 7)

int main() {
  ll N;
  cin >> N;
  string S, T = "atcoder";
  cin >> S;
  int dp[N + 1][8];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= 7; j++) { dp[i][j] = 0; }
  }
  dp[0][0] = 1;  // 文字0をSの0番目を選んで作る通り 1 選ばない?
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 7; j++) {
      // atcoder 0~6 2ルート
      if (S[i] == T[j] && j < 7) {
        dp[i + 1][j + 1] = (dp[i][j] + dp[i + 1][j + 1]) % mod;
        if (dp[i + 1][j + 1] < 0) dp[i + 1][j + 1] += mod;
      }
      dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % mod;
      if (dp[i + 1][j] < 0) dp[i + 1][j] += mod;
    }
  }
  cout << dp[N][7] << endl;
}