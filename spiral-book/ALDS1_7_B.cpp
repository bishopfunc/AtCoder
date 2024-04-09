#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define NIL -1

struct Node {
  int p, l, r;
};
Node T[MAX_N];

int depth[MAX_N];   // 深さを格納する配列
int height[MAX_N];  // 高さを格納する配列

// 根からuまでの深さを計算
void calcDepth(int u, int d) {
  if (u == NIL) return;
  depth[u] = d;
  calcDepth(T[u].l, d + 1); // ++dにすると
  calcDepth(T[u].r, d + 1); // 上の再帰から戻ったときにdが変わってしまう
}

// uから葉までの高さを計算
int calcHeight(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].l != NIL) h1 = calcHeight(T[u].l) + 1;
  if (T[u].r != NIL) h2 = calcHeight(T[u].r) + 1;
  int h = max(h1, h2);
  return height[u] = h;  // hを返すときにheightにも格納
}

// 兄弟のノードを返す
int getSibling(int u) {
  int p = T[u].p;
  if (p == NIL) return NIL;
  if (T[p].l != NIL && T[p].l != u) return T[p].l;
  if (T[p].r != NIL && T[p].r != u) return T[p].r;
  return NIL;
}

// 子の数を返す
int getChild(int u) {
  int deg = 0;
  if (T[u].l != NIL) deg++;
  if (T[u].r != NIL) deg++;
  return deg;
}

int main() {
  // 初期化
  for (int i = 0; i < MAX_N; i++) {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  int n;
  cin >> n;
  int id, l, r;
  for (int i = 0; i < n; i++) {
    cin >> id >> l >> r;
    T[id].l = l;
    T[id].r = r;
    if (l != NIL) T[l].p = id;
    if (r != NIL) T[r].p = id;
  }
  // 根を探す
  int root = NIL;
  for (int i = 0; i < n; i++) {
    if (T[i].p == NIL) {
      root = i;
      break;
    }
  }

  calcDepth(root, 0);
  calcHeight(root);

  // 結果を出力
  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].p << ", ";
    cout << "sibling = " << getSibling(i) << ", ";
    cout << "degree = " << getChild(i) << ", ";
    cout << "depth = " << depth[i] << ", ";
    cout << "height = " << height[i] << ", ";

    if (T[i].p == NIL) {
      cout << "root";
    } else if (T[i].l == NIL && T[i].r == NIL) {
      cout << "leaf";
    } else {
      cout << "internal node";
    }
    cout << endl;
  }
}
