#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

using Graph = vector<vector<int>>;
vector<bool> seen;
vector<int> habatsu;
int max_num = 1;

void dfs(const Graph &G, int v) {
  int num = 1;
  seen[v] = true; //訪問済み
  for (auto next_v: G[v]) {
    if (seen[next_v]) {
      num++;
      max_num = max(max_num, num);
      continue;
    }
    dfs(G, next_v); //再帰的
  }
}

int main() {
  int N, M; //頂点と辺
  cin >> N >> M;
  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  seen.assign(N, false);
  habatsu.assign(N, 1);
  
  rep(v, 0, N) {
    if (seen[v]) continue;
    dfs(G, v);
  }
  cout << max_num << endl;
}