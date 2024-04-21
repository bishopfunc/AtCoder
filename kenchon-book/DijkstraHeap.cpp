#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) \
  for (int i = (s); i < (int)(n); i++)  // rep(i, 0, N) cin >> D[i]
#define all(v) v.begin(), v.end()       // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
struct Edge {
  int to;  // 隣接頂点番号
  ll weight;
  Edge(int _to, ll _w) : to(_to), weight(_w) {}
};
using Graph = vector<vector<Edge>>;
const ll INF = 1LL << 60;

template <class T>
bool chmin(T& a, T b) {
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
  vector<ll> dist(N);
  dist[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  que.push(make_pair(dist[s], s));

  // Dijkstra
  while (!que.empty()) {
    int v = que.top().second();
    ll d = que.top().first();
    que.pop();

    if (d > dist[v]) continue;  // 込み
    for (auto e : G[v]) {       // 隣接対象
      if (chmin(dist[e.to], dist[v]))
        que.push(make_pair(dist[e.to], e.to));  // dist更新したら、queに追加
    }
  }

  rep(v, 0, N) {
    if (dist[v] < INF) cout << dist[v] << endl;
    else cout << "INF" << endl;
  }
}