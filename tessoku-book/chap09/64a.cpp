#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define INF 1e9
vector<pair<int, int>> G[MAX_N];  // 距離, 頂点

int dist[MAX_N];
bool visited[MAX_N];

void dijkstra(int s) {
  priority_queue<pair<int, int>> PQ;
  PQ.push(make_pair(0, s));
  dist[s] = 0;
  while (!PQ.empty()) {
    // 未訪問の頂点のうち、dist が最小の頂点を探す
    int u = PQ.top().second;
    PQ.pop();
    if (visited[u]) continue;
    visited[u] = true;
    // 今訪問した頂点 u から到達可能な頂点 v について、dist[v] を更新
    for (auto g : G[u]) {
      int d = -g.first;
      int v = g.second;
      if (dist[u] + d < dist[v]) {
        dist[v] = dist[u] + d;
      }
      PQ.push(make_pair(-dist[v], v));
    }
  }
}

int main() {
  int N, M;
  int a, b, c;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    G[a].push_back(make_pair(-c, b));
    G[b].push_back(make_pair(-c, a));
  }
  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
    visited[i] = false;
  }
  dijkstra(1);  // 1-indexed
  for (int i = 1; i <= N; i++) {
    if (dist[i] == INF) cout << -1 << endl;
    else cout << dist[i] << endl;
  }
}