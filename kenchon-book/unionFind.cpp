#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

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
  UnionFind uf(7);
  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(5, 6);
  cout << uf.issame(1, 3) << endl;
  cout << uf.issame(2, 5) << endl;

  uf.unite(1, 6);
  cout << uf.issame(2, 5) << endl;
}