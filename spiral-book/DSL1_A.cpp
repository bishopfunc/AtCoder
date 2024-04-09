#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
 public:
  vector<int> parent, rank;
  DisjointSet() {}
  DisjointSet(int size) {
    parent.resize(size, 0);
    rank.resize(size, 0);
    for (int i = 0; i < size; i++) makeSet(i);
  }

  // 集合を作る
  void makeSet(int x) {
    parent[x] = x;
    rank[x] = 0;
  }

  // x が属する集合の代表元を返す 自分が代表元なら自分を返す
  int findSet(int x) {
    if (x != parent[x]) {
      parent[x] = findSet(parent[x]);
    }
    return parent[x];
  }

  // Union by Rank
  // 経路圧縮 大きい木に小さい木をつなげる
  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[x] = y;
      rank[y]++;
    }
  }

  // xとyが属する集合を併合
  void unite(int x, int y) { link(findSet(x), findSet(y)); }

  // x と y が同じ集合に属するかどうかを判定
  bool same(int x, int y) { return findSet(x) == findSet(y); }
};

int main() {
  int n, q;
  cin >> n >> q;
  DisjointSet ds = DisjointSet(n);
  int command, x, y;
  for (int i = 0; i < q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      ds.unite(x, y);
    } else if (command == 1) {
      if (ds.same(x, y)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}