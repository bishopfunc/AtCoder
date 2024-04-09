#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef modint998244353 mint;
#define mod 998244353

struct S {
  ll value;
  int size;
};
using F = ll;

const F ID = 8e18;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
  if (f != ID) x.value = f * x.size;
  return x;
}
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<S> v(N, {1, 1});
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  for (int i = 0; i < Q; i++) {
    int L, R, D;
    cin >> L >> R >> D;
    seg.apply(L - 1, R, D);

    string res;
    for (int i = 0; i < N; i++) {
      res += to_string(seg.get(i).value);
    }
    cout << stoll(res) % mod << endl;
  }
}
