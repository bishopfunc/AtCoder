#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
struct Edge {
  int to; //隣接頂点番号
  ll weight;
  Edge(int _to, ll _w) : to(_to), weight(_w) {}
};
using Graph = vector<vector<Edge>>; //Edgeのリストで隣接リストを表現。。

void search(const Graph &G, int s) {
  int N = (int)G.size();
  vector<bool> seen(N, false);
  queue<int> todo;

  seen[s] = true;
  todo.push(s);

  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();
    for(int x: G[v]) {
      if (seen[x]) continue;
      seen[x] = true;
      todo.push(x);
    }
  }
  
}