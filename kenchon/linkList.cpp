#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

struct Node {
  Node* next;
  string name;

  Node(string name_ = "") : next(NULL), name(name_) {}   
  // 引数ありならname_, なしなら""
};

// 番兵, Node型の適当な変数
Node* nil;

// 初期化
void init() {
  nil = new Node();
  nil->next = nil;
}

// 表示
void printList() {
  for (Node* cur = nil->next; cur != nil; cur = cur->next) {
    cout << cur->name << " -> ";
  }
  cout << endl;
}

// 挿入
void insert(Node *v, Node* p = nil) {
  v->next = p->next; //vの次をnilにする
  p->next = v;  //nilにvを代入
}

int main() {
  init();
  vector<string> names = {"A", "B", "C", "D", "E", "F"};

  for (int i = 0; i < (int)names.size(); i++) {
    Node* node = new Node(names[i]);
    insert(node);
    cout << "step" << i << ": ";
    printList();
  }
}