#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll next_combination(ll sub) {
  ll x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}

// 定数倍が小さいから 100^5 * 1/120で問題ないっぽい
int main() {
  int N, P, Q;
  cin >> N >> P >> Q;
  vector<ll> A(N);
  // どこでオーバーフローするか注意
  for (int i = 0; i < N; i++) cin >> A[i];

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        for (int l = 0; l < k; l++) {
          for (int m = 0; m < l; m++) {
            // modは掛け算分配できる
            ll a = (A[i] * A[j]) % P;
            ll b = (A[k] * A[l]) % P;
            ll c = (a * b) % P;
            ll d = (c * A[m]) % P;
            if (d == Q) cnt++;
          }
        }
      }
    }
  }

  // 1 << 100は無理
  // int cnt = 0;
  // ll bit = (1 << 5) - 1;
  // for (; bit < (1 << N); bit = next_combination(bit)) {
  //   ll res = 1;
  //   vector<int> S;
  //   for (int i = 0; i < N; i++) {
  //     int mask = (1 << i);
  //     if (bit & mask) {
  //       res = (res * A[i]) % P;
  //       S.push_back(i);
  //     }
  //   }
  //   // bit の表す集合の出力
  //   cout << bit << ": {";
  //   for (int i = 0; i < (int)S.size(); ++i) { cout << S[i] << " "; }
  //   cout << "}" << endl;

  //   if (res % P == Q) cnt++;
  // }
  cout << cnt << endl;
}