#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  rep(i, 0, H) cin >> a[i];

  rep(i, 0, W + 2) cout << "#";
  cout << endl;

  rep(i, 0, H) {
    cout << "#" << a[i] << "#" << endl;
  }

  rep(i, 0, W + 2) cout << "#";
  cout << endl;

  return 0;
}