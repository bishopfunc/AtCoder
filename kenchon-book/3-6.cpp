#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];

  bool flag = false;
  rep(bit, 0, (1<<N)) {
    int sum = 0;
    rep(i, 0, N) {
      if (bit & (1<<i)) sum += a[i];
    }
    if (sum == W) flag = true;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

}