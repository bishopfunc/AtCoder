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
  string command;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "insert") {
      int key;
      cin >> key;
      insert(key);
    } else if (command == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
}
