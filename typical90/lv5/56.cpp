// DP復元

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp[i] i日目まで見て、総額がjの場合、買い物が可能か
// boolのDP 簡単 条件を満たしたら dp[i][j] = true

int main() {
  int N, S;
  cin >> N >> S;
  int A[N + 1], B[N + 1];
  bool ans = false;
  for (int i = 1; i <= N; i++) { cin >> A[i] >> B[i]; }

  bool dp[N + 1][S + 1];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= S; j++) { dp[i][j] = false; }
  }
  dp[0][0] = true;  // trueを伝播させる
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      if (j - A[i] >= 0 && dp[i - 1][j - A[i]]) dp[i][j] = true;
      if (j - B[i] >= 0 && dp[i - 1][j - B[i]]) dp[i][j] = true;
    }
  }

  if (dp[N][S] == false) {
    cout << "Impossible" << endl;
    return 0;
  }
  string path;
  int pos = N, sum = S;
  while (pos >= 1) {
    if (sum >= A[pos] && dp[pos - 1][sum - A[pos]]) {
      path += 'A';
      sum -= A[pos];
    } else if (sum >= B[pos] && dp[pos - 1][sum - B[pos]]) {
      path += 'B';
      sum -= B[pos];
    }
    pos--;
  }
  reverse(path.begin(), path.end());
  cout << path << endl;
  return 0;
}