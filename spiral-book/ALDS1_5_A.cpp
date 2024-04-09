#include <bits/stdc++.h>
using namespace std;

int dp[21][2001] = {};

bool solve(int i, int m, const vector<int>& A) {
  if (dp[i][m] != -1) return dp[i][m];  // 既に計算済みならその結果を返す
  if (m == 0) return dp[i][m] = 1;  // mが0ならtrue
  if (i >= A.size()) return dp[i][m] = 0;
  return dp[i][m] = solve(i + 1, m, A) || solve(i + 1, m - A[i], A);
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int q, m;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> m;
    bool flag = solve(0, m, A);
    if (flag) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j <= m; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
  }
}