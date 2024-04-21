#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 座標圧縮 二次元verもある
// https://drken1215.hatenablog.com/entry/2021/08/09/235400
// STEP1 ソート 重複除去 => T
// STEP2 二分探索 A[i]を満たす最小のid => B
int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  // 1
  vector<int> T = A;
  sort(T.begin(), T.end());
  T.erase(unique(T.begin(), T.end()), T.end());
  // 2
  for (int i = 0; i < N; i++) {
    B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
    cout << B[i] << endl;
  }
}