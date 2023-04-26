#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, K; cin >> N >> K;
  vector<int> x(N);
  int res = 0;
  rep(i, 0, N) cin >> x[i];
  rep(i, 0, N) {
    int dist = min(K - x[i], x[i]); // A:0~x, B:K~xの距離
    res += 2 * dist;
  }
  cout << res << endl;
}