#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100002
#define INF (int)1e9
int dp[MAX_N], A[MAX_N], B[MAX_N];

// TODO

int main() {
  int N;
  cin >> N;
  fill(dp, dp + MAX_N, -INF);
  // もらうDP dp[i-1][j-1] 最後から考える
  // 配るDP dp[i+1][j+1] 次ステップを考える

  for (int i = 1; i <= N - 1; i++) cin >> A[i];
  for (int i = 1; i <= N - 1; i++) cin >> B[i];
  dp[1] = 0;  // 1-N
  for (int i = 1; i <= N - 1; i++) {
    dp[A[i]] = max(dp[A[i]], dp[i] + 100);
    dp[B[i]] = max(dp[B[i]], dp[i] + 150);
  }
  // マスi進んだ時点のスコアの最大値がDP
  cout << dp[N] << endl;
}