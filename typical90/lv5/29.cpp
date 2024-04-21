#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
using S = ll;
using F = ll;

const S INF = 8e18;
const F ID = -8e18;

S op(S a, S b) { return max(a, b); }
S e() { return 0LL; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
  ll W, N;
  cin >> W >> N;
  lazy_segtree<S, op, e, F, mapping, composition, id> sg(W);
  for (int i = 0; i < N; i++) {
    ll L, R;
    cin >> L >> R;
    L--;
    sg.apply(L, R, sg.prod(L, R) + 1); // 最大値+1で更新
    cout << sg.prod(L, R) << endl;
  }
}