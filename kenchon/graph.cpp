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

int main() {
  int N, M; //頂点,辺数
  cin >> N >> M;

  Graph G(N);
  rep(i, 0, M) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }
}