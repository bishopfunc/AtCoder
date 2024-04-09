#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> a(N), b(M);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  for (int i = 0; i < M; i++) cin >> b.at(i);
  vector<ll> c = convolution<998244353>(a, b);
  for (int i = 0; i < c.size(); i++) {
    if (i) cout << " ";
    cout << c[i];
  }
  cout << endl;
}