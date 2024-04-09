#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000

class UnionFind {
 public:
  int n;
  int par[MAX_N], size[MAX_N];  // 親, 頂点の数
  UnionFind(int n) : n(n) {}
  // 初期化
  void init() {
    for (int i = 1; i <= n; i++) {
      par[i] = -1;
      size[i] = 1;
    }
  }

  // rootを返す
  int root(int u) {
    if (par[u] == -1) return u;
    return par[u] = root(par[u]);
  }

  // union by size
  void unite(int u, int v) {
    if (same(u, v)) return;
    u = root(u);
    v = root(v);
    if (size[u] < size[v]) {
      par[u] = v;
      size[v] += size[u];
    } else {
      par[v] = u;
      size[u] += size[v];
    }
  }

  // 一致
  bool same(int u, int v) { return root(u) == root(v); }
};

int main() {
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N);
  uf.init();
  int query, u, v;
  for (int i = 0; i < Q; i++) {
    cin >> query >> u >> v;
    if (query == 1)
      uf.unite(u, v);
    else if (query == 2) {
      if (uf.same(u, v))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
