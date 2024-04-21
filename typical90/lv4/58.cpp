#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)1e5

// 鳩の巣原理 ループ検出
// 数は0-99999の5桁に絶対なる
// ループの何番目 = (K - start) % cycle_len + start
ll push_btn(ll x) {
  ll z = 0, y = x;
  // 12345 -> 12345 % 10 -> 1234 % 10  -> 123 % 10 -> 12 % 10 -> 1 % 10
  // 1の位 % 10でOK
  while (y > 0) {
    z += y % 10;
    y /= 10;
  }
  return (x + z) % mod;
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> res(mod);  // 周期の入力がxの時の出力
  for (int i = 0; i < mod; i++) res[i] = push_btn(i);

  vector<ll> time_stamp(mod, -1);  // i番目にアクセスした時間
  ll pos = N, time = 0;            // 最初は入力N, 時刻0
  while (time_stamp[pos] == -1) {
    time_stamp[pos] = time;  // 現在の時刻 // poseは周期timeの値
    pos = res[pos];          // 次の値に更新
    time++;
  }
  // 二度目にposにアクセスした時 ループを抜ける
  ll start_time = time_stamp[pos];
  ll cycle = time - start_time;
  if (K >= start_time) K = (K - start_time) % cycle + start_time;
  // K = 1000, start_time = 3, cycle = 10
  // 1000 - 3 -> 997 % 10 -> 7 -> 3+7
  ll ans = -1;
  for (int pos = 0; pos < mod; pos++) {
    if (time_stamp[pos] == K) ans = pos;
  }
  // アクセスした時間を見つけたたら、そのindexが値
  cout << ans << endl;
}