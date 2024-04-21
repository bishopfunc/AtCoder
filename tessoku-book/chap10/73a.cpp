#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
#define INF (int)1e9

// 木があるところは 距離 - 1
// 距離は * 10000 N=8000 だから MAXでも距離の長短が変わることがない

int dist[MAX_N];
bool visited[MAX_N];
vector<pair<int, int>> G[MAX_N];  // 距離, 頂点

void dijkstra(int s) {
  priority_queue<pair<int, int>> PQ;
  PQ.push(make_pair(0, s));
  dist[s] = 0;
  while (!PQ.empty()) {
    int u = PQ.top().second;
    PQ.pop();
    if (visited[u]) continue;
    visited[u] = true;
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
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    G[A].push_back({-(C * MAX_N - D), B});
    G[B].push_back({-(C * MAX_N - D), A});
  }
  // 1-index
  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
    visited[i] = false;
  }
  dijkstra(1);                                   // 1-N
  int ans_dist = ceil(dist[N] / (double)MAX_N);  // 切り上げ
  int ans_tree = ans_dist * MAX_N - dist[N];  // 切り上げ * 10000 - 本当の距離
  // 2*10000-3 = 19997 1.9997 = 2
  cout << ans_dist << " " << ans_tree << endl;
}