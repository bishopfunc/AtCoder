#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1~Nしかないので 1から左から揃えていけばよい

int main() {
  int N;
  cin >> N;
  int A[N + 1], pos[N + 1];
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    pos[A[i]] = i;
  }
  int cnt = 0;
  vector<pair<int, int>> ans;
  for (int i = 1; i <= N; i++) {
    if (pos[i] != i) {
      // cout << "pos[A[i]]: " << pos[A[i]] << ", pos[i]: " << pos[i]
      //  << ", i: " << i << endl;
      ans.push_back({i, pos[i]});
      pos[A[i]] = pos[i];     // A[1]の数字の位置をpos[1]に書き換え
      swap(A[i], A[pos[i]]);  // 実際に入れ替え
      cnt++;
    }
  }
  cout << cnt << endl;
  for (auto &a : ans) { cout << a.first << " " << a.second << endl; }
}