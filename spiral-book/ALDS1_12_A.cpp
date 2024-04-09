#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define INF (int)1e9
#define NIL -1

// Minimum Spanning Tree 最小全域木
// Prim's algorithm プリム法

int G[MAX_N][MAX_N];  // 隣接行列
int parent[MAX_N];    // 親ノードを格納する配列
int dist[MAX_N];      // 頂点からの最小距離を格納する配列
vector<int> T;        // 最小全域木の頂点集合
int n;                // 頂点数

// vectorにxが含まれているかどうかを判定する
bool contains(vector<int>& vec, int x) {
  return find(vec.begin(), vec.end(), x) != vec.end();
}

void prim() {
  int s = 0;  // 適当な頂点をスタート地点にする
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
    T.push_back(u);       // MSTに追加

    // 隣接する頂点のdistを更新
    for (int v = 0; v < n; v++) {
      if (G[u][v] == INF) continue;  // u から v に辺がない場合はスキップ
      if (contains(T, v)) continue;  // MSTに含まれる頂点はスキップ
      if (G[u][v] < dist[v]) {
        dist[v] = G[u][v];
        parent[v] = u;  // 親の設定
      }
    }
  }
}
int main() {
  int x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      G[i][j] = (x == NIL) ? INF : x;
    }
  }
  prim();
  int sum = 0;
  for (int i = 0; i < T.size(); i++) {
    sum += dist[T[i]];
  }
  cout << sum << endl;
}
// 閉路を形成=MSTに同じ辺が含まれる