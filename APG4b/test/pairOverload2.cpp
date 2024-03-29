#include <bits/stdc++.h>
using namespace std;

// .second → .first の順に比較
bool operator<(pair<int, int> l, pair<int, int> r) {
  if (l.second != r.second) {
    return l.second < r.second;
  } else {
    return l.first < r.first;
  }
}
// <演算子 を用いて定義
bool operator> (pair<int, int> l, pair<int, int> r) { return r < l; } // <が呼び出されているから?
bool operator<=(pair<int, int> l, pair<int, int> r) { return !(r < l); }
bool operator>=(pair<int, int> l, pair<int, int> r) { return !(l < r); }

int main() {
  pair<int, int> a = {0, 5};
  pair<int, int> b = {3, 2};
  cout << (a < b) << endl;  // 0
  cout << (a > b) << endl;  // 1
}
