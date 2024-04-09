#include <bits/stdc++.h>
using namespace std;
#define MAX_N 401
#define MAX_FLOW 1000000000

struct Edge {
  int to, cap, rev;
};

class MaximumFlow {
  int size_ = 0;
  bool visited[MAX_N];
  vector<Edge> G[MAX_N];

 public:
  MaximumFlow(int N) {
    size_ = N;
    for (int i = 0; i <= size_; i++) {  //[0,N]
      G[i].clear();
      visited[i] = false;
    }
  }
  void add_edge(int a, int b, int c) {
    int Ga_size = G[a].size();
    int Gb_size = G[b].size();
    G[a].push_back(Edge{b, c, Gb_size});
    G[b].push_back(Edge{a, 0, Ga_size});  // 逆向きは0
    // a保存時のbのsizeを保存、G[G[pos][i].to][G[pos][i].rev].capでアクセス可能
  }

  // DFSで経路を探して、その経路の残余グラフの容量の最小値分流す
  // 返り値は流した量
  int dfs(int u, int g, int F) {
    if (u == g) return F;
    // ゴールなら、これまで伝わってきた最小流量を流すため、返す
    visited[u] = true;
    for (int v = 0; v < (int)G[u].size(); v++) {
      if (G[u][v].cap == 0) continue;     // 流量がゼロ
      if (visited[G[u][v].to]) continue;  // 訪問済み
      int min_flow = min(F, G[u][v].cap);
      int flow = dfs(G[u][v].to, g, min_flow);
      if (flow > 0) {
        G[u][v].cap -= flow;                     // 容量を減らす
        G[G[u][v].to][G[u][v].rev].cap += flow;  // 残余を減らす
        return flow;                             // 流した時点で返す
      }
    }
    // 流せる辺がない
    return 0;
  }
  // 頂点sからtまで最大フローの総流量を流す
  int max_flow(int s, int t, int init_flow) {
    int total_flow = 0;
    while (true) {
      // 毎度のDFSはリセットする // 1回の経路で重複しないだけ
      for (int i = 0; i < size_; i++) visited[i] = false;
      int flow = dfs(s, t, init_flow);
      if (flow == 0) break;
      total_flow += flow;
    }
    return total_flow;
  }
};

int main() {
  int N;
  cin >> N;
  MaximumFlow Z(2 * N + 2);
  // 始点付近と終点付近を区別できればよい
  // N * Nでも良いが、2Nで十分
  // i, j+N, 2N+1, 2N+2

  // 青と赤間のエッジ
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char c;
      cin >> c;
      // stringだと1行取れてしまう
      if (c == '#') Z.add_edge(i, N + j, 1);  //
    }
  }
  // 始点->青 赤->終点
  for (int i = 1; i <= N; i++) {
    Z.add_edge(2 * N + 1, i, 1);
    Z.add_edge(i + N, 2 * N + 2, 1);
  }
  cout << Z.max_flow(2 * N + 1, 2 * N + 2, MAX_FLOW) << endl;
}