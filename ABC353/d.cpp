#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef modint998244353 mint;
#define MAX_N 200001

struct S {
  mint value;
  int size;  // 桁数
};

// 111 , 100
// 11111111 3 6 2 -> 2 5 2
// 11222211
vector<mint> ones(MAX_N), tens(MAX_N);

using F = mint;

const F ID = 0;

S op(S a, S b) { return {a.value * tens[b.size] + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
// 何も影響しない 1は影響あり
S mapping(F f, S x) {
  if (f == ID) return x;
  return {f * ones[x.size], x.size};
}
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }
// 何も影響しない 絶対にあり得ない値

int main() {
  int N;
  cin >> N;
  std::vector<S> v(N, {1, 1});  // 桁数は1, 1じゃないと*fで0になる
  for (int i = 0; i < N; i++) {
    tens[i + 1] = tens[i] * 10;
    ones[i + 1] = ones[i] + tens[i];
  }

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  for (int i = 0; i < N; i++) {
    seg.apply(i + 1, N, (mint)0);
    cout << seg.all_prod().value.val() << endl;
  }
}