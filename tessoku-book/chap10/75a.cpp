#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef long long ll;
#define MAX_TIME 1440

// 貪欲的に終了時間が早い順に解く
// dp[i][j] i番目の問題まで見終わった時、j分かかった時の 問題数

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> TD(N);  // 締め切り 時間
  for (int i = 0; i < N; i++) { cin >> TD[i].second >> TD[i].first; }
  // 締め切りで昇順ソート
  sort(TD.begin(), TD.end());
  int T[N + 1], D[N + 1];  // dpのiは1~なので 1-indexにする
  for (int i = 1; i <= N; i++) {
    T[i] = TD[i - 1].second;
    D[i] = TD[i - 1].first;
  }

  // 初期化
  int dp[N + 1][MAX_TIME + 1];
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= MAX_TIME; j++) { dp[i][j] = -INF; }
  }
  dp[0][0] = 0;  // 0分0問目 0問
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= MAX_TIME; j++) {
      // j - T[i] <= D[i] 開始前は終了時間以前
      // j <= D[i] 完了後も終了時間以前
      if (T[i] <= j && j <= D[i])
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + 1);
        // max dp[i] じゃなくて dp[i-1]
      else dp[i][j] = dp[i - 1][j];
      // 何もしない or T秒前から遷移
      // jは問題を解く時間以上 && jはDより早い(Tかけた上で)
    }
  }
  int ans = 0;
  for (int j = 0; j <= MAX_TIME; j++) { ans = max(ans, dp[N][j]); }
  // 貪欲で早い終了時間順にやると良い
  // 時間によってはi-1をやるとiがやれない場合もある 何もしないほうがいい場合も
  // dp[N][MAX_TIME]は答えじゃない ちょうどMAX_TIMEに終わらないと0の場合もある
  cout << ans << endl;
}