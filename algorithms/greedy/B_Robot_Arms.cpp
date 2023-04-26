#include <bits/stdc++.h>
using namespace std; 
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++) // rep(i, 0, N) cin >> D[i] 
#define all(v) v.begin(), v.end() // sort(all(v));
//---------------------------------------------------------------------------------------------------
int N, D[101];
int main() {
  cin >> N;
  vector<int> X(N), L(N);
  vector<pair<int, int>> XL;
  rep(i, 0, N) cin >> X.at(i) >> L.at(i);
  rep(i, 0, N) {
    XL.push_back(make_pair(X.at(i) +  L.at(i),  X.at(i) -  L.at(i)));
  }
  sort(all(XL));
  int t = XL.at(0).first;
  int ans = 1;
  rep(i, 1, N) {
    if (t <= XL.at(i).second) {
      ans++;
      t = XL.at(i).first;
    }
  }
  cout << ans << endl;
}