#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e9 + 7)

// dp[i] 桁数の和が iの場合
// dp[9]の一歩手前は 左の桁1~9を選ぶ
// 1を選ぶなら桁の和は8 つまりdp[8]から遷移する
// dp[9]は dp[0]~dp[8]の合計 1~9を選ぶため
// dp[0] 0 (0桁は0)
// dp[1] 1 (dp[0]から1を選ぶ)
// dp[2] 11 2 (dp[0]から2を選ぶ, dp[1]から1を選ぶ)
// dp[3] 111 12 21 3 (dp[0]から3を選ぶ, dp[1]から2を選ぶ, dp[2]から1を選ぶ)

int main() {
  ll K;
  cin >> K;
  vector<ll> dp(K + 1, 0);
  if (K % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
        dp[i] %= mod;
        if (dp[i] < 0) dp[i] += mod;
      }
    }
  }
  cout << dp[K] << endl;
}