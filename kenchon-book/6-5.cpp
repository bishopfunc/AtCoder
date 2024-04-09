// ちょっとあやしい
#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
typedef long long ll;
int main() {
  int N; cin >> N;
  vector<ll>H(N), S(N);
  rep(i, 0, N) cin >> H[i] >> S[i];
  ll M = 0; //上限
  rep(i, 0, N) M = max(M, H[i] + S[i] * N);
  ll l = 0, r = M;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    bool ok = true; //範囲外、時間切れフラグ
    vector<ll> t(N, 0); //所用時間の配列

    rep(i, 0, N) {
      if (mid < H[i]) ok = false; // Mより小さい
      else t[i] = (mid - H[i]) / S[i];
    }

    sort(all(t)); // 昇順ソート, 前の方が危うい
    rep(i, 0, N) {
      if (t[i] < i) ok = false;
    }


    if(ok) r = mid; //小さい方を探す
    else l = mid; //大きい方を探す
  }
  cout << r << endl;
}