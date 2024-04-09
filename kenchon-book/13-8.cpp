#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

using Graph = vector<vector<int>>;
vector<int> depth;
vector<int> subtree_size; //部分木のサイズ
 
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
  depth[v] = d;
  for (auto c: G[v]) {
    if (c == p) continue; //探索方向が親に逆流するのを防ぐ
    dfs(G, c, v, p, d); //再帰的
  }
  // 帰りがけでサイズを求める
  subtree_size[v] = 1;
  for (auto c: G[v]) {
    if (c == p) continue; //探索方向が親に逆流するのを防ぐ
    subtree_size[v] += subtree_size[c];
  }
}

int main() {
  int N; cin >> N;
  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int root = 0;
  depth.assign(N, 0);
  subtree_size.assign(N, 0);
  dfs(G, root); //0から探索
  
  rep(v, 0, N) {
    cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << endl;
  }
}