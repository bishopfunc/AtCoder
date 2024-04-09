#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

using Graph = vector<vector<int>>;
vector<bool> seen;
vector<bool> order;

void dfs(const Graph &G, int v) {
  seen[v] = true; //訪問済み
  for (auto next_v: G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v); //再帰的
  }
  order.push_back(v); //v-outを記録する
}

int main() {
  int N, M; //頂点と辺
  cin >> N >> M;
  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }
  seen.assign(N, false);
  
  rep(v, 0, N) {
    if (seen[v]) continue;
    dfs(G, v);
  }
  reverse(all(order));
  for (auto v: order) cout << v << " -> ";
  cout << endl;
}