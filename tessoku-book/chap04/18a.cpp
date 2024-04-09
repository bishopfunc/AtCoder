#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  int dp[N + 1][S + 1];  // i番目のカードまででjを作れるかどうか
  dp[0][0] = true;       // 0枚で0は作れる
  for (int j = 1; j <= N; j++) dp[0][j] = false;  // 0枚で何も作れない
  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    // 最後から考える
    // dp[i-1][j]のまま, Aを使ってdp[i-1][j-A]
    for (int j = 0; j <= S; j++) {
      if (j >= A) {
        if (dp[i - 1][j] == true || dp[i - 1][j - A] == true)
          dp[i][j] = true;
        else
          dp[i][j] = false;
      } else {
        if (dp[i - 1][j] == true)
          dp[i][j] = true;
        else
          dp[i][j] = false;
      }
    }
  }
  cout << (dp[N][S] ? "Yes" : "No") << endl;
}