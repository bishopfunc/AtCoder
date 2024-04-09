#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
vector<int> G[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

void bfs(int u) {
  queue<int> Q;
  Q.push(u);
  dist[u] = 0;
  visited[u] = true;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : G[u]) {
      if (visited[v]) continue;
      visited[v] = true;
      dist[v] = dist[u] + 1;
      Q.push(v);
    }
  }
}

int main() {
  int N, M;
  int a, b;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= N; i++) {
    dist[i] = -1;
    visited[i] = false;
  }
  bfs(1);  // 1-indexed
  for (int i = 1; i <= N; i++) {
    cout << dist[i] << endl;
  }
}