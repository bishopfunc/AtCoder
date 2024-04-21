#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9

// 両方向で LIS 最長増加部分列 をとる
// dp[k] 長さkの部分列の最後の文字の最小値 はダメ
// 別にi番目の文字を最後にする部分列の長さを保持する P,Q
// そうじゃないと両方向じゃ使えない

int main() {
  int N;
  cin >> N;
  vector<int> A(N), dp1(N, INF), dp2(N, INF), P(N), Q(N);
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  int cnt1 = 0;
  for (int i = 0; i < N; i++) {
    int k = lower_bound(dp1.begin(), dp1.end(), A[i]) - dp1.begin();
    dp1[k] = A[i];
    P[i] = k + 1;  // 長さ=idx+1
  }
  int cnt2 = 0;
  for (int i = N - 1; i >= 0; i--) {
    int k = lower_bound(dp2.begin(), dp2.end(), A[i]) - dp2.begin();
    dp2[k] = A[i];
    Q[i] = k + 1;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, P[i] + Q[i] - 1);  // 自分自身が重複するから1文字減らす
  }
  cout << ans << endl;
}
