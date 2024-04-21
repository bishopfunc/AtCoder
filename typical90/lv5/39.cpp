#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 100000
// 答えの貢献度
// 主客転倒
// 貢献度は i * (N - i)
// (X[i+1] - X[i]) * i * (N - i)
// 自分より右の区間の数 N - i
// 自分及び左の点の数 が同じことする i
// 区間4、点5 4=6=6=4

// |A| * (N - |A|)
// |A|   自分を含む木の頂点の数=自分及び左の点
// N-|A| その他の木の頂点の数=右の区間の数
// 辺でグループを切り分ける 辺でループすれば良い
// 辺の距離 * 寄与度 = 距離の総和
// dp[i] iを頂点とする木の頂点の数 来た方向は除く

vector<ll> G[MAX_N + 1];
ll dp[MAX_N + 1];

// preの方向は除外する
void dfs(int u, int pre) {
  dp[u] = 1LL;
  for (auto &v : G[u]) {
    if (v == pre) continue;
    dfs(v, u);
    // 帰りがけ 再帰の底を計算してから
    dp[u] += dp[v];
    // 自分の1 + 子の2
  }
}

int main() {
  int N;
  cin >> N;
  int A[N], B[N];
  fill(dp, dp + MAX_N + 1, -1);
  for (int i = 1; i <= N - 1; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  dfs(1, -1);
  ll dist = 0LL;
  // for (int i = 1; i <= N; i++) { cout << dp[i] << endl; }

  for (int i = 1; i <= N - 1; i++) {
    ll nodes = min(dp[A[i]], dp[B[i]]);
    // 小さい方をとる N=nodesなら0になってしまう、辺のもう片方なら最小nodes=1
    dist += nodes * (N - nodes) * 1;
    // 本来はA[i]-B[i]の距離をかける
  }
  cout << dist << endl;
}