// ref: https://scrapbox.io/esaka-sandbox/AtCoder_Beginner_Contest_104_-_C_-_All_Green
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std; 
#define rep(i, s, n) for (long long i = (s); i < (long long)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
template<class T>void chmin(T &a, T &b) {if (b < a) {a = b;}}
//---------------------------------------------------------------------------------------------------
int main() {
  int d, g;
  long long ans = LONG_MAX;
  cin >> d >> g;
  vector<long long> p(d), c(d);
  rep(i, 0, d) cin >> p[i] >> c[i];
  for (int bit = 0; bit <= (1<<d); bit++){ //d bit
    long long sum = 0, count = 0;
    rep(i, 0, d) {
      // cout << sum << endl;
      // cout << count << endl;
      // cout << (1<<d) << endl;
      if (bit & (1 << i)) { //どのflagが立っているか, 全パターン
        sum += (i + 1) * 100 * p[i] + c[i];
        count += p[i];
      }
    }
    // 同じbitのループ中
    // 10011 = 100, 400, 500を全探索 + α
    if (sum >= g) chmin(ans, count);
    else {
      for (int i = d - 1; i >= 0; i--){ //d=5 => 4,3,2,1... 点数が大きい順に
        if(bit & 1 << i) continue; //すでに全完している 1<<4 10_000
        rep(j, 0, p[i]) {
          if (sum >= g) {
            chmin(ans, count);
            break; //欲しい点数を超えてるか
          } 
          sum += (i + 1) * 100;
          count++;
        }
        break; //二重ループ
      }
    }
    // if (sum >= g) chmin(ans, count);
  }
  cout << ans << endl;
}