#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

using F = bool;
// 区間内の0,1,転倒数の数
struct S {
  ll zero;
  ll one;
  ll tentou;
  S(ll zero = 0, ll one = 0, ll tentou = 0)
      : zero(zero), one(one), tentou(tentou) {}
};

S op(S x, S y) {
  return S(x.zero + y.zero, x.one + y.one,
           x.tentou + y.tentou + x.one * y.zero);
}
// 111|00 の時に2*3の組み合わせができる
S e() { return S(0, 0, 0); }
// fは反転フラグ
// fがtrueなら置き換える
S mapping(F f, S x) {
  if (f) return S(x.one, x.zero, x.zero * x.one - x.tentou);
  return x;
  // 1-Xなので入れ替え, 01とペア数-転倒数
}

// 2回反転は同じ
F composition(F g, F f) {
  if (g) f = !f;
  return f;
}
// 何もしない場合はfalse
F id() { return false; }

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<S> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 0)
      A[i] = S(1, 0, 0);
    else if (a == 1)
      A[i] = S(0, 1, 0);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> sg(A);
  for (int i = 0; i < Q; i++) {
    int T, L, R;
    cin >> T >> L >> R;  // 1-index
    if (T == 1)
      sg.apply(L - 1, R, true);  // 置き換え
    else if (T == 2)
      cout << sg.prod(L - 1, R).tentou << endl;  // 転倒数を求める
  }
}