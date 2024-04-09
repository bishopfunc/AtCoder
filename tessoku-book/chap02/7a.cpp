#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  vector<int> S(D + 1), I(D + 1);  // 累積和, 前日比
  // imos
  for (int i = 1; i <= N; i++) {
    int L, R;
    cin >> L >> R;
    I[L]++;
    I[R + 1]--;
  }
  S[0] = 0;
  for (int d = 1; d <= D; d++) {
    S[d] = S[d - 1] + I[d];
    cout << S[d] << endl;
  }
}