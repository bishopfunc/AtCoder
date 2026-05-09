#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  char A[N][N], B[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) { cin >> A[i][j]; }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) { cin >> B[i][j]; }
  }
  int ans_i = 0, ans_j = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] != B[i][j]) {
        ans_i = i;
        ans_j = j;
      }
    }
  }
  cout << ans_i + 1 << " " << ans_j + 1 << endl;
}