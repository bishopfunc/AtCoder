#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef modint998244353 mint;
// https://betrue12.hateblo.jp/entry/2020/09/22/194541
// https://betrue12.hateblo.jp/entry/2020/09/23/005940
struct S {
  mint value;  // 実際の値
  ll size;     // 区間の幅
  S(mint v = 0, ll s = 0) : value(v), size(s){};
};
struct F {
  mint b;
  mint c;
  F(mint b = 0, mint c = 0) : b(b), c(c){};
};

S op(S x, S y) { return S(x.value + y.value, x.size + y.size); }
S e() { return S(0, 0); }
S mapping(F f, S x) { return S(x.value * f.b + f.c * x.size, x.size); }
// 1*2+3 2*2+3 3*2+3 // 区間分+3*size
F composition(F g, F f) { return F(f.b * g.b, f.c * g.b + g.c); }
// g.b((f.b)x + f.c) + g.c = (g.b f.b)x + g.b f.c + g.c
// fの+Cがgで+C*Bされる
F id() { return F(1, 0); }

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<S> A(N);
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;  // 0-index
    A[i] = S(a, 1);
  };
  lazy_segtree<S, op, e, F, mapping, composition, id> sg(A);
  for (int i = 0; i < Q; i++) {
    int q, l, r, b, c;
    cin >> q;
    if (q == 0) {
      cin >> l >> r >> b >> c;
      sg.apply(l, r, F(b, c));
    } else if (q == 1) {
      cin >> l >> r;
      cout << sg.prod(l, r).value.val() << endl;
      // valでmintの値を取得可能
    }
  }
}