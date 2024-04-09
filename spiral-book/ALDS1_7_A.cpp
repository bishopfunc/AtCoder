#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define NIL -1
struct Node {
  int parent, leftChild, rightSibling;
};
Node T[MAX_N];

int depth[MAX_N];  // 深さを格納する配列

void getDepth(int u, int d) {
  // cout << "u = " << u << ", d = " << d << endl;
  depth[u] = d;
  if (T[u].rightSibling != NIL) getDepth(T[u].rightSibling, d);
  // 兄弟の深さはそのまま
  if (T[u].leftChild != NIL) getDepth(T[u].leftChild, d + 1);
  // 子の深さは+1
}

int main() {
  // 初期化
  for (int i = 0; i < MAX_N; i++) {
    T[i].parent = T[i].leftChild = T[i].rightSibling = NIL;
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int id, k, child, prevChild = NIL;
    cin >> id >> k;
    if (k > 0) {
      for (int j = 0; j < k; j++) {
        // cout << "id = " << id << "child =" << child
        //      << "T[0].parent = " << T[0].parent << endl;
        cin >> child;
        T[child].parent = id;  // 親を登録
        // (1)

        if (j == 0) {
          // cout << "child" << endl;
          T[id].leftChild = child;  // 最初の子
        } else {
          // cout << "sibling" << endl;
          T[prevChild].rightSibling = child;  // 前の子の右兄弟に設定
        }

        // (2)
        prevChild = child;  // 前の子を更新 // (1)に書くと今の子と同じになるからダメ
      }
    }
  }

  // 根を探す
  int root = NIL;
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) {
      root = i;
      break;
    }
  }
  // cout << "root = " << root << endl;

  // 深さを求める
  getDepth(root, 0);

  // 結果を出力
  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "depth = " << depth[i] << ", ";
    if (T[i].parent == NIL) {
      cout << "root, ";
    } else if (T[i].leftChild == NIL) {
      cout << "leaf, ";
    } else {
      cout << "internal node, ";
    }
    cout << "[";
    for (int c = T[i].leftChild, t = 0; c != NIL; c = T[c].rightSibling) {
      if (t++ > 0) cout << ", ";
      cout << c;
    }
    cout << "]" << endl;
  }
}
