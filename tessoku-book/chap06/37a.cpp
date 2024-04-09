#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N, M, B;
  cin >> N >> M >> B;
  ll A[N], C[M];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> C[i];
  ll sum = 0;
  sum += N * M * B;
  for (int i = 0; i < N; i++) sum += A[i] * M;
  for (int i = 0; i < M; i++) sum += C[i] * N;
  cout << sum << endl;
}