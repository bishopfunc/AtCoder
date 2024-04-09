#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *p, *l, *r;
};
Node *root, *NIL;

void insert(int key) {
  Node *z = (Node *)malloc(sizeof(Node));
  z->key = key;
  z->l = NIL;
  z->r = NIL;

  Node *y = NIL;   // 木が空かどうかを判定するためのポインタ
  Node *x = root;  // 親を探すためのポインタ

  while (x != NIL) {
    y = x;  // 木が空でない場合、必ず何か代入される yが親でであり、xが子である
    // cout << x->l->key << " " << x->r->key << endl;
    if (z->key < x->key) {
      x = x->l;
    } else {
      x = x->r;
    }
  }
  z->p = y;
  if (y == NIL) {
    root = z;
  } else if (z->key < y->key) {
    y->l = z;
  } else {
    y->r = z;
  }
}

// ノードに key が含まれているかどうかを判定する
bool find(Node *u, int key) {
  while (u != NIL) {
    if (key == u->key)
      return true;
    else if (key < u->key) {
      u = u->l;
    } else {
      u = u->r;
    }
  }
  return false;
}

// ノードに key が含まれている場合、そのノードを返す
Node *getNode(Node *u, int key) {
  while (u != NIL && key != u->key) {
    if (key < u->key) {
      u = u->l;
    } else {
      u = u->r;
    }
  }
  return u;
}

// ノード u の中で最小のノードを探す
// 一番左のノードが最小のノード
Node *getMinimum(Node *u) {
  while (u->l != NIL) {
    u = u->l;
  }
  return u;
}

// 次のノードを探す
// 次に大きいノードは、右のノードの中で最小のノード
Node *getSuccessor(Node *u) {
  // if (u->r != NIL) return getMinimum(u->r);
  // getSuccessorは2つの子を持つノードに対して呼ばれる
  // 右の子が存在しない場合はない(親を辿る)
  // Node *y = u->p;
  // while (y != NIL && u == y->r) {
  //   u = y;
  //   y = y->p;
  // }
  return getMinimum(u->r);
}

void deleteNode(Node *z) {
  Node *y;  // 削除するノード
  Node *x;  // yの子
  // 1つの子が子がない場合、yにzを代入して接続する
  // 2つの子がある場合、yに次のノードを代入して接続する
  if (z->l == NIL || z->r == NIL) {
    y = z;
  } else {
    y = getSuccessor(z);
  }
  // yの子をxに代入する
  if (y->l != NIL)
    x = y->l;
  else
    x = y->r;
  // xの親をyの親にする(zの子->zの親を接続する)
  if (x != NIL) {
    x->p = y->p;
  }
  // yの親がNILの場合、yの子をrootにする(zの親->zの子を接続する)
  if (y->p == NIL) {
    root = x;
  } else if (y->p->l == y) {
    y->p->l = x;
  } else {
    y->p->r = x;
  }
  // zがyでない場合、zのキーをyのキーにする(suceessorの方)
  if (y != z) {
    z->key = y->key;
  }
  free(y);
}

void preorder(Node *u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preorder(u->l);
  preorder(u->r);
}

void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->l);
  cout << " " << u->key;
  inorder(u->r);
}

int main() {
  int n;
  cin >> n;
  int key;
  string command;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> key;
      insert(key);
    } else if (command == "delete") {
      cin >> key;
      deleteNode(getNode(root, key));
    } else if (command == "find") {
      cin >> key;
      if (find(root, key)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    } else if (command == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
}
