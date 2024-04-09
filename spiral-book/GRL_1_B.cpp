#include <bits/stdc++.h>
using namespace std;
#define MAX_V 1000
#define INF (int)1e9
int dist[MAX_V];
int V, E;
vector<pair<int, int>> G[MAX_V];  // (to, cost)
// https://dai1741.github.io/maximum-algo-2012/docs/shortest-path/
//  V-1回更新し、各頂点からの最短距離を更新する=全部の辺を見るでもいい
//  負の閉路が存在する場合はtrueを返す
//  N-1回で変わらなくなる、N-1回目に変わる場合は負の閉路が存在する
bool bellman_ford(int s) {
  fill(dist, dist + MAX_V, INF);
  dist[s] = 0;
  for (int i = 0; i < V; i++) {
    for (int u = 0; u < V; u++) {
      for (auto g : G[u]) {
        int v = g.first;
        int d = g.second;
        if (dist[u] != INF && dist[v] > dist[u] + d) {
          dist[v] = dist[u] + d;
          if (i == V - 2) return true;
          // 0-indexedなのでV-2
        }
      }
    }
  }
  return false;
}

int main() {
  int r;
  cin >> V >> E >> r;
  int s, e, d;
  for (int i = 0; i < E; i++) {
    cin >> s >> e >> d;
    G[s].push_back(make_pair(e, d));
  }
  if (bellman_ford(r)) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    for (int i = 0; i < V; i++) {
      if (dist[i] == INF) {
        cout << "INF" << endl;
      } else {
        cout << dist[i] << endl;
      }
    }
  }
}