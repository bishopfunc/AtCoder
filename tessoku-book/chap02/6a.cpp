#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> S(N + 1);  // 累積和
  S[0] = 0;
  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    S[i] = S[i - 1] + A;
  }

  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << S[R] - S[L - 1] << endl;
  }
}