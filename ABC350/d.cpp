#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef long long ll;
ll nC2(ll n) { return n * (n - 1) / 2; }

int main() {
  int N, M;
  cin >> N >> M;
  dsu d(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    d.merge(A, B);
  }
  ll ans = 0;
  for (auto &g : d.groups()) {
    ll n = g.size();
    ans += nC2(n);
  }
  cout << ans - M << endl;
}