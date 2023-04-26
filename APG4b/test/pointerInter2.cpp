#include <bits/stdc++.h>
using namespace std;

int main() {
  // イテレータを用いて順番にアクセス
  vector<int> a = { 1, 2, 3 };
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << endl;
  }

  // ポインタを用いて順番にアクセス
  vector<int> b = { 1, 2, 3 };
  // b.data() ... bのデータの先頭アドレスを返す(&b[0] と同じ)
  // int *begin_addr = b.data();
  int *begin_addr = &b[0];

  // // ヒープメモリなら先頭要素を変数でアクセスできる、vectorはできない
  // uint32_t *p = new uint32_t[10];
  // uint32_t *tmp = p;  
  
  for (int *ptr = begin_addr; ptr < begin_addr + 3; ptr = ptr + 1) {
    cout << *ptr << endl;
  }
}
