#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 100001
#define INF (int)1e9
vector<pair<int, int>> G[MAX_N];  // 距離, 頂点
int dist[MAX_N];
bool visited[MAX_N];

// 1-K と N-K でやれば良い

void dijkstra(int s) {
  fill(dist, dist + MAX_N, INF);
  fill(visited, visited + MAX_N, false);
  priority_queue<pair<int, int>> PQ;
  PQ.push(make_pair(0, s));
  dist[s] = 0;
  while (!PQ.empty()) {
    int u = PQ.top().second;
    PQ.pop();
    if (visited[u]) continue;
    visited[u] = true;
    // 今訪問した頂点 u から到達可能な頂点 v について、dist[v] を更新
    for (auto g : G[u]) {
      int d = -g.first;
      int v = g.second;
      if (dist[u] + d < dist[v]) { dist[v] = dist[u] + d; }
      PQ.push(make_pair(-dist[v], v));
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    G[A].push_back(make_pair(-C, B));
    G[B].push_back(make_pair(-C, A));
  }
  int dist_1_to_K[MAX_N];  // 1-K
  dijkstra(1);
  for (int k = 1; k <= N; k++) { dist_1_to_K[k] = dist[k]; }
  int dist_N_to_K[MAX_N];  // N-K
  dijkstra(N);
  for (int k = 1; k <= N; k++) { dist_N_to_K[k] = dist[k]; }
  for (int k = 1; k <= N; k++) {
    cout << dist_1_to_K[k] + dist_N_to_K[k] << endl;
  }
}