#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
using Edge = pair<int, pair<int,int>>;
typedef long long ll;

struct UnionFind {
  vector<int> par, siz;
  // par 親頂点の番号 n個-1
  // siz 木の頂点数 n個1
  UnionFind(int n) : par(n, -1), siz(n, 1) {};

  // 根を求める
  int root(int x) {
    if(par[x] == -1) return x; //xが根ならxを返す
    return par[x] = root(par[x]);
  }

  // x,yの根が一致するかどうか
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  // xとyを併合する
  bool unite(int x, int y) {
    x = root(x); y = root(y); //根に移動
    if (x == y) return false; //同じ根なら何もしない

    if (siz[y] < siz[x]) swap(x, y); //yのサイズが大きいならswap

    par[y] = x; //yの根をxにする
    siz[x] += siz[y];

    return true;
  }

};

int main() {
  int N, M; //頂点と辺
  cin >> N >> M;
  vector<Edge> edges(M); //辺集合
  rep(i, 0, M) {
    int u, v, w;
    cin >> u >> v >> w;
    // u, v頂点
    edges[i] = Edge(w, make_pair(u, v));
  }
  sort(all(edges)); //重みが小さい順にソート {w, {u, v}}

  ll res = 0;
  UnionFind uf(N);
  rep(i, 0, M) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (uf.issame(u, v)) continue; //閉路を形成するなら追加しない

    // u, vを結合
    // 重みを追加
    res += w;
    uf.unite(u, v);
  }
  cout << res << endl;
}