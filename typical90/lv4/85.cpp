#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 約数の個数が最大 高度合成数
// Kの約数の個数d(K)から3つ選ぶ d^3/6
// 10^12以下の高度合成数 963761198400	約数の数6720
// aとbを探索すればcも判定できる

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll K;
  cin >> K;
  // 約数列挙
  vector<ll> vec;
  for (ll d = 1; d * d <= K; d++) {
    if (K % d == 0) {
      vec.push_back(d);  // 約数なら追加
      if (d != (K / d)) vec.push_back(K / d);
      // もう片方の約数がdじゃないなら追加
    }
  }
  // cout << vec.size() << endl;
  sort(vec.begin(), vec.end());
  // Kの約数を使ってabc=Kを探索
  ll ans = 0;
  ll n = vec.size();
  // j=i 7=1*1*7みたいに重複しても良い
  for (int i = 0; i < n; i++) {
    ll a = vec[i];
    for (int j = i; j < n; j++) {
      ll b = vec[j];
      if (a > K / b) continue;
      if (K % (a * b) != 0) continue;
      ll c = K / (a * b);
      // if ((a * b * c == K) && a <= b && b <= c) ans++;
      if (a <= b && b <= c) ans++; // オーバーフロー
    }
  }
  cout << ans << endl;
}