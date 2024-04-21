#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) \
  for (int i = (s); i < (int)(n); i++)  // rep(i, 0, N) cin >> D[i]
#define all(v) v.begin(), v.end()       // sort(all(v));
//---------------------------------------------------------------------------------------------------
const int INF = 1 << 29;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N), b(N);
  rep(i, 0, N) cin >> a[i];
  rep(i, 0, N) cin >> b[i];

  int min_val = INF;
  sort(b.all());
  rep(i, 0, N) {
    auto iter = lower_bound(b.all(), K - a[i]);
    int val = *iter;
    if (val + a[i] < min_val) min_val = val + a[i];
  }
  cout < < min_val << endl;
}