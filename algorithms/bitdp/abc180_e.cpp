#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9

// bitDP 巡回セールスマン
// https://qiita.com/karutetto332/items/90fc8186c915afd1e9e8

int main() {
  int N;
  cin >> N;
  ll dist[N][N];
  // cout << (1 << N) << endl;
  // ll dp[(1 << N)][N];
  // 初期値 INF
  // for (int visited = 0; visited < (1 << N); visited++) {
  //   for (int v = 0; v < N; v++) { dp[visited][v] = INF; }
  // }
  vector<vector<ll>> dp((1 << N), vector<ll>(N, INF));  // vectorを利用
  // dp 訪問済み集合, 最後に訪問
  ll X[N], Y[N], Z[N];
  for (int i = 0; i < N; i++) { cin >> X[i] >> Y[i] >> Z[i]; }
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      dist[u][v] = abs(X[v] - X[u]) + abs(Y[v] - Y[u]) + max(0LL, Z[v] - Z[u]);
    }
  }
  dp[1][0] = 0LL;  // スタート0 001のbit 距離0
  // 2^N * N^2
  for (int visited = 1; visited < (1 << N); visited++) {
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) {
        // iがbitに含まれるかつ jがbitに含まれてない
        if ((visited >> u & 1) && !(visited >> v & 1)) {
          int new_visited = visited | (1 << v);  // 集合に追加
          dp[new_visited][v] =
              min(dp[new_visited][v], dist[u][v] + dp[visited][u]);
        }
      }
    }
  }
  // 全ての都市を通って vに着く最短経路
  ll ans = INF;
  for (int v = 0; v < N; v++) {
    ans = min(dp[(1 << N) - 1][v] + dist[v][0], ans);
  }
  cout << ans << endl;
}