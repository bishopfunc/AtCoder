#include <bits/stdc++.h>
using namespace std;
#define MAX_X 1001
#define MAX_Y 1001

int dp[MAX_X][MAX_Y] = {};

// 注意: 初期化が必要, 1 to m
int lcs(string s1, string s2) {
  // 初期化
  for (int i = 0; i < MAX_X; i++) dp[i][0] = 0;
  for (int j = 0; j < MAX_Y; j++) dp[0][j] = 0;
  int m = s1.size();
  int n = s2.size();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {  // 空文字を含むため-1
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
      // cout << s1 << " " << s2 << endl;
      // cout << s1[i] << " " << s2[j] << " " << dp[i][j] << endl;
    }
  }
  // for (int i = 0; i <= m; i++) {
  //   for (int j = 0; j <= n; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return dp[m][n];
}

int main() {
  int n;
  cin >> n;
  string s1, s2;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
  }
}
