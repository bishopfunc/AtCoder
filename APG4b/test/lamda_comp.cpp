#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = { 2, 3, 1 };
  // 大きい順にソートさせる比較関数
  auto comp = [](int a, int b) { return a > b; };
  sort(v.begin(), v.end(), comp);
  // sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

  cout << v[0] << endl; // v は {3, 2, 1}となっている
}
