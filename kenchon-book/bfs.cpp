#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
using Graph = vector<vector<int>>;

// s startの位置
vector<int> bfs(Graph &G, int s) {
  int N = (int)G.size();
  vector<int> dist(N, -1); //-1なら未探索

  dist[s] = 0; //スタート地点の距離を0
  
  queue<int> que;
  que.push(s);

  while (!que.empty()) {
    int x = que.front(); //キューから取得
    que.pop();

    for (auto v: G[x]) {
      if (dist[v] != -1) continue;
      
      que.push(v); //キューに追加
      dist[v] = dist[x] + 1; //xの位置に1を足す
    }
  }

  return dist;
}

int main() {
  int N, M;
  cin >> N >> M;

  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist = bfs(G, 0);
  rep(v, 0, N) cout << v << ": " << dist[v] << endl;
}