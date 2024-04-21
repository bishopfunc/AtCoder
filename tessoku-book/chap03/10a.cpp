#include <bits/stdc++.h>
using namespace std;

// 二方向累積和

int main() {
  int N, D;
  cin >> N;
  int A[N + 1], P[N + 1], Q[N + 1];
  for (int i = 1; i <= N; i++) { cin >> A[i]; }
  cin >> D;
  int L[D + 1], R[D + 1];
  for (int i = 1; i <= D; i++) { cin >> L[i] >> R[i]; }

  // 順方向 i部屋目まで見た時の最大人数の部屋の人数
  P[1] = A[1];
  for (int i = 2; i <= N; i++) { P[i] = max(P[i - 1], A[i]); }
  // 逆方向 i部屋目まで見た時の最大人数の部屋の人数
  Q[N] = A[N];
  for (int i = N - 1; i >= 1; i--) { Q[i] = max(Q[i + 1], A[i]); }
  // L, R が占有されるなら P[1,L-1] Q[R+1,N]のmax
  // P[L-1]に1~L-1までのmaxが累積されてる
  for (int d = 1; d <= D; d++) {
    cout << max(P[L[d] - 1], Q[R[d] + 1]) << endl;
  }
}