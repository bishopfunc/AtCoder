#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N; cin >> N;
  vector<int> t(N);
  rep(i, 0, N) cin >> t[i];
  int tmp, res = 100000;
  rep(bit, 0, (1 << N)) {
    int t1 = 0, t2 = 0;
    rep(i, 0, N) {
      if(bit & (1 << i)) t1 += t[i];
      else t2 += t[i];
    }
    tmp = max(t1, t2);
    res = min(res, tmp);
    // cout << res << endl;
  }
  cout << res << endl;
}