// 半分全列挙
// https://algo-logic.info/split-and-list/

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1001
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

int main() {
  int N, K;  // N 10^9
  cin >> N >> K;

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  for (int i = 0; i < N; i++) cin >> D[i];

  vector<int> P(N * N), Q(N * N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      P[i * N + j] = A[i] + B[j];
      Q[i * N + j] = C[i] + D[j];
    }
  }
  sort(Q.begin(), Q.end());
  bool ans = false;
  for (int i = 0; i < N * N; i++) {
    int key = K - P[i];
    // 範囲 && keyかどうかの確認が必要
    auto iter = lower_bound(Q.begin(), Q.end(), key);
    if (iter != Q.end() && *iter == key) {
      ans = true;
      break;
    }
    //   int pos = lower_bound(Q.begin(), Q.end(), key) - Q.begin();
    //   if (0 <= pos && pos < N * N && Q[pos] == key) {
    //     ans = true;
    //     break;
    //   }
  }
  cout << (ans ? "Yes" : "No") << endl;
}
