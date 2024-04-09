#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
using Graph = vector<vector<int>>;
typedef long long ll;

int N;
vector<ll> w;
Graph G;
vector<int> dp1, dp2;

void dfs(int v, int p = -1) {
  // 隣接要素を順番に探索
  for (auto ch: G[v]) {
    if (ch == p) continue; //根ならスキップ
    dfs(ch, v);
  }
  // 帰りがけに動的計画法
  for (auto ch: G[v]) {
    if (ch == p) continue;
    dp1[v] += max(dp1[ch], dp2[ch]);
    dp2[v] += dp1[ch];
  }
}

int main() {
  cin >> N; //木の辺数は頂点N-1
  w.resize();
  G.clear(); G.resize(N); //globalとして管理するため
  rep(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int root = 0; //仮に頂点0を根とする
  dp1.assign(N, 0);
  dp2.assign(N, 0);
  dfs(root);

  cout << max(dp1[root], dp2[root]) << endl;
}