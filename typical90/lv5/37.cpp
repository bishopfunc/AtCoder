#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define INF (ll)1e9

// セグ木DP
// dp[i][w] i番目の料理まで見て香辛料w使った時の最大の価値
// dp[i][w] = dp[i-1][w] 香辛料使わない
// dp[i][w] = max(dp[i-1][w-R]..dp[i-1][w-L]) 香辛料使う場合

// 愚直 O(N*W^2)
// RMQ O(NW + NW*log(W))
// スライド最小値 O(NW)

ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF; }

int main() {
  int N, W;
  cin >> W >> N;
  ll dp[N + 1][W + 1];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) { dp[i][j] = -INF; }
  }

  vector<segtree<ll, op, e>> rmqs(N + 1, segtree<ll, op, e>(W + 1));
  dp[0][0] = 0LL;       // 商品0 香辛料0 価値0
  rmqs[0].set(0, 0LL);  // RMQも0

  for (int i = 1; i <= N; i++) {
    int L, R;
    ll V;
    cin >> L >> R >> V;
    // 1. 香辛料なし
    for (int j = 0; j <= W; j++) { dp[i][j] = dp[i - 1][j]; }
    // 2. 香辛料あり
    for (int j = 0; j <= W; j++) {
      int l = max(j - R, 0);
      int r = max(j - L + 1, 0);  // [j-R, j-L+1)
      // cout << l << " " << r << endl;
      if (l == r) continue;  // 区間0
      ll max_v = rmqs[i - 1].prod(l, r);
      if (max_v != -INF) { dp[i][j] = max(dp[i - 1][j], max_v + V); }
    }
    // RMQにDPの値を更新
    for (int j = 0; j <= W; j++) { rmqs[i].set(j, dp[i][j]); }
    // 3段階に分けてる 12とセットは分ける必要がある
  }
  cout << (dp[N][W] == -INF ? -1 : dp[N][W]) << endl;
}