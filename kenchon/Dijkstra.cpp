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

  // Dijkstra
  vector<bool> used(N, false);
  vector<ll> dist(N, INF);
  dist[s] = 0; //スタートは0
  rep(i, 0, N) {// N-1回試行する, V-1回で頂点全部探索できる理論上
    ll min_dist = INF;
    int min_v = -1;
    rep(v, 0, N) { //辺の数
     if (!used[v] && dist[v] < min_dist) 
        min_dist = dist[v];
        min_v = v;
        //min_dist, min_v候補から選び更新
        //まだ使ってないかつ,chminによって更新された隣接
        //毎回の試行で探索範囲は減る
    }
    if (min_v == -1) break; //更新されなかったらbreak
    for (auto e: G[v]) { //隣接対象
      chmin(dist[e.to], dist[v] + e.w)  //0->1なら chmin(dist[1], dist[0] + w) //dist配列を更新
    }
    used[min_v] = true;


    rep(v, 0, N) {
      if (dist[v] < INF) cout << dist[v] << endl;
      else cout << "INF" << endl;
    }
  }
}