#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10001
#define DEF 24

int main() {
  int D, N;
  cin >> D >> N;
  int L[MAX_N], R[MAX_N], H[MAX_N];
  int lim[D + 1];
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i] >> H[i];
  }

  fill(lim, lim + D + 1, DEF);
  for (int i = 0; i < N; i++) {
    for (int d = L[i]; d <= R[i]; d++) {
      lim[d] = min(lim[d], H[i]);
    }
  }
  int sum = 0;
  for (int d = 1; d <= D; d++) {
    sum += lim[d];
  }
  cout << sum << endl;
}
