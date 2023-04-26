#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

struct Heap {
  vector<int> heap;
  Heap() {};

  void push(int x) {
      heap.push_back(x); //末尾に挿入
      int cur = (int)heap.size() - 1;
      while (cur > 0) {
        int p = (cur - 1) / 2; //親
        if (heap[p] >= x) break; //すでに親の方が大きいなら何もしない
        heap[cur] = heap[p]; //
        cur = p; //上に上がるため、番兵に親を代入
      }
      heap[cur] = x; //最終位置にxを代入する
  }


  void pop() {
    if (heap.empty()) return;
    int x = heap.back(); //末尾の値を保持
    heap.pop_back();
    int cur = 0; //上から下に行く, heapの範囲内なら
    while (cur * 2 + 1 < (int)heap.size()) {
      //大きい方をchild1にする
      int child1 = cur * 2  + 1;
      int child2 = cur * 2  + 2;
      if (child2 < (int)heap.size() && heap[child2] > heap[child1]) {
        child1 = child2;
      }
      if(heap[child1] <= x) break; //すでに子の方が小さいなら何もしない
      heap[cur] = heap[child1]; 
      cur = child1; //下に下がるため、番兵に子を代入
    }
    heap[cur] = x; //適切なときにxを代入
  }

  int top() {
    if(!heap.empty()) return heap[0];
    return -1;
  }

};

int main() {
  Heap h;
  h.push(3);h.push(5);h.push(7);h.push(1);

  cout << h.top() << endl;
  h.pop();
  cout << h.top() << endl;
  h.push(11);
  cout << h.top() << endl;
  h.pop();
  cout << h.top() << endl;
}