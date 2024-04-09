#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define NIL -1
enum { UNVISITED, VISITING, VISITED };

int dist[MAX_N] = {};              // 距離 // 0-indexed
int states[MAX_N] = {};            // 状態 // 0-indexed
int G[MAX_N + 1][MAX_N + 1] = {};  // 隣接行列 // 0-indexed

void bfs(int r) {
  // 初期化
  queue<int> Q;
  Q.push(r);
  states[r] = VISITING;
  dist[r] = 0;
  while (!Q.empty()) {
    // 1. キューの先頭を取り出し訪問完了
    int u = Q.front();
    Q.pop();
    states[u] = VISITED;
    // 2. uに隣接する未訪問の頂点をキューに追加 距離を記録
    for (int v = 0; v < MAX_N; v++) {
      if (G[u][v] && states[v] == UNVISITED) {
        Q.push(v);
        states[v] = VISITING;
        dist[v] = dist[u] + 1;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  int u, k, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--;  // 0-indexedに変換
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;          // 0-indexedに変換
      G[u][v] = 1;  // 0-indexedの隣接行列
    }
  }
  // 初期化
  for (int i = 0; i < MAX_N; i++) {
    dist[i] = NIL;
    states[i] = UNVISITED;
  }
  bfs(0);
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << dist[i] << endl;
  }
}