#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (int)1e9
#define mod (ll)(1e9 + 7)

int main() {
  ll N, W, L, R;
  cin >> N >> W >> L >> R;
  ll X[N + 2];
  for (int i = 1; i <= N; i++) { cin >> X[i]; }
  X[0] = 0;                                  // 西の岸
  X[N + 1] = W;                              // 東の岸
  vector<ll> dp(N + 2, 0), dpsum(N + 2, 0);  // 0, X, W
  // dpsum[i] = dp[0]+...+dp[i]
  // dp[i] = i番目まで行く通りの数 答えは岸まで行くので dp[N+1]
  // 最後から見た時に x[N*1]-L <=x[k] <= x[N*1]-R dp[N+1] = sum dp[k]
  // 範囲: R ~ x[k] ~ L -- x[N+1] みたいな位置関係になる
  // 範囲のidx を[a, b]とする
  // しゃくとり法 or 二分探索
  dp[0] = 1;
  dpsum[0] = 1;
  int a = -1, b = -1;
  for (int i = 1; i <= N + 1; i++) {
    int a = lower_bound(X, X + N + 2, X[i] - R) - X;      // ちょうど
    int b = lower_bound(X, X + N + 2, X[i] - L + 1) - X;  // こえる
    b--;  // ちょうど or X[i]-Lかこえるから 絶対超えるようにして-1
    // while (X[a + 1] <= X[i] - R) a++;  // 絶対入る
    // while (X[b + 1] <= X[i] - L) b++;  // 絶対出る
    // b--;
    // <多めに入る/出る =ちょうど次に入る/出る
    if (b >= 0) dp[i] = (dp[i] + dpsum[b]) % mod;
    if (a - 1 >= 0) dp[i] = (dp[i] - dpsum[a - 1]) % mod;  // 出口 - (入口-1)
    dp[i] = (dp[i] + mod) % mod; // コーナケース
    dpsum[i] = (dp[i] + dpsum[i - 1]) % mod;
  }
  cout << dp[N + 1] << endl;
}