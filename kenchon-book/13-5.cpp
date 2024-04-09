#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
vector<int> color;
using Graph = vector<vector<int>>;
bool dfs(Graph &G, int v, int cur_c) {
  color[v] = cur_c; //色を代入
  for (auto next_v: G[v]) {
    if (color[next_v] != -1) { //探索済み
      if (color[next_v] == cur_c) return false; //隣接と同じ色
      continue; //skip
    }
    if (!dfs(G, next_v, 1 - cur_c)) return false; //flaseを返すならfalseを返す
    // 1-0=1, 1-1=0
  }
  return true;
}

int main() {
  int N, M; //頂点と辺
  cin >> N >> M;
  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool is_bipartite = true;
  color.assign(N, -1);
  rep(v, 0, N) {
    if (color[v] != -1) continue;
    if (!dfs(G, v, 0)) is_bipartite = false; //falseが返ったらfalseを返す
  }  
  if (is_bipartite) cout << "Yes" << endl;
  else cout << "No" << endl;
}