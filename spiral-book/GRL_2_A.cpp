#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
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

class Edge {
 public:
  int source, target, weight;
  Edge() {}
  Edge(int source, int target, int weight)
      : source(source), target(target), weight(weight) {}
  bool operator<(const Edge &e) const { return weight < e.weight; }
};

int kruskal(vector<Edge> edges) {
  vector<Edge> MST;                  // 最小全域木
  sort(edges.begin(), edges.end());  // 昇順にソート
  int n = edges.size();
  DisjointSet ds = DisjointSet(n + 1);  // 頂点数 = 辺数+1
  for (auto edge : edges) {
    // 同じ集合じゃない=閉路ができない->MSTに追加
    if (!ds.same(edge.source, edge.target)) {
      ds.unite(edge.source, edge.target);
      MST.push_back(edge);
    }
  }
  int sum = 0;
  for (auto edge : MST) {
    sum += edge.weight;
  }
  return sum;
}

int main() {
  int v, e;
  cin >> v >> e;
  int source, target, weight;
  vector<Edge> edges;
  for (int i = 0; i < e; i++) {
    cin >> source >> target >> weight;
    Edge edge = Edge(source, target, weight);
    edges.push_back(edge);
  }
  cout << kruskal(edges) << endl;
}