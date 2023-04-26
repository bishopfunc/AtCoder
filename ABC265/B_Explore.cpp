#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int main() {
  int N, M;
  long long T;
  cin >> N >> M >> T;
  vector<long> a(N);
  map<int,int> mp;
  bool res_flag = true;
  rep(i, 1, N) cin >> a[i];
  int x, y;
  rep(i, 0, M) {
    cin >> x >> y;
    mp[x] = y;
  }
  // cout << T << endl;
  rep(i, 1, N + 1) {
    T -= a[i];
    if (mp.count(i)) T += mp[i]; 
    // cout << T << endl;
    if (T <= 0) {
      res_flag = false;
      break;
    }
  }
  if (res_flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}