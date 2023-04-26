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
using Graph = vector<vector<Edge>>; 
const ll INF = 1LL << 60;

template<class T> bool chmin(T&a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N, M, s;
  cin >> N >> M >> s;
  Graph G(N);
  rep(i, 0, M) {
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }

  // Bellman-Ford
  bool exist_negative_cycle = false;
  vector<ll> dist(N, INF);
  dist[s] = 0; //スタートは0
  rep(i, 0, N) {// N-1回試行する, V-1回で頂点全部探索できる理論上
    bool update = false;
    rep(v, 0, M) { //辺の数
      if (dist[v] == INF) continue;
      for (auto e: G[v]) { //隣接対象
        if (chmin(dist[e.to], dist[v])) update = true; //0->1なら chmin(dist[1], dist[0] + w)
      }
    }
    if (!update) break; //更新しなければ試行を停止
    if (i == N - 1 && update) exist_negative_cycle = true; //最後の試行で更新したら負閉路が存在する

    if (exist_negative_cycle) cout << "negative" << endl;
    else {
      rep(v, 0, N) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
      }
    }
  }
}