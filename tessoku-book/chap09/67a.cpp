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

int A[MAX_N], B[MAX_N], C[MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  int a, b, c;
  vector<pair<int, int>> G;
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    G.push_back(make_pair(C[i], i));
  }
  sort(G.begin(), G.end());
  UnionFind uf(N);
  uf.init();
  int total = 0;
  for (int i = 0; i < G.size(); i++) {
    int id = G[i].second;
    if (!uf.same(A[id], B[id])) {
      uf.unite(A[id], B[id]);
      total += C[id];
    }
  }
  cout << total << endl;
}