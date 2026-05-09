#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MAX_N 200000
#define INF (int)1e9
#define NIL -1

// Minimum Spanning Tree 最小全域木
// Prim's algorithm プリム法

vector<pair<int, ll>> G[MAX_N];  // 隣接リスト (頂点, 重み)
int parent[MAX_N];               // 親ノードを格納する配列
ll dist[MAX_N];        // 頂点からの最小距離を格納する配列
unordered_set<int> T;  // 最小全域木の頂点集合
int N, M;              // 頂点数, 辺数

void prim() {
  fill(dist, dist + N, INF);
  fill(parent, parent + N, NIL);
  int s = 0;
  parent[s] = NIL;
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.emplace(0, s);

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (T.find(u) != T.end()) continue;
    T.insert(u);

    for (auto &[v, weight] : G[u]) {
      if (T.find(v) == T.end() && weight < dist[v]) {
        dist[v] = weight;
        parent[v] = u;
        pq.emplace(dist[v], v);
      }
    }
  }
}

int main() {
  cin >> N >> M;
  dsu d(N);
  for (int i = 0; i < M; i++) {
    ll K, C;
    cin >> K >> C;
    for (int j = 0; j < K; j++) {
      int A;
      cin >> A;
      A--;
      d.merge(i, A);
      G[i].push_back({A, C});
      G[A].push_back({i, C});
    }
  }
  bool is_connected = false;
  if (d.groups().size() == 1) { is_connected = true; }
  if (!is_connected) {
    cout << -1 << endl;
    return 0;
  }
  prim();
  ll ans = 0;
  for (auto &u : T) {
    int v = parent[u];
    if (v == NIL) continue;
    ll w = INF;
    for (auto &g : G[u]) {
      if (g.first == v) { w = min(w, g.second); }
    }
    ans += w;
  }
  cout << ans << endl;
}