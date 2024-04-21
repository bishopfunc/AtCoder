#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  ll A[N + 1], S[2 * N + 2];
  S[0] = 0;
  for (int i = 1; i <= N; i++) { cin >> A[i]; }
  for (int i = 1; i <= N; i++) { S[i] = S[i - 1] + A[i]; }
  for (int i = 1; i <= N; i++) { S[i + N] = S[i + N - 1] + A[i]; }
  // %しないように2倍して繋げてる 累積和的な
  // S[N]まで埋めてから2倍の
  if (S[N] % 10LL != 0LL) {
    cout << "No" << endl;
    return 0;
  }
  // S[N]はケーキの長さ
  // 0~N 探索範囲は両端
  for (int i = 0; i <= N; i++) {
    ll goal = S[i] + S[N] / 10LL;
    // 19 + 20/10 = 21
    ll pos = lower_bound(S, S + 2 * N + 1, goal) - S;
    // cout << goal << " " << S[pos] << endl;
    // 1-indexだからソートは注意
    // 一致してるか確認だけで良い
    if (S[pos] == goal) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}