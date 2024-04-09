#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define INF (int)1e9
#define NIL -1

// Single Source Shortest Path 単一始点最短経路
// Djikstra's algorithm ダイクストラ法

int G[MAX_N][MAX_N];  // 隣接行列
int parent[MAX_N];    // 親ノードを格納する配列
int dist[MAX_N];      // 頂点からの最小距離を格納する配列
vector<int> T;        // 最短経路木
int n;                // 頂点数

// vectorにxが含まれているかどうかを判定する
bool contains(vector<int>& vec, int x) {
  return find(vec.begin(), vec.end(), x) != vec.end();
}

// スタート地点からの最短経路を求める
void dijkstra(int s) {
  for (int v = 0; v < n; v++) {
    parent[v] = NIL;
    dist[v] = INF;
  }
  dist[s] = 0;
  while (true) {
    int u = NIL;
    int minv = INF;
    for (int v = 0; v < n; v++) {
      // T に含まれない頂点のうち、dist が最小の頂点を探す
      if (contains(T, v)) continue;
      if (dist[v] < minv) {
        minv = dist[v];
        u = v;
      }
    }

    if (u == NIL) break;  // もう未訪問の頂点がない場合は終了
    T.push_back(u);       // SSTに追加 (最短経路木)

    // 隣接する頂点のdistを更新
    for (int v = 0; v < n; v++) {
      if (G[u][v] == INF) continue;  // u から v に辺がない場合はスキップ
      if (contains(T, v)) continue;  // SSTに含まれる頂点はスキップ
      if (G[u][v] + dist[u] < dist[v]) {
        dist[v] = G[u][v] + dist[u];
        // cout << "dist[" << v << "] = " << dist[v] << endl;
        parent[v] = u;  // 親の設定
      }
    }
  }
}
int main() {
  int u, k, c, v, x;
  cin >> n;
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      G[i][j] = INF;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      G[u][v] = c;
    }
  }
  dijkstra(0);
  sort(T.begin(), T.end());
  for (int i = 0; i < T.size(); i++) {
    cout << T[i] << " " << dist[T[i]] << endl;
  }
}
