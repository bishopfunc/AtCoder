#include <bits/stdc++.h>
using namespace std;

// allマクロの定義
#define all(v) v.begin(), v.end()

int main() {
  vector<int> v = { 2, 3, 1 };
  sort(all(v)); // 2回配列変数名を書く必要がない
  cout << v.at(0) << endl;
}