// bitDP

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9

int main() {
  int N, M;
  cin >> N >> M;
  int A[M + 1][N + 1];
  vector<int> available_coupon(M + 1, 0);
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
      if (A[i][j] == 1) available_coupon[i] |= (1 << (j - 1));
    }
  }
  vector<vector<ll>> dp((M + 1), vector<ll>(1 << N, INF));
  // i番目のクーポンまで見て、j集合の商品を買うときの最小コスト NG
  // i番目のクーポンまで見て、j集合の商品を買う 最小クーポン数

  dp[0][0] = 0;  // 0番目のクーポンで商品ゼロの最小コストは0
  for (int i = 1; i <= M; i++) {
    int mask = available_coupon[i];
    for (int bit = 0; bit < (1 << N); bit++) {
      // 商品を追加しない
      dp[i][bit] = min(dp[i - 1][bit], dp[i][bit]);
      // 商品を追加
      dp[i][bit | mask] = min(dp[i][bit | mask], dp[i - 1][bit] + 1);
      // mask | bit 集合に追加 追加されたもののみ更新
    }
  }
  ll ans = dp[M][(1 << N) - 1];
  cout << (ans == INF ? -1 : ans) << endl;
}
