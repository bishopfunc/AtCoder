#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

struct Node {
  Node* next;
  Node* prev;
  string name;

  Node(string name_ = "") : next(NULL), prev(NULL), name(name_) {}   
  // 引数ありならname_, なしなら""
};

// 番兵, Node型の適当な変数
Node* nil;

// 初期化
void init() {
  nil = new Node();
  nil->prev = nil;
  nil->next = nil;
}

// 表示
void printList() {
  for (Node* cur = nil->next; cur != nil; cur = cur->next) {
    cout << cur->name << " -> ";
  }
  cout << endl;
}

// pのあとに挿入
void insert(Node *v, Node* p = nil) {
  v->next = p->next; //vの次をnilにする
  p->next->prev = v; //vを代入
  p->next = v;  //nilにvを代入
  v->prev = p; //vの前にp
}

// 削除
void erase(Node *v) {
  if (v == nil) return;
  v->prev->next = v->next;
  v->next->prev = v->prev;
  delete v; //メモリを解放
}

int main() {
  init();
  vector<string> names = {"A", "B", "C", "D", "E", "F"};
  Node* d;

  for (int i = 0; i < (int)names.size(); i++) {
    Node* node = new Node(names[i]);
    insert(node);
    if(names[i] == "D") d = node;
  }

  printList();
  erase(d);
  printList();
}