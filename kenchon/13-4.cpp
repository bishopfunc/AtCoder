#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

using Graph = vector<vector<int>>;
vector<bool> seen;

void dfs(const Graph &G, int v) {
  seen[v] = true; //訪問済み
  for (auto next_v: G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v); //再帰的
  }
}

int main() {
  int N, M; //頂点と辺
  int s, t; //頂点s,t
  cin >> N >> M;
  cin >> s >> t;
  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }
  seen.assign(N, false);
  
  dfs(G, s);
  if (seen[t]) cout << "Yes" << endl;
  else cout << "No" << endl;
}