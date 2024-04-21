#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 100000

// https://hcpc-hokudai.github.io/archive/graph_scc_001.pdf#page=206.00

// STEP
// DFS1 訪問してない点を探索 帰りがけで追加
// 逆順
// DFS2 番号が大きい点を探索
// 通れた部分を連結成分に追加 未探索をDFS2

// 逆順にするのは 自分より大きいノードに行かないため
// 強連結は逆順にしても強連結

vector<int> G[MAX_N];   // グラフ
vector<int> rG[MAX_N];  // 逆グラフ
vector<int> path;       // 帰りがけで作成した経路
bool visited[MAX_N];    // 訪問済み
int group[MAX_N];       // 各点がどのに強連結属するか
map<int, int> m;        // グループkeyの個数val
void dfs1(int v) {
  visited[v] = true;
  for (auto& u : G[v]) {
    if (!visited[u]) dfs1(u);
  }
  path.push_back(v);  // 帰りがけ
}
void dfs2(int v, int g) {
  visited[v] = true;
  group[v] = g;
  m[g]++;
  for (auto& u : rG[v]) {
    if (!visited[u]) dfs2(u, g);
  }
}

// 返り値は連結成分の数
int scc(int N) {
  // dfs1
  fill(visited, visited + MAX_N, false);
  // 連結してない場合もあるから、forで回す
  for (int v = 0; v < N; v++) {
    if (!visited[v]) dfs1(v);
  }
  // dfs2
  int g = 0;  // グループid
  fill(visited, visited + MAX_N, false);
  // 番号が大きい順に
  for (int i = N - 1; i >= 0; i--) {
    int v = path[i];  // pathの大きい順
    if (!visited[v]) {
      dfs2(v, g);
      g++;  // 連結してない時だけグループを増やす
    }
  }
  return g;
}

int main() {
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    rG[t].push_back(s);  // 逆順
  }
  // cout << scc(N) << endl;
  scc(V);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v;
    cin >> u >> v;
    if (group[u] == group[v]) cout << 1 << endl;
    else cout << 0 << endl;
  }
}