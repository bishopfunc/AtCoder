#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int C1[N + 1], C2[N + 1], S1[N + 1], S2[N + 1];
  fill(C1, C1 + N + 1, 0);
  fill(C2, C2 + N + 1, 0);
  S1[0] = 0;
  S2[0] = 0;
  for (int i = 1; i <= N; i++) {
    int C, P;
    cin >> C >> P;
    if (C == 1) C1[i] = P;
    else if (C == 2) C2[i] = P;
  }
  for (int i = 1; i <= N; i++) {
    S1[i] = S1[i - 1] + C1[i];
    S2[i] = S2[i - 1] + C2[i];
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << S1[R] - S1[L - 1] << " " << S2[R] - S2[L - 1] << endl;
  }
}