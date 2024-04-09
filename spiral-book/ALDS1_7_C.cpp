#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define NIL -1

struct Node {
  int p, l, r;
};
Node T[MAX_N];
vector<int> preorderArray;
vector<int> inorderArray;
vector<int> postorderArray;

// root->left->right
void preorder(int u) {
  if (u == NIL) return;
  preorderArray.push_back(u);
  preorder(T[u].l);
  preorder(T[u].r);
}

// left->root->right
void inorder(int u) {
  if (u == NIL) return;
  inorder(T[u].l);
  inorderArray.push_back(u);
  inorder(T[u].r);
}

// left->right->root
void postorder(int u) {
  if (u == NIL) return;
  postorder(T[u].l);
  postorder(T[u].r);
  postorderArray.push_back(u);
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
    // cout << "id = " << id << ", p = " << T[id].p << ", l = " << T[id].l
    //  << ", r = " << T[id].r << endl;
  }

  // 根を探す
  int root = NIL;
  for (int i = 0; i < n; i++) {
    if (T[i].p == NIL) {
      root = i;
      break;
    }
  }

  // cout << "root = " << root << endl;
  preorder(root);
  inorder(root);
  postorder(root);

  cout << "Preorder" << endl;
  for (int i = 0; i < n; i++) {
    cout << " ";
    cout << preorderArray[i];
  }
  cout << endl;

  cout << "Inorder" << endl;
  for (int i = 0; i < n; i++) {
    cout << " ";
    cout << inorderArray[i];
  }
  cout << endl;

  cout << "Postorder" << endl;
  for (int i = 0; i < n; i++) {
    cout << " ";
    cout << postorderArray[i];
  }
  cout << endl;
}
