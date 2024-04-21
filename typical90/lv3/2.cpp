#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// depは公式を参考
bool check(string str) {
  int dep = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') dep++;
    if (str[i] == ')') dep--;
    if (dep < 0) return false;
  }
  if (dep == 0) return true;
  return false;
}

//  ()と2種類でbit全探索して チェック
int main() {
  int N;
  cin >> N;
  string res;
  vector<string> res_list;
  if (N % 2 == 1) {
    res = "";
    cout << res << endl;
    return 0;
  } else {
    for (int bit = 0; bit < (1 << N); bit++) {
      res = "";
      for (int i = N - 1; i >= 0; i--) {
        int mask = 1 << i;
        if (bit & mask) res += '(';
        else res += ')';
      }
      // cout << bitset<2>(bit) << endl;
      // cout << res << endl;
      res_list.push_back(res);
    }
    sort(res_list.begin(), res_list.end());
    int left = 0, right = 0;
    for (auto &res : res_list) {
      if (check(res)) cout << res << endl;
    }
  }
}