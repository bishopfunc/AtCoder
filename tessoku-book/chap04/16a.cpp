#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100002
#define INF (int)1e9

int dp[MAX_N];

int main() {
  int N;
  cin >> N;
  fill(dp, dp + MAX_N, INF);
  int A[N + 1], B[N + 1];
  for (int i = 2; i <= N; i++) cin >> A[i];  // A_2~N
  for (int i = 3; i <= N; i++) cin >> B[i];  // B_3~N
  dp[1] = 0;
  dp[2] = A[2];
  for (int i = 3; i <= N; i++) {
    dp[i] = min({dp[i], dp[i - 1] + A[i], dp[i - 2] + B[i]});
  }
  cout << dp[N] << endl;
}