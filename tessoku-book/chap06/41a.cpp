#include <bits/stdc++.h>
using namespace std;

bool contains(string s1, string s2) {
  if (s1.find(s2) != string::npos) {
    return true;
  }
  return false;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  // 最後の3つだけ見れば良い、それ以外は上書きされるので1個ずつだと見れる
  bool ans = false;
  if (contains(S, "RRR") || contains(S, "BBB")) ans = true;
  cout << (ans ? "Yes" : "No") << endl;
}