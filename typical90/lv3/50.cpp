#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e9 + 7)

// 漸化式を考える
//  i = 0 dp[i] = 1 // 最初は1通り
//  1 <= i < L dp[i] = dp[i-1]
//  i >= L dp[i] = dp[i-1] + dp[i-L]
// 最後の1手から考える dpはN通りの合計 3手前の1(1通り)+2(2通り)が3を作る方法

int main() {
  int N, L;
  cin >> N >> L;
  int dp[N + 1];
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    if (i >= L) dp[i] = (dp[i - 1] + dp[i - L]) % mod;
    else dp[i] = dp[i - 1];
  }
  cout << dp[N] % mod << endl;
}