#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (int)1e9
// 9999の制約を条件に全探索

int main() {
  ll N, A, B, C;
  cin >> N >> A >> B >> C;
  ll L = 9999, ans = INF;
  for (ll i = 0; i <= L; i++) {
    for (ll j = 0; i + j <= L; j++) {
      ll left = N - (A * i + B * j);
      ll k = left / C;
      ll sum = i * A + j * B + k * C;
      if (sum == N && left % C == 0 && left >= 0) ans = min(i + j + k, ans);
      // ぴったり0じゃないケースを防ぐ
      // 残り金額がマイナスになるケースを防ぐ
      // cout << sum << endl;
      // if (sum > N) break;
    }
  }
  cout << ans << endl;
}