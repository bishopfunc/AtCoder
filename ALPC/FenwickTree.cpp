#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  ll N, Q;
  cin >> N >> Q;
  fenwick_tree<ll> fw(N);
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    fw.add(i, a);
  }
  for (int i = 0; i < Q; i++) {
    ll q, p, x, l, r;
    cin >> q;
    if (q == 0) {
      cin >> p >> x;
      fw.add(p, x);
    } else if (q == 1) {
      cin >> l >> r;
      cout << fw.sum(l, r) << endl;
    }
  }
}