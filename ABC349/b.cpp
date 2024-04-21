#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  map<int, int> m1, m2;
  for (int i = 0; i < S.size(); i++) {
    int key = S[i] - 'a';
    m1[key]++;
  }

  bool ans = true;
  for (auto &val : m1) {
    m2[val.second]++;
    // cout << val.second << endl;
  }
  for (auto &val : m2) {
    // cout << val.second << endl;
    if (val.second != 0 && val.second != 2) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}